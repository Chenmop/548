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
#include "Language.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "UpdateMask.h"
#include "NPCHandler.h"
#include "Pet.h"
#include "MapManager.h"



enum DBQueryType
{
    //BattlePetAbility           = 0xCBA43BD7,
    //BattlePetAbilityEffect     = 0xDD8B690E,
    //BattlePetAbilityState      = 0x3C556E43,
    //BattlePetAbilityTurn       = 0xECD8ECDC,
    //BattlePetBreedQuality      = 0x1B5A4EA6,
    //BattlePetBreedState        = 0x6AFB3206,
    DB_QUERY_BattlePetEffectProperties  = 0x63B4C4BA,
    //BattlePetNPCTeamMember     = 0xF2059DFA,
    //BattlePetSpecies           = 0x6C93F9B1,
    //BattlePetSpeciesState      = 0x15D87DD0,
    //BattlePetSpeciesXAbility   = 0x44237314,
    //BattlePetState             = 0x8F447330,
    //BattlePetVisual            = 0xC3ADEB43,
    DB_QUERY_NPC_TEXT          = 0x021826BB,
    /*Creature                   = 0xC9D6B6B3,
    GameObjects                = 0x13C403A5,*/
    DB_QUERY_ITEM_SPARSE       = 0x919BE54E,
    DB_QUERY_ITEM              = 0x50238EC2,
    /*ItemCurrencyCost           = 0x6FE05AE9,*/
    //ItemExtendedCost           = 0xBB858355,
    /*ItemUpgrade                = 0x7006463B,
    KeyChain                   = 0x6D8A2694,
    Locale                     = 0x3F85ABB7,
    Location                   = 0x394C3727,
    MapChallengeMode           = 0x383B4C27,
    MarketingPromotionsXLocale = 0xA1D3F1AD,
    Path                       = 0x94F46395,
    PathNode                   = 0x3B9E4CA2,
    PathNodeProperty           = 0xFE21C024,
    PathProperty               = 0x08E54F60,
    QuestPackageItem           = 0xCC2F84F0,
    RulesetItemUpgrade         = 0x6DB7086C,
    RulesetRaidLootUpgrade     = 0xED1FBB4D,
    SceneScript                = 0xD4B163CC,
    SceneScriptPackage         = 0xE8CB5E09,
    SceneScriptPackageMember   = 0xE44DB71C,
    SpellReagents              = 0xAB66C99F*/
};

void WorldSession::SendNameQueryOpcode(ObjectGuid guid, uint32 realmID)
{
	ObjectGuid guid2 = 0;
	ObjectGuid guid3 = guid;

	Player* player = ObjectAccessor::FindPlayer(guid);
	CharacterNameData const* nameData = sWorld->GetCharacterNameData(GUID_LOPART(guid));

	WorldPacket data(SMSG_NAME_QUERY_RESPONSE, 500);
	data.WriteBit(guid[3]);
	data.WriteBit(guid[6]);
	data.WriteBit(guid[7]);
	data.WriteBit(guid[2]);
	data.WriteBit(guid[5]);
	data.WriteBit(guid[4]);
	data.WriteBit(guid[0]);
	data.WriteBit(guid[1]);

	data.WriteByteSeq(guid[5]);
	data.WriteByteSeq(guid[4]);
	data.WriteByteSeq(guid[7]);
	data.WriteByteSeq(guid[6]);
	data.WriteByteSeq(guid[1]);
	data.WriteByteSeq(guid[2]);

	data << uint8(!nameData);

	if (nameData)
	{
		data << uint32(realmID); // realmIdSecond
		data << uint32(1); // AccID
		data << uint8(nameData->m_class);
		data << uint8(nameData->m_race);
		data << uint8(nameData->m_level);
		data << uint8(nameData->m_gender);
	}

	data.WriteByteSeq(guid[0]);
	data.WriteByteSeq(guid[3]);

	if (!nameData)
	{
		SendPacket(&data);
		return;
	}

	data.WriteBit(guid2[2]);
	data.WriteBit(guid2[7]);
	data.WriteBit(guid3[7]);
	data.WriteBit(guid3[2]);
	data.WriteBit(guid3[0]);
	data.WriteBit(0); //isDeleted ? Wod ?
	data.WriteBit(guid2[4]);
	data.WriteBit(guid3[5]);
	data.WriteBit(guid2[1]);
	data.WriteBit(guid2[3]);
	data.WriteBit(guid2[0]);

	DeclinedName const* names = (player ? player->GetDeclinedNames() : NULL);
	for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
		data.WriteBits(names ? names->name[i].size() : 0, 7);

	data.WriteBit(guid3[6]);
	data.WriteBit(guid3[3]);
	data.WriteBit(guid2[5]);
	data.WriteBit(guid3[1]);
	data.WriteBit(guid3[4]);
	data.WriteBits(nameData->m_name.size(), 6);
	data.WriteBit(guid2[6]);

	data.FlushBits();

	data.WriteByteSeq(guid3[6]);
	data.WriteByteSeq(guid3[0]);
	data.WriteString(nameData->m_name);
	data.WriteByteSeq(guid2[5]);
	data.WriteByteSeq(guid2[2]);
	data.WriteByteSeq(guid3[3]);
	data.WriteByteSeq(guid2[4]);
	data.WriteByteSeq(guid2[3]);
	data.WriteByteSeq(guid3[4]);
	data.WriteByteSeq(guid3[2]);
	data.WriteByteSeq(guid2[7]);

	if (names)
		for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
			data.WriteString(names->name[i]);

	data.WriteByteSeq(guid2[6]);
	data.WriteByteSeq(guid3[7]);
	data.WriteByteSeq(guid3[1]);
	data.WriteByteSeq(guid2[1]);
	data.WriteByteSeq(guid3[5]);
	data.WriteByteSeq(guid2[0]);

	SendPacket(&data);
}

