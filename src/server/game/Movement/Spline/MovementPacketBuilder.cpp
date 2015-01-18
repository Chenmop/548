/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "MovementPacketBuilder.h"
#include "MoveSpline.h"
#include "WorldPacket.h"
#include "Object.h"
#include "Player.h"

uint32 hasUnkSplineCounter = false;

namespace Movement
{
    inline void operator << (ByteBuffer& b, const Vector3& v)
    {
        b << v.x << v.y << v.z;
    }

    inline void operator >> (ByteBuffer& b, Vector3& v)
    {
        b >> v.x >> v.y >> v.z;
    }

    enum MonsterMoveType
    {
        MonsterMoveNormal       = 0,
        MonsterMoveStop         = 1,
        MonsterMoveFacingSpot   = 2,
        MonsterMoveFacingTarget = 3,
        MonsterMoveFacingAngle  = 4
    };

	MonsterMoveType SplineFlagsToMonsterMoveType(MoveSplineFlag p_Flags)
    {
        switch (p_Flags & MoveSplineFlag::Mask_Final_Facing)
        {
            case MoveSplineFlag::Final_Target:
                return MonsterMoveFacingTarget;
                break;

            case MoveSplineFlag::Final_Angle:
                return MonsterMoveFacingAngle;
                break;

            case MoveSplineFlag::Final_Point:
                return MonsterMoveFacingSpot;
                break;
        }

        return MonsterMoveNormal;
    }

    void PacketBuilder::WriteCommonMonsterMovePart(const MoveSpline& p_MoveSpline, ObjectGuid p_CreatureGuid, ObjectGuid p_TransportGuid, WorldPacket& p_Data)
    {
		ObjectGuid guid = p_CreatureGuid;
		ObjectGuid transport = p_TransportGuid;
		MoveSplineFlag l_SplineFlags = p_MoveSpline.splineflags;
		l_SplineFlags.enter_cycle = p_MoveSpline.isCyclic();

		MonsterMoveType l_MoveType = SplineFlagsToMonsterMoveType(l_SplineFlags);
		G3D::Vector3 const& firstPoint = p_MoveSpline.spline.getPoint(p_MoveSpline.spline.first());

		p_Data << float(firstPoint.z);
		p_Data << float(firstPoint.x);
		p_Data << uint32(p_MoveSpline.GetId());
		p_Data << float(firstPoint.y);
		p_Data << float(0.f); // Most likely transport Y
		p_Data << float(0.f); // Most likely transport Z
		p_Data << float(0.f); // Most likely transport X

		p_Data.WriteBit(1); // Parabolic speed // esi+4Ch
		p_Data.WriteBit(guid[0]);
		p_Data.WriteBits(l_MoveType, 3);

		if (l_MoveType == MonsterMoveFacingTarget)
		{
			ObjectGuid targetGuid = p_MoveSpline.facing.target;
			p_Data.WriteBit(targetGuid[6]);
			p_Data.WriteBit(targetGuid[4]);
			p_Data.WriteBit(targetGuid[3]);
			p_Data.WriteBit(targetGuid[0]);
			p_Data.WriteBit(targetGuid[5]);
			p_Data.WriteBit(targetGuid[7]);
			p_Data.WriteBit(targetGuid[1]);
			p_Data.WriteBit(targetGuid[2]);
		}

		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);

		uint32 uncompressedSplineCount = p_MoveSpline.splineflags & MoveSplineFlag::UncompressedPath ? p_MoveSpline.splineflags.cyclic ? p_MoveSpline.spline.getPointCount() - 2 : p_MoveSpline.spline.getPointCount() - 3 : 1;
		p_Data.WriteBits(uncompressedSplineCount, 20);

		p_Data.WriteBit(!p_MoveSpline.splineflags.raw());
		p_Data.WriteBit(guid[3]);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(!p_MoveSpline.Duration());
		p_Data.WriteBit(guid[7]);
		p_Data.WriteBit(guid[4]);
		p_Data.WriteBit(1);
		p_Data.WriteBit(guid[5]);

