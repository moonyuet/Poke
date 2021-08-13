#include <Poke.h>
#include <Poke/Core/EntryPoint.h>

#include "PokeNeedle.h"

namespace Poke {

	class PokeEditor :public App
	{
	public:
		PokeEditor()
			:App("PokeNeedle")
		{
			PushLayer(new PokeNeedle());

		}
		~PokeEditor()
		{

		}
	};


	Poke::App* Poke::CreateApp()
	{
		return new PokeEditor();
	}

		
}