void WorldSession::HandleNameQueryOpcode(WorldPacket& recvData)
{
	ObjectGuid guid;

	uint8 bit14, bit1C;
	uint32 unk, unk1;

	guid[4] = recvData.ReadBit();
	bit14 = recvData.ReadBit();
	guid[6] = recvData.ReadBit();
	guid[0] = recvData.ReadBit();
	guid[7] = recvData.ReadBit();
	guid[1] = recvData.ReadBit();
	bit1C = recvData.ReadBit();
	guid[5] = recvData.ReadBit();
	guid[2] = recvData.ReadBit();
	guid[3] = recvData.ReadBit();

	recvData.ReadByteSeq(guid[7]);
	recvData.ReadByteSeq(guid[5]);
	recvData.ReadByteSeq(guid[1]);
	recvData.ReadByteSeq(guid[2]);
	recvData.ReadByteSeq(guid[6]);
	recvData.ReadByteSeq(guid[3]);
	recvData.ReadByteSeq(guid[0]);
	recvData.ReadByteSeq(guid[4]);

	// virtual and native realm Addresses

	if (bit14)
		recvData >> unk;

	if (bit1C)
		recvData >> unk1;

    // This is disable by default to prevent lots of console spam
    // sLog->outInfo(LOG_FILTER_NETWORKIO, "HandleNameQueryOpcode %u", guid);

    SendNameQueryOpcode(guid, realmID);
}

void WorldSession::HandleQueryTimeOpcode(WorldPacket & /*recvData*/)
{
    SendQueryTimeResponse();
}