		int32 compressedSplineCount = p_MoveSpline.splineflags & MoveSplineFlag::UncompressedPath ? 0 : p_MoveSpline.spline.getPointCount() - 3;
		p_Data.WriteBits(compressedSplineCount, 22); // WP count

		p_Data.WriteBit(guid[6]);
		p_Data.WriteBit(0); // Fake bit

		p_Data.WriteBit(transport[7]);
		p_Data.WriteBit(transport[1]);
		p_Data.WriteBit(transport[3]);
		p_Data.WriteBit(transport[0]);
		p_Data.WriteBit(transport[6]);
		p_Data.WriteBit(transport[4]);
		p_Data.WriteBit(transport[5]);
		p_Data.WriteBit(transport[2]);

		p_Data.WriteBit(0); // Send no block
		p_Data.WriteBit(0);
		p_Data.WriteBit(guid[2]);
		p_Data.WriteBit(guid[1]);

		p_Data.FlushBits();

		//if (compressedSplineCount)
			//WriteLinearPath(p_MoveSpline.spline, p_Data);

		p_Data.WriteByteSeq(guid[1]);
		p_Data.WriteByteSeq(transport[6]);
		p_Data.WriteByteSeq(transport[4]);
		p_Data.WriteByteSeq(transport[1]);
		p_Data.WriteByteSeq(transport[7]);
		p_Data.WriteByteSeq(transport[0]);
		p_Data.WriteByteSeq(transport[3]);
		p_Data.WriteByteSeq(transport[5]);
		p_Data.WriteByteSeq(transport[2]);

		//if (p_MoveSpline.splineflags & MoveSplineFlag::UncompressedPath)
		//{
		//	if (p_MoveSpline.splineflags.cyclic)
		//		WriteUncompressedCyclicPath(p_MoveSpline.spline, p_Data);
		//	else
		//		WriteUncompressedPath(p_MoveSpline.spline, p_Data);
		//}
		//else
		//{
			G3D::Vector3 const& point = p_MoveSpline.spline.getPoint(p_MoveSpline.spline.getPointCount() - 2);
			p_Data << point.y << point.x << point.z;
		//}

		if (l_MoveType == MonsterMoveFacingTarget)
		{
			ObjectGuid targetGuid = p_MoveSpline.facing.target;
			p_Data.WriteByteSeq(targetGuid[5]);
			p_Data.WriteByteSeq(targetGuid[7]);
			p_Data.WriteByteSeq(targetGuid[0]);
			p_Data.WriteByteSeq(targetGuid[4]);
			p_Data.WriteByteSeq(targetGuid[3]);
			p_Data.WriteByteSeq(targetGuid[2]);
			p_Data.WriteByteSeq(targetGuid[6]);
			p_Data.WriteByteSeq(targetGuid[1]);
		}

		p_Data.WriteByteSeq(guid[5]);

		if (l_MoveType == MonsterMoveFacingAngle)
			p_Data << float(p_MoveSpline.facing.angle);

		p_Data.WriteByteSeq(guid[3]);

		if (p_MoveSpline.splineflags.raw())
			p_Data << uint32(p_MoveSpline.splineflags.raw());

		p_Data.WriteByteSeq(guid[6]);

		if (l_MoveType == MonsterMoveFacingSpot)
			p_Data << p_MoveSpline.facing.f.x << p_MoveSpline.facing.f.y << p_MoveSpline.facing.f.z;

		p_Data.WriteByteSeq(guid[0]);
		p_Data.WriteByteSeq(guid[7]);
		p_Data.WriteByteSeq(guid[2]);
		p_Data.WriteByteSeq(guid[4]);

