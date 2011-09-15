/*
 * Copyright (C) 2011 SingularityCore <http://www.singularitycore.org/>
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "DBCStructure.h"
#include "DBCStores.h"

int32 SpellEntry::CalculateSimpleValue(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->CalculateSimpleValue();
    return 0;
}

uint32 SpellEntry::GetEffectItemType(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectItemType();
    return 0;
}

uint32 SpellEntry::GetEffectTriggerSpell(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectTriggerSpell();
    return 0;
}

uint32 SpellEntry::GetEffectAmplitude(uint32 eff) const
{
   if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
       return effectEntry->GetEffectAmplitude();
   return 0;
}

int32 SpellEntry::GetEffectMiscValue(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectMiscValue();
   return 0;
}

int32 SpellEntry::GetEffectMiscValueB(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectMiscValueB();
   return 0;
}

uint32 SpellEntry::GetEffectChainTarget(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectChainTarget();
    return NULL;
}

uint32 SpellEntry::GetEffectDieSides(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectDieSides();
    return NULL;
}

uint32 SpellEntry::GetEffectPointsPerComboPoint(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectPointsPerComboPoint();
    return NULL;
}

uint32 SpellEntry::GetEffectRealPointsPerLevel(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectRealPointsPerLevel();
    return NULL;
}

uint32 SpellEntry::GetEffectRadiusIndex(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectRadiusIndex();
    return NULL;
}

uint32 SpellEntry::GetDmgMultiplier(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetDmgMultiplier();
    return NULL;
}

uint32 SpellEntry::GetEffectMultipleValue(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return effectEntry->GetEffectMultipleValue();
    return NULL;
}

uint32 const* SpellEntry::GetEffectSpellClassMask(uint32 eff) const
{
    if (SpellEffectEntry const* effectEntry = GetSpellEffectEntry(Id, eff))
        return &effectEntry->EffectSpellClassMask[0];
    return NULL;
}

SpellAuraOptionsEntry const* SpellEntry::GetSpellAuraOptions() const
{
    return SpellAuraOptionsId ? sSpellAuraOptionsStore.LookupEntry(SpellAuraOptionsId) : NULL;
}

SpellAuraRestrictionsEntry const* SpellEntry::GetSpellAuraRestrictions() const
{
    return SpellAuraRestrictionsId ? sSpellAuraRestrictionsStore.LookupEntry(SpellAuraRestrictionsId) : NULL;
}

SpellCastingRequirementsEntry const* SpellEntry::GetSpellCastingRequirements() const
{
    return SpellCastingRequirementsId ? sSpellCastingRequirementsStore.LookupEntry(SpellCastingRequirementsId) : NULL;
}

SpellCategoriesEntry const* SpellEntry::GetSpellCategories() const
{
    return SpellCategoriesId ? sSpellCategoriesStore.LookupEntry(SpellCategoriesId) : NULL;
}

SpellClassOptionsEntry const* SpellEntry::GetSpellClassOptions() const
{
    return SpellClassOptionsId ? sSpellClassOptionsStore.LookupEntry(SpellClassOptionsId) : NULL;
}

SpellCooldownsEntry const* SpellEntry::GetSpellCooldowns() const
{
    return SpellCooldownsId ? sSpellCooldownsStore.LookupEntry(SpellCooldownsId) : NULL;
}

SpellEffectEntry const* SpellEntry::GetSpellEffect(uint32 eff) const
{
    return GetSpellEffectEntry(Id, eff);
}

SpellEquippedItemsEntry const* SpellEntry::GetSpellEquippedItems() const
{
    return SpellEquippedItemsId ? sSpellEquippedItemsStore.LookupEntry(SpellEquippedItemsId) : NULL;
}

SpellInterruptsEntry const* SpellEntry::GetSpellInterrupts() const
{
    return SpellInterruptsId ? sSpellInterruptsStore.LookupEntry(SpellInterruptsId) : NULL;
}

SpellLevelsEntry const* SpellEntry::GetSpellLevels() const
{
    return SpellLevelsId ? sSpellLevelsStore.LookupEntry(SpellLevelsId) : NULL;
}

SpellPowerEntry const* SpellEntry::GetSpellPower() const
{
    return SpellPowerId ? sSpellPowerStore.LookupEntry(SpellPowerId) : NULL;
}

SpellReagentsEntry const* SpellEntry::GetSpellReagents(uint8 eff) const
{
    return GetSpellReagentEntry(Id, eff);
}

SpellScalingEntry const* SpellEntry::GetSpellScaling() const
{
    return SpellScalingId ? sSpellScalingStore.LookupEntry(SpellScalingId) : NULL;
}

SpellShapeshiftEntry const* SpellEntry::GetSpellShapeshift() const
{
    return SpellShapeshiftId ? sSpellShapeshiftStore.LookupEntry(SpellShapeshiftId) : NULL;
}

SpellTargetRestrictionsEntry const* SpellEntry::GetSpellTargetRestrictions() const
{
    return SpellTargetRestrictionsId ? sSpellTargetRestrictionsStore.LookupEntry(SpellTargetRestrictionsId) : NULL;
}

SpellTotemsEntry const* SpellEntry::GetSpellTotems() const
{
    return SpellTotemsId ? sSpellTotemsStore.LookupEntry(SpellTotemsId) : NULL;
}

//SpellCooldownsEntry
uint32 SpellEntry::GetRecoveryTime() const
{
    SpellCooldownsEntry const* cd = GetSpellCooldowns();
    return cd ? cd->RecoveryTime : 0;
}

uint32 SpellEntry::GetStartRecoveryTime() const
{
    SpellCooldownsEntry const* cd = GetSpellCooldowns();
    return cd ? cd->StartRecoveryTime : 0;
}

uint32 SpellEntry::GetCategoryRecoveryTime() const
{
    SpellCooldownsEntry const* cd = GetSpellCooldowns();
    return cd ? cd->CategoryRecoveryTime : 0;
}
//SpellEquippedItemsEntry
int32 SpellEntry::GetEquippedItemInventoryTypeMask() const
{
    SpellEquippedItemsEntry const* items = GetSpellEquippedItems();
    return items ? items->EquippedItemInventoryTypeMask : -1;
}

int32 SpellEntry::GetEquippedItemSubClassMask() const
{
    SpellEquippedItemsEntry const* items = GetSpellEquippedItems();
    return items ? items->EquippedItemSubClassMask : -1;
}

int32 SpellEntry::GetEquippedItemClass() const
{
    SpellEquippedItemsEntry const* items = GetSpellEquippedItems();
    return items ? items->EquippedItemClass : -1;
}
//SpellClassOptionsEntry
uint32 SpellEntry::GetSpellFamilyName() const
{
    SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
    return classOpt ? classOpt->SpellFamilyName : 0;
}

flag96 SpellEntry::GetSpellFamilyFlags() const
{
    SpellClassOptionsEntry const* classOpt = GetSpellClassOptions();
    return classOpt ? classOpt->SpellFamilyFlags : flag96(0);
}
//SpellCategoriesEntry
uint32 SpellEntry::GetPreventionType() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->PreventionType : 0;
}

uint32 SpellEntry::GetCategory() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->Category : 0;
}

uint32 SpellEntry::GetMechanic() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->Mechanic : 0;
}

uint32 SpellEntry::GetStartRecoveryCategory() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->StartRecoveryCategory : 0;
}

uint32 SpellEntry::GetDmgClass() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->DmgClass : 0;
}

uint32 SpellEntry::GetDispel() const
{
    SpellCategoriesEntry const* cat = GetSpellCategories();
    return cat ? cat->Dispel : 0;
}
//SpellPowerEntry
uint32 SpellEntry::GetManaCostPerLevel() const
{
    SpellPowerEntry const* power = GetSpellPower();
    return power ? power->manaCostPerlevel : 0;
}

uint32 SpellEntry::GetManaCost() const
{
    SpellPowerEntry const* power = GetSpellPower();
    return power ? power->manaCost : 0;
}

uint32 SpellEntry::GetManaCostPercentage() const
{
    SpellPowerEntry const* power = GetSpellPower();
    return power ? power->ManaCostPercentage : 0;
}

uint32 SpellEntry::GetManaPerSecond() const
{
    SpellPowerEntry const* power = GetSpellPower();
    return power ? power->manaPerSecond : 0;
}
//SpellAuraOptionsEntry
uint32 SpellEntry::GetProcFlags() const
{
    SpellAuraOptionsEntry const* aura = GetSpellAuraOptions();
    return aura ? aura->procFlags : 0;
}

uint32 SpellEntry::GetStackAmount() const
{
    SpellAuraOptionsEntry const* aura = GetSpellAuraOptions();
    return aura ? aura->StackAmount : 0;
}

uint32 SpellEntry::GetProcCharges() const
{
    SpellAuraOptionsEntry const* aura = GetSpellAuraOptions();
    return aura ? aura->procCharges : 0;
}

uint32 SpellEntry::GetProcChance() const
{
    SpellAuraOptionsEntry const* aura = GetSpellAuraOptions();
    return aura ? aura->procChance : 0;
}
//SpellInterruptsEntry
uint32 SpellEntry::GetInterruptFlags() const
{
    SpellInterruptsEntry const* interrupt = GetSpellInterrupts();
    return interrupt ? interrupt->InterruptFlags : 0;
}

uint32 SpellEntry::GetChannelInterruptFlags() const
{
    SpellInterruptsEntry const* interrupt = GetSpellInterrupts();
    return interrupt ? interrupt->ChannelInterruptFlags : 0;
}

uint32 SpellEntry::GetAuraInterruptFlags() const
{
    SpellInterruptsEntry const* interrupt = GetSpellInterrupts();
    return interrupt ? interrupt->AuraInterruptFlags : 0;
}
//SpellLevelsEntry
uint32 SpellEntry::GetBaseLevel() const
{
    SpellLevelsEntry const* levels = GetSpellLevels();
    return levels ? levels->baseLevel : 0;
}

uint32 SpellEntry::GetMaxLevel() const
{
    SpellLevelsEntry const* levels = GetSpellLevels();
    return levels ? levels->maxLevel : 0;
}

uint32 SpellEntry::GetSpellLevel() const
{
    SpellLevelsEntry const* levels = GetSpellLevels();
    return levels ? levels->spellLevel : 0;
}
//SpellTargetRestrictionsEntry
uint32 SpellEntry::GetTargets() const
{
    SpellTargetRestrictionsEntry const* target = GetSpellTargetRestrictions();
    return target ? target->Targets : 0;
}

uint32 SpellEntry::GetTargetCreatureType() const
{
    SpellTargetRestrictionsEntry const* target = GetSpellTargetRestrictions();
    return target ? target->TargetCreatureType : 0;
}

uint32 SpellEntry::GetMaxAffectedTargets() const
{
    SpellTargetRestrictionsEntry const* target = GetSpellTargetRestrictions();
    return target ? target->MaxAffectedTargets : 0;
}
//SpellAuraRestrictionsEntry
uint32 SpellEntry::GetCasterAuraSpell() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->casterAuraSpell : 0;
}

uint32 SpellEntry::GetCasterAuraState() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->CasterAuraState : 0;
}

uint32 SpellEntry::GetCasterAuraStateNot() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->CasterAuraStateNot : 0;
}

uint32 SpellEntry::GetTargetAuraState() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->TargetAuraState : 0;
}

uint32 SpellEntry::GetTargetAuraSpell() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->targetAuraSpell : 0;
}

uint32 SpellEntry::GetExcludeTargetAuraSpell() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->excludeTargetAuraSpell : 0;
}

uint32 SpellEntry::GetExcludeCasterAuraSpell() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->excludeCasterAuraSpell : 0;
}

uint32 SpellEntry::GetTargetAuraStateNot() const
{
    SpellAuraRestrictionsEntry const* aura = GetSpellAuraRestrictions();
    return aura ? aura->TargetAuraStateNot : 0;
}
//SpellCastingRequirementsEntry
uint32 SpellEntry::GetRequiresSpellFocus() const
{
    SpellCastingRequirementsEntry const* castReq = GetSpellCastingRequirements();
    return castReq ? castReq->RequiresSpellFocus : 0;
}

int32 SpellEntry::GetAreaGroupId() const
{
    SpellCastingRequirementsEntry const* castReq = GetSpellCastingRequirements();
    return castReq ? castReq->AreaGroupId : -1;
}

uint32 SpellEntry::GetFacingCasterFlags() const
{
    SpellCastingRequirementsEntry const* castReq = GetSpellCastingRequirements();
    return castReq ? castReq->FacingCasterFlags : -1;
}
//SpellEffectEntry
uint32 SpellEntry::GetSpellEffectIdByIndex(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->Effect : NULL;
}

uint32 SpellEntry::GetSpellEffectMechanic(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->EffectMechanic : NULL;
}

uint32 SpellEntry::GetSpellEffectBasePoints(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->EffectBasePoints : NULL;
}

uint32 SpellEntry::GetEffectImplicitTargetAByIndex(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->EffectImplicitTargetA : NULL;
}

uint32 SpellEntry::GetEffectImplicitTargetBByIndex(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->EffectImplicitTargetB : NULL;
}

uint32 SpellEntry::GetEffectApplyAuraNameByIndex(uint32 index) const
{
    SpellEffectEntry const* effect = GetSpellEffect(index);
    return effect ? effect->EffectApplyAuraName : 0;
}
//SpellShapeshiftEntry
uint32 SpellEntry::GetStances() const
{
    SpellShapeshiftEntry const* ss = GetSpellShapeshift();
    return ss ? ss->Stances : 0;
}

uint32 SpellEntry::GetStancesNot() const
{
    SpellShapeshiftEntry const* ss = GetSpellShapeshift();
    return ss ? ss->StancesNot : 0;
}
//SpellReagentsEntry
uint32 SpellEntry::GetReagent(uint8 reagents) const
{
    if (SpellReagentsEntry const* reagent = GetSpellReagents(reagents))
        return reagent->Reagent[reagents];
    return 0;
}

uint32 SpellEntry::GetReagentCount(uint8 reagents) const
{
    if (SpellReagentsEntry const* reagent = GetSpellReagents(reagents))
        return reagent->ReagentCount[reagents];
    return 0;
}