void WorldSession::SendQueryTimeResponse()
{
    WorldPacket data(SMSG_QUERY_TIME_RESPONSE, 4+4);    
    data << uint32(time(NULL));
    data << uint32(sWorld->GetNextDailyQuestsResetTime() - time(NULL));
    SendPacket(&data);
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleCreatureQueryOpcode(WorldPacket& recvData)
{
    uint32 entry;
    recvData >> entry;

	WorldPacket data(SMSG_CREATURE_QUERY_RESPONSE, 500);
	data << uint32(entry);                              // creature entry
    
    CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(entry);
    
	data.WriteBit(ci != 0);                                    // Has data

	if (ci)
	{
		std::string Name, SubName;
		Name = ci->Name;
		SubName = ci->SubName;

		int loc_idx = GetSessionDbLocaleIndex();
		if (loc_idx >= 0)
		{
			if (CreatureLocale const* cl = sObjectMgr->GetCreatureLocale(entry))
			{
				ObjectMgr::GetLocaleString(cl->Name, loc_idx, Name);
				ObjectMgr::GetLocaleString(cl->SubName, loc_idx, SubName);
			}
		}

		sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CREATURE_QUERY '%s' - Entry: %u.", ci->Name.c_str(), entry);

		data.WriteBits(SubName.length() ? SubName.length() + 1 : 0, 11);
		data.WriteBits(MAX_CREATURE_QUEST_ITEMS, 22);        // Quest items
		data.WriteBits(0, 11);

		for (int i = 0; i < 8; i++)
		{
			if (i == 0)
				data.WriteBits(Name.length() + 1, 11);
			else
				data.WriteBits(0, 11);                       // Name2, ..., name8
		}

		data.WriteBit(ci->RacialLeader);
		data.WriteBits(ci->IconName.length() + 1, 6);
		data.FlushBits();

		data << uint32(ci->KillCredit[0]);                  // New in 3.1, kill credit
		data << uint32(ci->Modelid4);                       // Modelid4
		data << uint32(ci->Modelid2);                       // Modelid2
		data << uint32(ci->expansion);                      // Expansion Required
		data << uint32(ci->type);                           // CreatureType.dbc
		data << float(ci->ModHealth);                       // Hp modifier
		data << uint32(ci->type_flags);                     // Flags
		data << uint32(ci->type_flags2);                    // Flags2
		data << uint32(ci->rank);                           // Creature Rank (elite, boss, etc)
		data << uint32(ci->movementId);                     // CreatureMovementInfo.dbc
		data << Name;

		if (SubName != "")
			data << SubName;                                // Subname

		data << uint32(ci->Modelid1);                       // Modelid1
		data << uint32(ci->Modelid3);                       // Modelid3

		if (ci->IconName != "")
			data << ci->IconName;                           // "Directions" for guard, string for Icons 2.3.0

		for (uint32 i = 0; i < MAX_CREATURE_QUEST_ITEMS; ++i)
			data << uint32(ci->questItems[i]);              // ItemId[6], quest drop

		data << uint32(ci->KillCredit[1]);                  // New in 3.1, kill credit
		data << float(ci->ModMana);                         // Mana modifier
		data << uint32(ci->family);                         // CreatureFamily.dbc
	}

	SendPacket(&data);

        sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_CREATURE_QUERY_RESPONSE");
}

/// Only _static_ data is sent in this packet !!!
void WorldSession::HandleGameObjectQueryOpcode(WorldPacket& recvData)
{
	uint32 entry;
	ObjectGuid guid;

	recvData >> entry;

	guid[5] = recvData.ReadBit();
	guid[3] = recvData.ReadBit();
	guid[6] = recvData.ReadBit();
	guid[2] = recvData.ReadBit();
	guid[7] = recvData.ReadBit();
	guid[1] = recvData.ReadBit();
	guid[0] = recvData.ReadBit();
	guid[4] = recvData.ReadBit();

	recvData.ReadByteSeq(guid[1]);
	recvData.ReadByteSeq(guid[5]);
	recvData.ReadByteSeq(guid[3]);
	recvData.ReadByteSeq(guid[4]);
	recvData.ReadByteSeq(guid[6]);
	recvData.ReadByteSeq(guid[2]);
	recvData.ReadByteSeq(guid[7]);
	recvData.ReadByteSeq(guid[0]);

	const GameObjectTemplate* info = sObjectMgr->GetGameObjectTemplate(entry);

	WorldPacket data(SMSG_GAMEOBJECT_QUERY_RESPONSE, 150);
	data.WriteBit(info != NULL);
	data << uint32(entry);

	size_t pos = data.wpos();
	data << uint32(0);

	if (info)
	{
		std::string Name;
		std::string IconName;
		std::string CastBarCaption;

		Name = info->name;
		IconName = info->IconName;
		CastBarCaption = info->castBarCaption;

		int loc_idx = GetSessionDbLocaleIndex();
		if (loc_idx >= 0)
		{
			if (GameObjectLocale const* gl = sObjectMgr->GetGameObjectLocale(entry))
			{
				ObjectMgr::GetLocaleString(gl->Name, loc_idx, Name);
				ObjectMgr::GetLocaleString(gl->CastBarCaption, loc_idx, CastBarCaption);
			}
		}

		sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_GAMEOBJECT_QUERY '%s' - Entry: %u. ", info->name.c_str(), entry);

		data << uint32(info->type);
		data << uint32(info->displayId);
		data << Name;
		data << uint8(0) << uint8(0) << uint8(0);           // name2, name3, name4
		data << IconName;                                   // 2.0.3, string. Icon name to use instead of default icon for go's (ex: "Attack" makes sword)
		data << CastBarCaption;                             // 2.0.3, string. Text will appear in Cast Bar when using GO (ex: "Collecting")
		data << info->unk1;                                 // 2.0.3, string

		data.append(info->raw.data, MAX_GAMEOBJECT_DATA);
		data << float(info->size);                          // go size

		data << uint8(MAX_GAMEOBJECT_QUEST_ITEMS);

		for (uint32 i = 0; i < MAX_GAMEOBJECT_QUEST_ITEMS; ++i)
			data << uint32(info->questItems[i]);            // itemId[6], quest drop

		data << int32(info->unkInt32);                      // 4.x, unknown

		data.put(pos, uint32(data.wpos() - (pos + 4)));
		sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
	}
	else
	{
		sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_GAMEOBJECT_QUERY - Missing gameobject info for (GUID: %u, ENTRY: %u)",
			GUID_LOPART((uint64)guid), entry);
		sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_GAMEOBJECT_QUERY_RESPONSE");
	}

	SendPacket(&data);
}

