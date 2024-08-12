#pragma once
#include "Misc.h"


namespace HUD
{
	inline void CheatList()
	{
		if (!MiscCFG::CheatList)
			return;

		ImGuiWindowFlags windowFlags = ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar;
		ImGui::SetNextWindowBgAlpha(0.3f);
		ImGui::SetNextWindowSize(ImVec2(250, 0));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 100));
		ImGui::Begin(XorStr("Cheats List"), nullptr, windowFlags);
		ImGui::PopStyleColor();

		if (MenuConfig::AimBot && (MenuConfig::AimAlways || GetAsyncKeyState(AimControl::HotKey)))
			ImGui::Text(XorStr("Aimbot [Toggle]"));
		Misc::CheatText(XorStr("Anti Record"), MenuConfig::BypassOBS);
		Misc::CheatText(XorStr("Bhop"), MiscCFG::BunnyHop);
		Misc::CheatText(XorStr("Bomb Timer"), MiscCFG::bmbTimer);
		Misc::CheatText(XorStr("Crosshair"), CrosshairsCFG::ShowCrossHair);
		Misc::CheatText(XorStr("Enemy Sensor"), MiscCFG::EnemySensor);
		Misc::CheatText(XorStr("ESP"), ESPConfig::ESPenabled);
		Misc::CheatText(XorStr("External Radar"), RadarCFG::ShowRadar);
		Misc::CheatText(XorStr("Fake Duck"), MiscCFG::Jitter);
		Misc::CheatText(XorStr("Fast Stop"), MiscCFG::FastStop);
		if (MiscCFG::FlashImmunity != 0)
			ImGui::Text(XorStr("Flash Immunity"));
		Misc::CheatText(XorStr("Force Scope"), MiscCFG::ForceScope);
		if (MiscCFG::Fov != 90)
			ImGui::Text(XorStr("Fov Changer"));
		Misc::CheatText(XorStr("Headshot Line"), MenuConfig::ShowHeadShootLine);
		Misc::CheatText(XorStr("HitSound"), MiscCFG::HitSound);
		Misc::CheatText(XorStr("Money Service"), MiscCFG::MoneyService);
		Misc::CheatText(XorStr("No Smoke"), MiscCFG::NoSmoke);
		Misc::CheatText(XorStr("Radar Hack"), MiscCFG::RadarHack);
		Misc::CheatText(XorStr("RCS"), MenuConfig::RCS);
		Misc::CheatText(XorStr("Smoke Color"), MiscCFG::SmokeColored);
		Misc::CheatText(XorStr("Spec List"), MiscCFG::SpecList);
		if (MenuConfig::TriggerBot && (MenuConfig::TriggerAlways || GetAsyncKeyState(MenuConfig::TriggerHotKey)))
			ImGui::Text(XorStr("TriggerBot [Toggle]"));

		ImGui::End();
	}

}