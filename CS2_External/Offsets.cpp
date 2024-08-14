#include "Offsets.h"
#include "MenuConfig.hpp"
#include "Utils/ConfigSaver.hpp"
#include <filesystem>
#include "Utils/XorStr.h"

namespace fs = std::filesystem;

DWORD64 SearchOffsets(std::string Signature, DWORD64 ModuleAddress)
{
	std::vector<DWORD64> TempAddressList;
	DWORD64 Address = 0;
	DWORD Offsets = 0;

	TempAddressList = ProcessMgr.SearchMemory(Signature, ModuleAddress, ModuleAddress + 0x4000000);

	if (TempAddressList.size() <= 0)
		return 0;

	if (!ProcessMgr.ReadMemory<DWORD>(TempAddressList.at(0) + 3, Offsets))
		return 0;

	Address = TempAddressList.at(0) + Offsets + 7;
	return Address;
}

bool Offset::UpdateOffsets()
{

	std::string offsetPath = MenuConfig::path + XorStr("\\Offsets\\offsets.yaml");

	if (!fs::exists(offsetPath)) {
		if (fs::create_directories(MenuConfig::path + XorStr("\\Offsets")))
		{
			std::cout << XorStr("[Info] offsets folder created: ") << MenuConfig::path + XorStr("\\Offsets") << std::endl;
			std::cout << XorStr("       please visit https://aimstar.tkm.icu/updater to get the latest offset file.") << std::endl;
		}
		else
		{
			std::cerr << XorStr("Failed to locate offsets file: ") << offsetPath << std::endl;
			return false;
		}

	}
	YAML::Node offset = YAML::LoadFile(offsetPath);

	Offset::EntityList = MyConfigSaver::ReadOffset(offset["client_dll"]["dwEntityList"], 0);
	Offset::LocalPlayerController = MyConfigSaver::ReadOffset(offset["client_dll"]["dwLocalPlayerController"], 0);
	Offset::Matrix = MyConfigSaver::ReadOffset(offset["client_dll"]["dwViewMatrix"], 0);
	Offset::GlobalVars = MyConfigSaver::ReadOffset(offset["client_dll"]["dwGlobalVars"], 0);
	Offset::ViewAngle = MyConfigSaver::ReadOffset(offset["client_dll"]["dwViewAngles"], 0);
	Offset::LocalPlayerPawn = MyConfigSaver::ReadOffset(offset["client_dll"]["dwLocalPlayerPawn"], 0);
	Offset::PlantedC4 = MyConfigSaver::ReadOffset(offset["client_dll"]["dwPlantedC4"], 0);
	Offset::Sensitivity = MyConfigSaver::ReadOffset(offset["client_dll"]["dwSensitivity"], 0);
	Offset::InputSystem = MyConfigSaver::ReadOffset(offset["inputsystem.dll"]["dwInputSystem"], 0);
	Offset::ForceJump = MyConfigSaver::ReadOffset(offset["client_dll"]["jump"], 0);
	Offset::ForceCrouch = MyConfigSaver::ReadOffset(offset["client_dll"]["duck"], 0);
	Offset::ForceForward = MyConfigSaver::ReadOffset(offset["client_dll"]["forward"], 0);
	Offset::ForceLeft = MyConfigSaver::ReadOffset(offset["client_dll"]["left"], 0);
	Offset::ForceRight = MyConfigSaver::ReadOffset(offset["client_dll"]["right"], 0);

	Offset::Entity.IsAlive = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_bPawnIsAlive"], 0);
	Offset::Entity.m_bControllingBot = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_bControllingBot"], 0); 
	Offset::Entity.m_bEverPlayedOnTeam = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_bEverPlayedOnTeam"], 0);
	Offset::Entity.PlayerPawn = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_hPlayerPawn"], 0);
	Offset::Entity.iszPlayerName = MyConfigSaver::ReadOffset(offset["client_dll"]["CBasePlayerController"]["m_iszPlayerName"], 0);
	Offset::Entity.m_sSanitizedPlayerName = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_sSanitizedPlayerName"], 0);
	Offset::Entity.GravityScale = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_flGravityScal"], 0);
	Offset::Entity.GlowFunction = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseModelEntity"]["m_Glow"], 0) + MyConfigSaver::ReadOffset(offset["client_dll"]["CGlowProperty"]["m_bGlowing"], 0);
	Offset::Entity.GlowColorOverride = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseModelEntity"]["m_Glow"], 0) + MyConfigSaver::ReadOffset(offset["client_dll"]["CGlowProperty"]["m_glowColorOverride"], 0);

	Offset::Pawn.MovementServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_pMovementServices"], 0);
	Offset::Pawn.WeaponServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_pWeaponServices"], 0);
	Offset::Pawn.BulletServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_pBulletServices"], 0);
	Offset::Pawn.CameraServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_pCameraServices"], 0);
	Offset::Pawn.ViewModelServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_pViewModelServices"], 0);

	Offset::Pawn.pClippingWeapon = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_pClippingWeapon"], 0);
	Offset::Pawn.ViewModel = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayer_ViewModelServices"]["m_hViewModel"], 0);
	Offset::Pawn.CrouchState = MyConfigSaver::ReadOffset(offset["client_dll"]["CPlayer_MovementServices_Humanoid"]["m_nCrouchState"], 0);
	Offset::Pawn.isScoped = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_bIsScoped"], 0);
	Offset::Pawn.isDefusing = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_bIsDefusing"], 0);
	Offset::Pawn.TotalHit = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayer_BulletServices"]["m_totalHitsOnServer"], 0);
	Offset::Pawn.Pos = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_vOldOrigin"], 0);
	Offset::Pawn.CurrentArmor = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_ArmorValue"], 0);
	Offset::Pawn.MaxHealth = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_iMaxHealth"], 0);
	Offset::Pawn.CurrentHealth = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_iHealth"], 0);
	Offset::Pawn.GameSceneNode = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_pGameSceneNode"], 0);
	Offset::Pawn.angEyeAngles = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_angEyeAngles"], 0);
	Offset::Pawn.vecLastClipCameraPos = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_vecLastClipCameraPos"], 0);
	Offset::Pawn.iShotsFired = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_iShotsFired"], 0);
	Offset::Pawn.flFlashMaxAlpha = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_flFlashMaxAlpha"], 0);
	Offset::Pawn.flFlashDuration = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_flFlashDuration"], 0);
	Offset::Pawn.aimPunchAngle = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_aimPunchAngle"], 0);
	Offset::Pawn.aimPunchCache = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_aimPunchCache"], 0);
	Offset::Pawn.iIDEntIndex = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawnBase"]["m_iIDEntIndex"], 0);
	Offset::Pawn.iTeamNum = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_iTeamNum"], 0);
	Offset::Pawn.DesiredFov = MyConfigSaver::ReadOffset(offset["client_dll"]["CBasePlayerController"]["m_iDesiredFOV"], 0);
	Offset::Pawn.iFovStart = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerBase_CameraServices"]["m_iFOVStart"], 0);
	Offset::Pawn.fFlags = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_fFlags;"], 0);
	Offset::Pawn.bSpottedByMask = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_entitySpottedState"], 0) + MyConfigSaver::ReadOffset(offset["client_dll"]["EntitySpottedState_t"]["m_bSpottedByMask"], 0);
	Offset::Pawn.AbsVelocity = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_vecAbsVelocity"], 0);
	Offset::Pawn.IsBuying = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_bIsBuyMenuOpen"], 0);
	Offset::Pawn.m_bWaitForNoAttack = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSPlayerPawn"]["m_bWaitForNoAttack"], 0);

	Offset::WeaponBaseData.WeaponDataPTR = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BaseEntity"]["m_nSubclassID"],0) + 0x08;
	Offset::WeaponBaseData.szName = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_szName"], 0);
	Offset::WeaponBaseData.Clip1 = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerWeapon"]["m_iClip1"], 0);
	Offset::WeaponBaseData.MaxClip = MyConfigSaver::ReadOffset(offset["client_dll"]["CBasePlayerWeaponVData"]["m_iMaxClip1"], 0);
	Offset::WeaponBaseData.CycleTime = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_flCycleTime"], 0);
	Offset::WeaponBaseData.Penetration = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_flPenetration"], 0);
	Offset::WeaponBaseData.WeaponType = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_WeaponType"], 0);
	Offset::WeaponBaseData.Inaccuracy = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_flInaccuracyMove"], 0);
	Offset::WeaponBaseData.inReload = MyConfigSaver::ReadOffset(offset["client_dll"]["C_CSWeaponBase"]["m_bInReload"], 0);
	Offset::WeaponBaseData.m_nNumBullets = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSWeaponBaseVData"]["m_nNumBullets"], 0);
	Offset::WeaponBaseData.ActiveWeapon = MyConfigSaver::ReadOffset(offset["client_dll"]["CPlayer_WeaponServices"]["m_hActiveWeapon"], 0);
	Offset::WeaponBaseData.Item = MyConfigSaver::ReadOffset(offset["client_dll"]["C_AttributeContainer"]["m_Item"], 0);
	Offset::WeaponBaseData.ItemDefinitionIndex = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconItemView"]["m_iItemDefinitionIndex"], 0);
	Offset::WeaponBaseData.m_MeshGroupMask = MyConfigSaver::ReadOffset(offset["client_dll"]["CModelState"]["m_MeshGroupMask"], 0);

	Offset::PlayerController.m_hPawn = MyConfigSaver::ReadOffset(offset["client_dll"]["CBasePlayerController"]["m_hPawn"], 0);
	Offset::PlayerController.m_pObserverServices = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_pObserverServices"], 0);
	Offset::PlayerController.m_hObserverTarget = MyConfigSaver::ReadOffset(offset["client_dll"]["CPlayer_ObserverServices"]["m_hObserverTarget"], 0);
	Offset::PlayerController.m_hController = MyConfigSaver::ReadOffset(offset["client_dll"]["C_BasePlayerPawn"]["m_hController"], 0);
	Offset::PlayerController.PawnArmor = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_iPawnArmor"], 0);
	Offset::PlayerController.HasDefuser = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_bPawnHasDefuser"], 0);
	Offset::PlayerController.HasHelmet = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_bPawnHasHelmet"], 0);
	Offset::PlayerController.m_steamID = MyConfigSaver::ReadOffset(offset["client_dll"]["CBasePlayerController"]["m_steamID"], 0);

	Offset::C4.m_bBeingDefused = MyConfigSaver::ReadOffset(offset["client_dll"]["C_PlantedC4"]["m_bBeingDefused"], 0);
	Offset::C4.m_flDefuseCountDown = MyConfigSaver::ReadOffset(offset["client_dll"]["C_PlantedC4"]["m_flDefuseCountDown"], 0);
	Offset::C4.m_nBombSite = MyConfigSaver::ReadOffset(offset["client_dll"]["C_PlantedC4"]["m_nBombSite"], 0);

	Offset::InGameMoneyServices.MoneyServices = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController"]["m_pInGameMoneyServices"], 0);
	Offset::InGameMoneyServices.Account = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController_InGameMoneyServices"]["m_iAccount"], 0);
	Offset::InGameMoneyServices.TotalCashSpent = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController_InGameMoneyServices"]["m_iTotalCashSpent"], 0);
	Offset::InGameMoneyServices.CashSpentThisRound = MyConfigSaver::ReadOffset(offset["client_dll"]["CCSPlayerController_InGameMoneyServices"]["m_iCashSpentThisRound"], 0);

	Offset::SmokeGrenadeProjectile.nSmokeEffectTickBegin = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_nSmokeEffectTickBegin"], 0);
	Offset::SmokeGrenadeProjectile.bDidSmokeEffect = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_bDidSmokeEffect"], 0);
	Offset::SmokeGrenadeProjectile.nRandomSeed = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_nRandomSeed"], 0);
	Offset::SmokeGrenadeProjectile.vSmokeColor = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_vSmokeColor"], 0);
	Offset::SmokeGrenadeProjectile.vSmokeDetonationPos = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_vSmokeDetonationPos"], 0);
	Offset::SmokeGrenadeProjectile.VoxelFrameData = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_VoxelFrameData"], 0);
	Offset::SmokeGrenadeProjectile.bSmokeVolumeDataReceived = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_bSmokeVolumeDataReceived"], 0);
	Offset::SmokeGrenadeProjectile.bSmokeEffectSpawned = MyConfigSaver::ReadOffset(offset["client_dll"]["C_SmokeGrenadeProjectile"]["m_bSmokeEffectSpawned"], 0);

	Offset::EconEntity.AttributeManager = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconEntity"]["m_AttributeManager"], 0);
	Offset::EconEntity.FallbackPaintKit = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconEntity"]["m_nFallbackPaintKit"], 0);
	Offset::EconEntity.FallbackSeed = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconEntity"]["m_nFallbackSeed"], 0);
	Offset::EconEntity.FallbackWear = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconEntity"]["m_flFallbackWear"], 0);
	Offset::EconEntity.FallbackStatTrak = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconEntity"]["m_nFallbackStatTrak"], 0);
	Offset::EconEntity.szCustomName = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconItemView"]["m_szCustomName"], 0);
	Offset::EconEntity.EntityQuality = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconItemView"]["m_iEntityQuality"], 0);
	Offset::EconEntity.ItemIDHigh = MyConfigSaver::ReadOffset(offset["client_dll"]["C_EconItemView"]["m_iItemIDHigh"], 0);

	return true;
}
