/*
 * Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "deadmines.h"

//Todo: Add Addition spawns and theyr scripts.

enum Spells
{
    // Phase 1
    SPELL_FISTS_OF_FLAME                = 87859,
    SPELL_FISTS_OF_FROST                = 87861,
    // Phase 2
    SPELL_ARCANE_POWER                  = 88009,
    SPELL_FIRE_WALL                     = 91398,
    SPELL_FIRE_BLOSSOM                  = 91286,
    SPELL_FROST_BLOSSOM                 = 91287
};

enum Events
{
    EVENT_FISTS_OF_FLAME    = 1,
    EVENT_FISTS_OF_FROST    = 2,
    EVENT_ARCANE_POWER      = 3,
    EVENT_FIREWALL          = 4,
    EVENT_FIRE_BLOSSOM      = 5,
    EVENT_FROST_BLOSSOM     = 6,
};

enum Phases
{
    PHASE_1       = 1,
    PHASE_2       = 2,
};

const Position Phase2Pos = { 588.050f, -251.191f, 470.536f, 1.498f }; // todo fill in correct x y z o

class boss_glubtok : public CreatureScript
{
public:
    boss_glubtok() : CreatureScript("boss_glubtok") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_glubtokAI (creature);
    }

    struct boss_glubtokAI : public BossAI
    {
        boss_glubtokAI(Creature* creature) : BossAI(creature, BOSS_GLUBTOK_DATA)
        {
        }

        bool Phase2;

        void Reset()
        {
            _Reset();
            Phase2 = false;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_FISTS_OF_FLAME, 10*IN_MILLISECONDS, 0, PHASE_1); //Todo: get correct timers
            events.ScheduleEvent(EVENT_FISTS_OF_FROST, 20*IN_MILLISECONDS, 0, PHASE_1); //Todo: get correct timers
        }

        void UpdateAI(uint32 const Diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(Diff);

            if (HealthBelowPct(50) && !Phase2)
            {
                me->GetMotionMaster()->MovePoint(1, Phase2Pos);
                Phase2 = true;
            }
            
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    // Phase 1
                    case EVENT_FISTS_OF_FLAME:
                        DoCast(SPELL_FISTS_OF_FLAME);
                        events.RepeatEvent(urand(5*IN_MILLISECONDS,10*IN_MILLISECONDS));
                        return;
                    case EVENT_FISTS_OF_FROST:
                        DoCast(SPELL_FISTS_OF_FROST);
                        events.RepeatEvent(urand(15*IN_MILLISECONDS,20*IN_MILLISECONDS));
                        return;
                    // Phase 2                    
                    case EVENT_ARCANE_POWER:
                        events.DelayEvents(5*IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_FIREWALL, 1*IN_MILLISECONDS, 0, PHASE_2); //Todo: get correct timers and verify if heroic only
                        return;
                    case EVENT_FIREWALL:
                        DoCast(SPELL_FIRE_WALL);
                        return;
                    case EVENT_FIRE_BLOSSOM:
                        DoCast(SPELL_FIRE_BLOSSOM);
                        events.RepeatEvent(urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS));
                        return;
                    case EVENT_FROST_BLOSSOM:
                        DoCast(SPELL_FROST_BLOSSOM);
                        events.RepeatEvent(urand(10*IN_MILLISECONDS,15*IN_MILLISECONDS));
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (id == 1)
            {               
                events.SetPhase(PHASE_2);
                events.ScheduleEvent(EVENT_ARCANE_POWER, 4*IN_MILLISECONDS, 0, PHASE_2); //Todo: get correct timers                
                events.ScheduleEvent(EVENT_FIRE_BLOSSOM, 20*IN_MILLISECONDS, 0, PHASE_2); //Todo: get correct timers
                events.ScheduleEvent(EVENT_FROST_BLOSSOM, 30*IN_MILLISECONDS, 0, PHASE_2); //Todo: get correct timers
            }
        }

    };

};

void AddSC_boss_glubtok()
{
    new boss_glubtok();
}
