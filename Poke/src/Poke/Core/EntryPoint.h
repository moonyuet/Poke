#pragma once


#ifdef PK_PLATFORM_WINDOWS

extern Poke::App* Poke::CreateApp(); 

int main(int argc, char** argv)
{
	Poke::Log::Init();
	//PK_CORE_WARN("Initialized Log!");
	
	//PK_INFO("Hello");
	auto app = Poke::CreateApp();
	app->Run();
	delete app;
}
#endif