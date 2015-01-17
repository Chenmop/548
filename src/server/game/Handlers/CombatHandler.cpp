/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Common.h"
#include "Log.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "ObjectDefines.h"
#include "Vehicle.h"
#include "VehicleDefines.h"
#include "Player.h"
#include "Opcodes.h"

void WorldSession::HandleAttackSwingOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    guid[7] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[0]);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recvd CMSG_ATTACKSWING Message guidlow:%u guidhigh:%u", GUID_LOPART(guid), GUID_HIPART(guid));

    Unit* pEnemy = ObjectAccessor::GetUnit(*_player, guid);

    if (!pEnemy)
    {
        // stop attack state at client
        SendAttackStop(NULL);
        return;
    }

    if (!_player->IsValidAttackTarget(pEnemy))
    {
        // stop attack state at client
        SendAttackStop(pEnemy);
        return;
    }

    //! Client explicitly checks the following before sending CMSG_ATTACKSWING packet,
    //! so we'll place the same check here. Note that it might be possible to reuse this snippet
    //! in other places as well.
    if (Vehicle* vehicle = _player->GetVehicle())
    {
        VehicleSeatEntry const* seat = vehicle->GetSeatForPassenger(_player);
        ASSERT(seat);
        if (!(seat->m_flags & VEHICLE_SEAT_FLAG_CAN_ATTACK))
        {
            SendAttackStop(pEnemy);
            return;
        }
    }

    _player->Attack(pEnemy, true);
}

void WorldSession::HandleAttackStopOpcode(WorldPacket & /*recvData*/)
{
    GetPlayer()->AttackStop();
}

void WorldSession::HandleSetSheathedOpcode(WorldPacket& recvData)
{
    uint32 sheathed;
    bool unk;

    recvData >> sheathed;
    unk = recvData.ReadBit();

    //sLog->outDebug(LOG_FILTER_PACKETIO, "WORLD: Recvd CMSG_SETSHEATHED Message guidlow:%u value1:%u", GetPlayer()->GetGUIDLow(), sheathed);

    if (sheathed >= MAX_SHEATH_STATE)
    {
        sLog->outError(LOG_FILTER_NETWORKIO, "Unknown sheath state %u ??", sheathed);
        return;
    }

    GetPlayer()->SetSheath(SheathState(sheathed));
}

void WorldSession::SendAttackStop(Unit const* enemy)
{
    WorldPacket data(SMSG_ATTACKSTOP, (8+8+4));             // we guess size
    ObjectGuid l_PlayerGuid = GetPlayer()->GetGUID();
    ObjectGuid l_EnemyGuid  = enemy ? enemy->GetGUID() : 0;

    data.WriteBit(l_EnemyGuid[0]);
    data.WriteBit(l_PlayerGuid[4]);
    data.WriteBit(l_EnemyGuid[1]);
    data.WriteBit(l_PlayerGuid[7]);
    data.WriteBit(l_EnemyGuid[6]);
    data.WriteBit(l_EnemyGuid[3]);
    data.WriteBit(0);                                      // unk, can be 1 also
    data.WriteBit(l_EnemyGuid[5]);
    data.WriteBit(l_PlayerGuid[1]);
    data.WriteBit(l_PlayerGuid[0]);
    data.WriteBit(l_EnemyGuid[7]);
    data.WriteBit(l_PlayerGuid[6]);
    data.WriteBit(l_EnemyGuid[4]);
    data.WriteBit(l_EnemyGuid[2]);
    data.WriteBit(l_PlayerGuid[3]);
    data.WriteBit(l_PlayerGuid[2]);
    data.WriteBit(l_PlayerGuid[5]);
    data.FlushBits();

    data.WriteByteSeq(l_PlayerGuid[2]);
    data.WriteByteSeq(l_PlayerGuid[7]);
    data.WriteByteSeq(l_EnemyGuid[0]);
    data.WriteByteSeq(l_PlayerGuid[5]);
    data.WriteByteSeq(l_EnemyGuid[5]);
    data.WriteByteSeq(l_PlayerGuid[3]);
    data.WriteByteSeq(l_EnemyGuid[7]);
    data.WriteByteSeq(l_EnemyGuid[1]);
    data.WriteByteSeq(l_EnemyGuid[3]);
    data.WriteByteSeq(l_PlayerGuid[0]);
    data.WriteByteSeq(l_EnemyGuid[4]);
    data.WriteByteSeq(l_EnemyGuid[6]);
    data.WriteByteSeq(l_PlayerGuid[1]);
    data.WriteByteSeq(l_PlayerGuid[6]);
    data.WriteByteSeq(l_EnemyGuid[2]);
    data.WriteByteSeq(l_PlayerGuid[4]);

    SendPacket(&data);
}
