#include "Glow.h"
#include <thread>
#define PI 3.141592653

void Glow::Run(const CEntity& Entity)
{
	int on = 1;
	int off = 0;
	DWORD color = Glow::rainbow();
	if (!MiscCFG::EnemySensor)
	{
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowFunction, off);
	}
	else {
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowFunction, on);
		ProcessMgr.WriteMemory(Entity.Pawn.Address + Offset::Entity.GlowColorOverride, color);
	}
	return;
}

ImColor Glow::rainbow() {
	static float time = 0.0f;
	time += 0.001f;

	float r = (std::sin(time * 2.0f * PI) + 1.0f) * 0.5f;
	float g = (std::sin(time * 2.0f * PI + 2.0f * PI / 3.0f) + 1.0f) * 0.5f;
	float b = (std::sin(time * 2.0f * PI + 4.0f * PI / 3.0f) + 1.0f) * 0.5f;

	return ImColor(r, g, b, 200.f);
}
