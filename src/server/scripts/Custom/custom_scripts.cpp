#include "ScriptMgr.h"
#include "ScriptedCreature.h"

struct npc_spam_spellcaster : public ScriptedAI
{
    public:
        npc_spam_spellcaster(Creature* creature) : ScriptedAI(creature) { }

        void UpdateAI(uint32 diff) override
        {
            if (!me->HasUnitState(UNIT_STATE_CASTING))
            {
                if (auto target = SelectTarget(SelectTargetMethod::Random, 0, 40.0f, true))
                    DoCast(target, 76369);
            }
        }

        // Called at any Damage to any victim (before damage apply)
        void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
        {
            damage = 0;
        }

        void DamageTaken(Unit* who, uint32& damage, DamageEffectType dmgType, SpellInfo const*) override
        {
            damage = 0;
        }
};

void AddSC_CScripts()
{
    RegisterCreatureAI(npc_spam_spellcaster);
}
