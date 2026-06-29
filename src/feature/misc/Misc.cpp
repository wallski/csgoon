#include "Misc.h"
#include "../combat/Combat.h"
#include "bhop/Bhop.h"
#include "noflash/NoFlash.h"
#include "nosmoke/NoSmoke.h"

void Misc::Render()
{
	// Placeholder for miscellaneous rendering features
}

void Misc::Run() {
	Combat::Run();
	BunnyHop::Run();
	NoFlash::Run();
	NoSmoke::Run();
}