/*
 * Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/> 
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
#include "deadmines.h"
#include "InstanceScript.h"

class instance_deadmines : public InstanceMapScript
{
    public:
        instance_deadmines() : InstanceMapScript("instance_deadmines", 36){}

        struct instance_deadmines_InstanceMapScript : public InstanceScript
        {
            instance_deadmines_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

            uint32 Encounter[MAX_ENCOUNTER];
            uint64 GlubtokGUID;

            void Initialize()
            {
                SetBossNumber(MAX_ENCOUNTER);
                GlubtokGUID = 0;

                memset(Encounter, 0, sizeof(Encounter));
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    if (Encounter[i] == IN_PROGRESS)
                        return true;
                }

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_GLUBTOK:
                        GlubtokGUID = creature->GetGUID();
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case BOSS_GLUBTOK_DATA:
                        break;
                }
                return true;
            }

            uint64 GetData64(uint32 data)
            {
                switch (data)
                {
                    case BOSS_GLUBTOK_DATA:
                        return GlubtokGUID;
                }

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "D M" << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* strIn)
            {
                if (!strIn)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(strIn);

                char dataHead1, dataHead2;

                std::istringstream loadStream(strIn);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'D' && dataHead2 == 'M')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }
                }

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };        

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_deadmines_InstanceMapScript(map);
        }
};

void AddSC_instance_deadmines()
{
    new instance_deadmines();
}
