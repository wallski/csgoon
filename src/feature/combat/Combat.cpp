#include "./legitbot/Aimbot.h"
#include "Combat.h"
#include "ragebot/ragebot.h"
#include "triggerbot/triggerbot.h"

void Combat::Run() {
	Aimbot::Run();
	RageAimbot::Run();
	Triggerbot::Run();;
}