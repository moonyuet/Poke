#pragma once

#include "Base.h"

#ifdef PK_PLATFORM_WINDOWS

extern Poke::App* Poke::CreateApp(); 

int main(int argc, char** argv)
{
	Poke::Log::Init();
	
	PK_PROFILE_BEGIN_SESSION("Startup", "PokeProfile-Startup.json");

	auto app = Poke::CreateApp();

	PK_PROFILE_END_SESSION();

	PK_PROFILE_BEGIN_SESSION("Runtime", "PokeProfile-Runtime.json");
	app->Run();
	PK_PROFILE_END_SESSION();

	PK_PROFILE_BEGIN_SESSION("Startup", "PokeProfile-Shutdown.json");
	delete app;
	PK_PROFILE_END_SESSION();
}
#endif