void WorldSession::HandleCorpseQueryOpcode(WorldPacket& /*recvData*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Received MSG_CORPSE_QUERY");

    Corpse* corpse = GetPlayer()->GetCorpse();

    if (!corpse)
    {
        WorldPacket data(SMSG_CORPSE_QUERY);

        data << uint8(0);     

        SendPacket(&data);
        return;
    }

    uint32 mapid = corpse->GetMapId();
    float x = corpse->GetPositionX();
    float y = corpse->GetPositionY();
    float z = corpse->GetPositionZ();
    uint32 corpsemapid = mapid;

    // if corpse at different map
    if (mapid != _player->GetMapId())
    {
        // search entrance map for proper show entrance
        if (MapEntry const* corpseMapEntry = sMapStore.LookupEntry(mapid))
        {
            if (corpseMapEntry->IsDungeon() && corpseMapEntry->entrance_map >= 0)
            {
                // if corpse map have entrance
                if (Map const* entranceMap = sMapMgr->CreateBaseMap(corpseMapEntry->entrance_map))
                {
                    mapid = corpseMapEntry->entrance_map;
                    x = corpseMapEntry->entrance_x;
                    y = corpseMapEntry->entrance_y;
                    z = entranceMap->GetHeight(GetPlayer()->GetPhaseMask(), x, y, MAX_HEIGHT);
                }
            }
        }
    }
     {
        WorldPacket data(SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE, 4+4+4+4);
        data << uint32(0);
        data << float(GetPlayer()->GetCorpse()->m_positionX);
        data << uint32(0);
        data << float(GetPlayer()->GetCorpse()->m_positionY);
        data << float(GetPlayer()->GetCorpse()->m_positionZ);
        data.WriteBits(0, 8);
        data.WriteBit(1);
        data.FlushBits();
        SendPacket(&data);

    }

    WorldPacket data(SMSG_CORPSE_QUERY);
	data << uint8(1);                                       // corpse found
    data << int32(mapid);
    data << float(x);
    data << float(y);
    data << float(z);
    data << int32(corpsemapid);
    data << uint32(0);                                      // unknown
    SendPacket(&data);    
}

void WorldSession::HandleNpcTextQueryOpcode(WorldPacket& recvData)
{
    uint32		l_TextID;
    ObjectGuid	l_NpcGuid;

    recvData >> l_TextID;

    l_NpcGuid[7] = recvData.ReadBit();
    l_NpcGuid[3] = recvData.ReadBit();
    l_NpcGuid[1] = recvData.ReadBit();
    l_NpcGuid[5] = recvData.ReadBit();
    l_NpcGuid[6] = recvData.ReadBit();
    l_NpcGuid[4] = recvData.ReadBit();
    l_NpcGuid[0] = recvData.ReadBit();
    l_NpcGuid[2] = recvData.ReadBit();

    recvData.ReadByteSeq(l_NpcGuid[1]);
    recvData.ReadByteSeq(l_NpcGuid[5]);
    recvData.ReadByteSeq(l_NpcGuid[2]);
    recvData.ReadByteSeq(l_NpcGuid[7]);
    recvData.ReadByteSeq(l_NpcGuid[3]);
    recvData.ReadByteSeq(l_NpcGuid[6]);
    recvData.ReadByteSeq(l_NpcGuid[4]);
    recvData.ReadByteSeq(l_NpcGuid[0]);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_NPC_TEXT_QUERY ID '%u'", l_TextID);
   
    GetPlayer()->SetSelection(l_NpcGuid);

    GossipText const* pGossip = sObjectMgr->GetGossipText(l_TextID);

    WorldPacket l_Data(SMSG_NPC_TEXT_UPDATE, 4 + 4 + (8 * 4) + (8 * 4) + 1);

    l_Data << l_TextID;
    l_Data << uint32(0);	/// Data size

    for (size_t l_I = 0 ; l_I < TOTAL_LOCALES ; l_I++)
        l_Data << uint32(l_TextID);

    for (size_t l_I = 0 ; l_I < TOTAL_LOCALES ; l_I++)
        l_Data << uint32(l_TextID);

    l_Data.WriteBit(1);
    l_Data.FlushBits();

    l_Data.wpos(4);
    l_Data << uint32(l_Data.size() - 9);

    SendPacket(&l_Data);

    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_NPC_TEXT_UPDATE");
}

void SendNpcTextDBQueryResponse(WorldSession * p_Session, WorldPacket & p_Data, uint32 p_LocalTextID)
{    
    uint32 l_LocalTextID = p_LocalTextID;

    GossipText const* p_Gossip = sObjectMgr->GetGossipText(l_LocalTextID);
    std::string l_Text1 = "Greetings $N";
    std::string l_Text2 = "Greetings $N";

    if (p_Gossip && p_Gossip->Options[0].Text_0.size())
        l_Text1 = p_Gossip->Options[0].Text_0;
    if (p_Gossip && p_Gossip->Options[0].Text_1.size())
        l_Text2 = p_Gossip->Options[0].Text_1;

    int l_SessionLocalIndex = p_Session->GetSessionDbLocaleIndex();
    if (l_SessionLocalIndex >= 0)
    {
        if (NpcTextLocale const* l_LocalData = sObjectMgr->GetNpcTextLocale(l_LocalTextID))
        {
            ObjectMgr::GetLocaleString(l_LocalData->Text_0[0], l_SessionLocalIndex, l_Text1);
            ObjectMgr::GetLocaleString(l_LocalData->Text_1[0], l_SessionLocalIndex, l_Text2);
        }
    }

    p_Data << uint32(l_LocalTextID);
    p_Data << uint32(p_Gossip != 0 ? p_Gossip->Options[0].Language : LANG_UNIVERSAL);
    p_Data << uint16(l_Text1.size());
    p_Data << l_Text1;
    p_Data << uint16(l_Text2.size());
    p_Data << l_Text2;

    if (p_Gossip)
    {
        for (int j = 0; j < MAX_GOSSIP_TEXT_EMOTES; ++j)
            p_Data << p_Gossip->Options[0].Emotes[j]._Emote;
        for (int j = 0; j < MAX_GOSSIP_TEXT_EMOTES; ++j)
            p_Data << p_Gossip->Options[0].Emotes[j]._Delay;
    }
    else
    {
        for (int j = 0; j < MAX_GOSSIP_TEXT_EMOTES; ++j)
        {
            p_Data << uint32(0);
            p_Data << uint32(0);
        }
    }

    p_Data << uint32(0);
    p_Data << uint32(0);

    p_Data << uint32(0x01);	/// unk
}

bool SendItemSparseDBQueryResponse(WorldSession * p_Session, WorldPacket & p_Data, uint32 p_ItemEntry)
{
    ItemTemplate const * item = sObjectMgr->GetItemTemplate(p_ItemEntry);

    if(!item) return false;

    p_Data << uint32(item->ItemId);//OK
    p_Data << uint32(item->Quality);//OK
    p_Data << uint32(item->Flags);
    p_Data << uint32(item->Flags2);
    p_Data << float(item->Unk430_1);
    p_Data << float(item->Unk430_2);
    p_Data << uint32(0); //unk
    p_Data << uint32(item->BuyCount);//OK
    p_Data << int32(item->BuyPrice);//OK
    p_Data << uint32(item->SellPrice);//OK
    p_Data << uint32(item->InventoryType);
    p_Data << int32(item->AllowableClass);//OK
    p_Data << int32(item->AllowableRace);//OK
    p_Data << uint32(item->ItemLevel);//OK
    p_Data << uint32(item->RequiredLevel);//OK
    p_Data << uint32(item->RequiredSkill);
    p_Data << uint32(item->RequiredSkillRank);
    p_Data << uint32(item->RequiredSpell);
    p_Data << uint32(item->RequiredHonorRank);
    p_Data << uint32(item->RequiredCityRank);
    p_Data << uint32(item->RequiredReputationFaction);
    p_Data << uint32(item->RequiredReputationRank);
    p_Data << int32(item->MaxCount);//OK
    p_Data << int32(item->Stackable);//OK
    p_Data << uint32(item->ContainerSlots);//OK

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        p_Data << uint32(item->ItemStat[x].ItemStatType);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        p_Data << int32(item->ItemStat[x].ItemStatValue);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        p_Data << int32(item->ItemStat[x].ItemStatUnk1);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_STATS; ++x)
        p_Data << int32(item->ItemStat[x].ItemStatUnk2);

    p_Data << uint32(item->ScalingStatDistribution);
    p_Data << uint32(item->DamageType);
    p_Data << uint32(item->Delay);
    p_Data << float(item->RangedModRange);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << int32(item->Spells[x].SpellId);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << uint32(item->Spells[x].SpellTrigger);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << int32(item->Spells[x].SpellCharges);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << int32(item->Spells[x].SpellCooldown);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << uint32(item->Spells[x].SpellCategory);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
        p_Data << int32(item->Spells[x].SpellCategoryCooldown);

    p_Data << uint32(item->Bonding);//OK

    // item name
    std::string name = item->Name1;//OK
    p_Data << uint16(name.length());
    if (name.length())
        p_Data << name;

    for (uint32 i = 0; i < 3; ++i) // other 3 names
        p_Data << uint16(0);//OK

    std::string desc = item->Description;
    p_Data << uint16(desc.length());
    if (desc.length())
        p_Data << desc;

    p_Data << uint32(item->PageText);
    p_Data << uint32(item->LanguageID);
    p_Data << uint32(item->PageMaterial);
    p_Data << uint32(item->StartQuest);
    p_Data << uint32(item->LockID);
    p_Data << int32(item->Material);
    p_Data << uint32(item->Sheath);
    p_Data << int32(item->RandomProperty);
    p_Data << int32(item->RandomSuffix);
    p_Data << uint32(item->ItemSet);

    p_Data << uint32(item->Area);
    p_Data << uint32(item->Map);
    p_Data << uint32(item->BagFamily);
    p_Data << uint32(item->TotemCategory);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SOCKETS; ++x)
        p_Data << uint32(item->Socket[x].Color);

    for (uint32 x = 0; x < MAX_ITEM_PROTO_SOCKETS; ++x)
        p_Data << uint32(item->Socket[x].Content);

    p_Data << uint32(item->socketBonus);
    p_Data << uint32(item->GemProperties);
    p_Data << float(item->ArmorDamageModifier);
    p_Data << int32(item->Duration);
    p_Data << uint32(item->ItemLimitCategory);
    p_Data << uint32(item->HolidayId);
    p_Data << float(item->StatScalingFactor);    // StatScalingFactor
    p_Data << uint32(item->CurrencySubstitutionId);
    p_Data << uint32(item->CurrencySubstitutionCount);

    return true;
}

bool SendItemDBQueryResponse(WorldSession * p_Session, WorldPacket & p_Data, uint32 p_ItemEntry)
{
    ItemTemplate const * item = sObjectMgr->GetItemTemplate(p_ItemEntry);

    if(!item) return false;

    p_Data << uint32(item->ItemId);
    p_Data << uint32(item->Class);
    p_Data << uint32(item->SubClass);
    p_Data << int32(item->SoundOverrideSubclass);
    p_Data << uint32(item->Material);
    p_Data << uint32(item->DisplayInfoID);
    p_Data << uint32(item->InventoryType);
    p_Data << uint32(item->Sheath);

    return true;
}

void WorldSession::HandleDbQueryOpcode(WorldPacket& p_ReceivedPacket)
{
     uint32 l_QueryType;
     uint32 l_Count;

     p_ReceivedPacket >> l_QueryType;

     l_Count = p_ReceivedPacket.ReadBits(21);

     std::vector<ObjectGuid>    l_Guids;
     std::vector<uint32>		l_requestedEntries;

     for (uint32 l_I = 0 ; l_I < l_Count ; l_I++)
     {
         ObjectGuid l_Guid;

         l_Guid[3] = p_ReceivedPacket.ReadBit();
         l_Guid[4] = p_ReceivedPacket.ReadBit();
         l_Guid[7] = p_ReceivedPacket.ReadBit();
         l_Guid[2] = p_ReceivedPacket.ReadBit();
         l_Guid[5] = p_ReceivedPacket.ReadBit();
         l_Guid[0] = p_ReceivedPacket.ReadBit();
         l_Guid[6] = p_ReceivedPacket.ReadBit();
         l_Guid[0] = p_ReceivedPacket.ReadBit();

         l_Guids.push_back(l_Guid);
     }

     for (uint32 l_I = 0 ; l_I < l_Count ; l_I++)
     {
         uint32	l_LocalTextID;

         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][6]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][1]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][2]);
         p_ReceivedPacket >> l_LocalTextID;
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][4]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][5]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][7]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][0]);
         p_ReceivedPacket.ReadByteSeq(l_Guids[l_I][3]);

         l_requestedEntries.push_back(l_LocalTextID);
     }

     if (!l_Count)
         return;

     for (uint32 l_I = 0 ; l_I < l_Count ; l_I++)
     {
         WorldPacket l_Data(SMSG_DB_REPLY, 100);

         l_Data << uint32(0);				/// Data size

        switch (l_QueryType)
        {
        case DB_QUERY_NPC_TEXT:
        {
            SendNpcTextDBQueryResponse(this, l_Data, l_requestedEntries[l_I]);
            break;
        }
        case DB_QUERY_ITEM_SPARSE:
        {
            if(!SendItemSparseDBQueryResponse(this, l_Data, l_requestedEntries[l_I])) continue; //dont send if no item
            break; //to disable the sent of the opcode
        }
        case DB_QUERY_ITEM:
        {
            if(!SendItemDBQueryResponse(this, l_Data, l_requestedEntries[l_I])) continue; //dont send if no item
            break; //to disable the sent of the opcode
        }
        case DB_QUERY_BattlePetEffectProperties:
        {
            l_Data << uint32(l_requestedEntries[l_I]);
            l_Data << uint32(38);
            l_Data << "Points";
            l_Data << "Accuracy";
            l_Data << uint32(43);
            l_Data << uint32(0);
            l_Data << uint32(0);
            l_Data << uint32(0);
            break; //to disable the sent of the opcode
        }
        default:
        {
            sLog->outDebug(LOG_FILTER_NETWORKIO, "Received non handled db query type 0x%08.8X", l_QueryType);
            continue; //to disable the sent of the opcode
        }
        }

         l_Data << uint32(l_QueryType);
         l_Data << uint32(time(0));
         l_Data << uint32(l_requestedEntries[l_I]);

         l_Data.wpos(0);
         l_Data << uint32(l_Data.size() - 16);   

         SendPacket(&l_Data);
    }
}



/// Only _static_ data is sent in this packet !!!
void WorldSession::HandlePageTextQueryOpcode(WorldPacket& recvData)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Received CMSG_PAGE_TEXT_QUERY");

    uint32 pageID;
    recvData >> pageID;
    recvData.rfinish();

    while (pageID)
    {
        PageText const* pageText = sObjectMgr->GetPageText(pageID);
                                                           
        WorldPacket data(SMSG_PAGE_TEXT_QUERY_RESPONSE, 50);

        if (!pageText)
        {
            data.WriteBit(0);
            data.FlushBits();

            data << pageID;
            pageID = 0;
        }
        else
        {
            std::string Text = pageText->Text;

            int loc_idx = GetSessionDbLocaleIndex();
            if (loc_idx >= 0)
                if (PageTextLocale const* player = sObjectMgr->GetPageTextLocale(pageID))
                    ObjectMgr::GetLocaleString(player->Text, loc_idx, Text);

            data.WriteBit(1);
            data.WriteBits(Text.length(), 12);
            data.FlushBits();

            data.WriteString(Text);
            data << pageID;
            data << uint32(pageText->NextPage);
            data << pageID;
            pageID = pageText->NextPage;
        }
        SendPacket(&data);

        sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Sent SMSG_PAGE_TEXT_QUERY_RESPONSE");
    }
}

void WorldSession::HandleCorpseMapPositionQuery(WorldPacket& recvData)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: Recv CMSG_CORPSE_MAP_POSITION_QUERY");

    if (!GetPlayer()->GetCorpse())
        return;

    uint32 transportGuidLow;
    recvData >> transportGuidLow;

    WorldPacket data(SMSG_CORPSE_MAP_POSITION_QUERY_RESPONSE, 4+4+4+4);
    data << uint32(0);
    data << float(GetPlayer()->GetCorpse()->m_positionX);
    data << uint32(0);
    data << float(GetPlayer()->GetCorpse()->m_positionY);
    data << float(GetPlayer()->GetCorpse()->m_positionZ);
    data.WriteBits(0, 8);
    data.WriteBit(1);
    data.FlushBits();

    SendPacket(&data);
}

void WorldSession::HandleQuestPOIQuery(WorldPacket& recvData)
{
    uint32 count;
    count = recvData.ReadBits(22); // quest count, max=25

    if (count >= MAX_QUEST_LOG_SIZE)
    {
        recvData.rfinish();
        return;
    }

    std::vector<POIQuest> l_QuestIDX;

    for(uint32 i = 0 ; i < count ; i++)
    {
        uint32 questId;
        recvData >> questId;

        bool questOk = false;
        uint16 questSlot = _player->FindQuestSlot(questId);
        if (questSlot != MAX_QUEST_LOG_SIZE)
            questOk =_player->GetQuestSlotQuestId(questSlot) == questId;

        POIQuest questPOI = POIQuest(questId, questOk);
        l_QuestIDX.push_back(questPOI);
    }


    WorldPacket data(SMSG_QUEST_POI_QUERY_RESPONSE, 4+(4+4)*count);
    data << uint32(count);
    data.WriteBits(count, 20); // count

    for (uint32 i = 0; i < count; ++i)
    {
        POIQuest questPOI = l_QuestIDX[i];

        if (questPOI.questOk)
        {
            QuestPOIVector const* POI = sObjectMgr->GetQuestPOIVector(questPOI.questId);

            if (POI)
            {
                data.WriteBits(POI->size(), 18); // POI count
                for (QuestPOIVector::const_iterator itr = POI->begin(); itr != POI->end(); ++itr)
                    data.WriteBits(itr->points.size(), 21);     // POI points count
            }
            else
            {
                data.WriteBits(0, 18); // POI count
            }
        }
        else
        {
            data.WriteBits(0, 18); // POI count
        }
    }

    data.FlushBits();

    for (uint32 i = 0; i < count; ++i)
    {
        POIQuest questPOI = l_QuestIDX[i];

        if (questPOI.questOk)
        {
            QuestPOIVector const* POI = sObjectMgr->GetQuestPOIVector(questPOI.questId);

            if (POI)
            {
                for (QuestPOIVector::const_iterator itr = POI->begin(); itr != POI->end(); ++itr)
                {
                    data << uint32(itr->Unk4);              // unknown
                    data << uint32(itr->Unk2);           // FloorId
                    data << uint32(itr->Unk3);              // unknown
                    data << uint32(itr->points.size());     // points count
                    data << uint32(itr->AreaId);            // areaid

                    for (std::vector<QuestPOIPoint>::const_iterator itr2 = itr->points.begin(); itr2 != itr->points.end(); ++itr2)
                    {
                        data << int32(itr2->y);             // POI point y
                        data << int32(itr2->x);             // POI point x
                    }

                    data << int32(itr->ObjectiveIndex);     // objective index
                    data << uint32(0);                      // unknown
                    data << uint32(itr->MapId);             // mapid

                    data << uint32(0);                      // unknown
                    data << uint32(0);                      // unknown

                    data << uint32(itr->Id);                // POI index
                }

                data << uint32(questPOI.questId);                    // quest ID
                data << uint32(POI->size());                // POI count
            }
            else
            {
                data << uint32(questPOI.questId);                    // quest ID
                data << uint32(0);                          // POI count
            }
        }
        else
        {
            data << uint32(questPOI.questId);                        // quest ID
            data << uint32(0);                              // POI count
        }
    }
    
    SendPacket(&data);
}
