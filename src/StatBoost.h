#ifndef MODULE_STAT_BOOST
#define MODULE_STAT_BOOST

#include "ChatCommand.h"
#include "Config.h"
#include "Spell.h"

#include "StatBoostCommon.h"
#include "StatBoostMgr.h"

using namespace Acore::ChatCommands;

class StatBoosterPlayer : public PlayerScript
{
public:
    StatBoosterPlayer() : PlayerScript("StatBoosterPlayer") { }

    void OnPlayerLogin(Player* player) override;
    void OnPlayerLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/) override;
    void OnPlayerQuestRewardItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnPlayerCreateItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnPlayerGroupRollRewardItem(Player* player, Item* item, uint32 /*count*/, RollVote /*voteType*/, Roll* /*roll*/) override;
    bool OnPlayerCanCastItemUseSpell(Player* /*player*/, Item* /*item*/, SpellCastTargets const& /*targets*/, uint8 /*cast_count*/, uint32 /*glyphIndex*/) override;
};

class StatBoosterWorld : public WorldScript
{
public:
    StatBoosterWorld() : WorldScript("StatBoosterWorld") { }

    void OnAfterConfigLoad(bool reload) override;
};

class StatBoosterCommands : public CommandScript
{
public:
    StatBoosterCommands() : CommandScript("StatBoosterCommands") { }

    ChatCommandTable GetCommands() const override;
    static bool HandleSBAddItemCommand(ChatHandler* handler, uint32 itemId = 0, uint32 count = 0, Optional<uint32> suffixId = std::nullopt);
};

#endif
