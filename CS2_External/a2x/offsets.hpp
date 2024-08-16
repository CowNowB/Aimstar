// Generated using https://github.com/a2x/cs2-dumper
// 2024-08-15 00:46:46.997594900 UTC

#pragma once

#include <cstddef>

namespace cs2_dumper {
    namespace offsets {
        // Module: client.dll
        namespace client_dll {
            constexpr std::ptrdiff_t dwCSGOInput = 0x19D4BA8;
            constexpr std::ptrdiff_t dwEntityList = 0x1969668;
            constexpr std::ptrdiff_t dwGameEntitySystem = 0x1A89298;
            constexpr std::ptrdiff_t dwGameEntitySystem_highestEntityIndex = 0x1510;
            constexpr std::ptrdiff_t dwGameRules = 0x19C6E50;
            constexpr std::ptrdiff_t dwGlobalVars = 0x17C8708;
            constexpr std::ptrdiff_t dwGlowManager = 0x19C6560;
            constexpr std::ptrdiff_t dwLocalPlayerController = 0x19B91A8;
            constexpr std::ptrdiff_t dwLocalPlayerPawn = 0x17D47E0;
            constexpr std::ptrdiff_t dwPlantedC4 = 0x19D0018;
            constexpr std::ptrdiff_t dwPrediction = 0x17D4680;
            constexpr std::ptrdiff_t dwSensitivity = 0x19C7B18;
            constexpr std::ptrdiff_t dwSensitivity_sensitivity = 0x40;
            constexpr std::ptrdiff_t dwViewAngles = 0x19DA928;
            constexpr std::ptrdiff_t dwViewMatrix = 0x19CB4D0;
            constexpr std::ptrdiff_t dwViewRender = 0x19CBC60;
            constexpr std::ptrdiff_t dwWeaponC4 = 0x196D560;
        }
        // Module: engine2.dll
        namespace engine2_dll {
            constexpr std::ptrdiff_t dwBuildNumber = 0x52F7F4;
            constexpr std::ptrdiff_t dwNetworkGameClient = 0x52EB80;
            constexpr std::ptrdiff_t dwNetworkGameClient_clientTickCount = 0x178;
            constexpr std::ptrdiff_t dwNetworkGameClient_deltaTick = 0x27C;
            constexpr std::ptrdiff_t dwNetworkGameClient_isBackgroundMap = 0x281477;
            constexpr std::ptrdiff_t dwNetworkGameClient_localPlayer = 0xF0;
            constexpr std::ptrdiff_t dwNetworkGameClient_maxClients = 0x270;
            constexpr std::ptrdiff_t dwNetworkGameClient_serverTickCount = 0x174;
            constexpr std::ptrdiff_t dwNetworkGameClient_signOnState = 0x260;
            constexpr std::ptrdiff_t dwWindowHeight = 0x5F4BE4;
            constexpr std::ptrdiff_t dwWindowWidth = 0x5F4BE0;
        }
        // Module: inputsystem.dll
        namespace inputsystem_dll {
            constexpr std::ptrdiff_t dwInputSystem = 0x377E0;
        }
        // Module: matchmaking.dll
        namespace matchmaking_dll {
            constexpr std::ptrdiff_t dwGameTypes = 0x1A41A0;
            constexpr std::ptrdiff_t dwGameTypes_mapName = 0x120;
        }
        // Module: soundsystem.dll
        namespace soundsystem_dll {
            constexpr std::ptrdiff_t dwSoundSystem = 0x334E40;
            constexpr std::ptrdiff_t dwSoundSystem_engineViewData = 0x7C;
        }
    }
}