		if (p_MoveSpline.Duration())
			p_Data << uint32(p_MoveSpline.Duration());
    }

    void PacketBuilder::WriteStopMovement(Vector3 const& pos, ObjectGuid p_CreatureGuid, ObjectGuid p_TransportGuid, uint32 splineId, ByteBuffer& p_Data)
    {
		p_Data << float(pos.z);
		p_Data << float(pos.x);
		p_Data << uint32(splineId);
		p_Data << float(pos.y);
		p_Data << float(0.f); // Most likely transport Y
		p_Data << float(0.f); // Most likely transport Z
		p_Data << float(0.f); // Most likely transport X

		p_Data.WriteBit(1); // Parabolic speed // esi+4Ch
		p_Data.WriteBit(p_CreatureGuid[0]);
		p_Data.WriteBits(MonsterMoveStop, 3);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBits(0, 20);
		p_Data.WriteBit(1);
		p_Data.WriteBit(p_CreatureGuid[3]);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(1);
		p_Data.WriteBit(p_CreatureGuid[7]);
		p_Data.WriteBit(p_CreatureGuid[4]);
		p_Data.WriteBit(1);
		p_Data.WriteBit(p_CreatureGuid[5]);
		p_Data.WriteBits(0, 22); // WP count
		p_Data.WriteBit(p_CreatureGuid[6]);
		p_Data.WriteBit(0); // Fake bit
		p_Data.WriteBit(p_TransportGuid[7]);
		p_Data.WriteBit(p_TransportGuid[1]);
		p_Data.WriteBit(p_TransportGuid[3]);
		p_Data.WriteBit(p_TransportGuid[0]);
		p_Data.WriteBit(p_TransportGuid[6]);
		p_Data.WriteBit(p_TransportGuid[4]);
		p_Data.WriteBit(p_TransportGuid[5]);
		p_Data.WriteBit(p_TransportGuid[2]);
		p_Data.WriteBit(0); // Send no block
		p_Data.WriteBit(0);
		p_Data.WriteBit(p_CreatureGuid[2]);
		p_Data.WriteBit(p_CreatureGuid[1]);

		p_Data.FlushBits();

		p_Data.WriteByteSeq(p_CreatureGuid[1]);
		p_Data.WriteByteSeq(p_TransportGuid[6]);
		p_Data.WriteByteSeq(p_TransportGuid[4]);
		p_Data.WriteByteSeq(p_TransportGuid[1]);
		p_Data.WriteByteSeq(p_TransportGuid[7]);
		p_Data.WriteByteSeq(p_TransportGuid[0]);
		p_Data.WriteByteSeq(p_TransportGuid[3]);
		p_Data.WriteByteSeq(p_TransportGuid[5]);
		p_Data.WriteByteSeq(p_TransportGuid[2]);
		p_Data.WriteByteSeq(p_CreatureGuid[5]);
		p_Data.WriteByteSeq(p_CreatureGuid[3]);
		p_Data.WriteByteSeq(p_CreatureGuid[6]);
		p_Data.WriteByteSeq(p_CreatureGuid[0]);
		p_Data.WriteByteSeq(p_CreatureGuid[7]);
		p_Data.WriteByteSeq(p_CreatureGuid[2]);
		p_Data.WriteByteSeq(p_CreatureGuid[4]);
    }

    void WriteLinearPath(const Spline<int32>& spline, ByteBuffer& data)
    {
       /* uint32 last_idx = spline.getPointCount() - 3;
        const Vector3 * real_path = &spline.getPoint(1);

        data << last_idx;
        data << real_path[last_idx];   // destination
        if (last_idx > 1)
        {
            Vector3 middle = (real_path[0] + real_path[last_idx]) / 2.f;
            Vector3 offset;
            // first and last points already appended
            for (uint32 i = 1; i < last_idx; ++i)
            {
                offset = middle - real_path[i];
                data.appendPackXYZ(offset.x, offset.y, offset.z);
            }
        }*/
    }

    void WriteCatmullRomPath(const Spline<int32>& spline, ByteBuffer& data)
    {
        //uint32 count = spline.getPointCount() - 3;
       // data << count;
       // data.append<Vector3>(&spline.getPoint(2), count);
    }

    void WriteCatmullRomCyclicPath(const Spline<int32>& spline, ByteBuffer& data)
    {
        //uint32 count = spline.getPointCount() - 3;
        //data << uint32(count + 1);
        //data << spline.getPoint(1); // fake point, client will erase it from the spline after first cycle done
        //data.append<Vector3>(&spline.getPoint(1), count);
    }

   void PacketBuilder::WriteMonsterMove(const MoveSpline& move_spline, ObjectGuid p_CreatureGuid, ObjectGuid p_TransportGuid, WorldPacket& data)
    {
        WriteCommonMonsterMovePart(move_spline, p_CreatureGuid, p_TransportGuid, data);
    }

    void PacketBuilder::WriteCreateBits(MoveSpline const& moveSpline, ByteBuffer& data)
    {
       if (!data.WriteBit(!moveSpline.Finalized()))
            return;

        bool hasUnkSpline = false;

        data.WriteBit(moveSpline.splineflags & (MoveSplineFlag::Parabolic | MoveSplineFlag::Animation));

        data.WriteBits(uint8(moveSpline.spline.mode()), 2);

        data.WriteBits(moveSpline.splineflags.raw(), 25);
        data.WriteBit(hasUnkSpline);

        if (hasUnkSpline)
        {
            data.WriteBits(0, 21);  // count
            data.WriteBits(0, 2);   // unk
        }

        data.WriteBits(moveSpline.getPath().size(), 20);
        data.WriteBit((moveSpline.splineflags & MoveSplineFlag::Parabolic) && moveSpline.effect_start_time < moveSpline.Duration());
    }

    void PacketBuilder::WriteCreateData(MoveSpline const& moveSpline, ByteBuffer& data)
    {
        if (!moveSpline.Finalized())
        {
            MoveSplineFlag const& splineFlags = moveSpline.splineflags;

            switch (moveSpline.splineflags & MoveSplineFlag::Mask_Final_Facing)
            {
                case MoveSplineFlag::Final_Target:
                    data << uint8(MonsterMoveFacingTarget);
                    break;
                case MoveSplineFlag::Final_Angle:
                    data << uint8(MonsterMoveFacingAngle);
                    break;
                case MoveSplineFlag::Final_Point:
                    data << uint8(MonsterMoveFacingSpot);
                    break;
                default:
                    data << uint8(0);
                    break;
            }

            data << float(1.f);                             // splineInfo.duration_mod; added in 3.1

            uint32 nodes = moveSpline.getPath().size();
            for (uint32 i = 0; i < nodes; ++i)
            {
                data << float(moveSpline.getPath()[i].z);
                data << float(moveSpline.getPath()[i].x);
                data << float(moveSpline.getPath()[i].y);
            }

            uint32 hasUnkSplineCounter = 0;
            for (uint32 i = 0; i < hasUnkSplineCounter; ++i)
            {
                data << float(0.0f);
                data << float(0.0f);
            }

            data << float(1.f);                             // splineInfo.duration_mod_next; added in 3.1

            if ((moveSpline.splineflags & MoveSplineFlag::Mask_Final_Facing) == MoveSplineFlag::Final_Point)
                data << moveSpline.facing.f.z << moveSpline.facing.f.y <<moveSpline.facing.f.x;

            if ((moveSpline.splineflags & MoveSplineFlag::Mask_Final_Facing) == MoveSplineFlag::Final_Angle)
                data << moveSpline.facing.angle;

            if ((splineFlags & MoveSplineFlag::Parabolic) && moveSpline.effect_start_time < moveSpline.Duration())
                data << moveSpline.vertical_acceleration;   // added in 3.1

            if (splineFlags & (MoveSplineFlag::Parabolic | MoveSplineFlag::Animation))
                data << moveSpline.effect_start_time;       // added in 3.1

            data << moveSpline.timePassed();
            data << moveSpline.Duration();
        }

        if (!moveSpline.isCyclic())
        {
            Vector3 dest = moveSpline.FinalDestination();
            data << moveSpline.GetId();
            data << float(dest.z);
            data << float(dest.x);
            data << float(dest.y);
        }
        else
        {
            data << moveSpline.GetId();
            data << float(0.0);
            data << float(0.0);
            data << float(0.0);
            data << float(0.0);
        }
    }
}