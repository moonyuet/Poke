#pragma once

#include "Poke/Core/Base.h"
#include "Poke/Core/Log.h"
#include "Poke/Scene/Scene.h"
#include "Poke/Scene/Entity.h"

namespace Poke {
	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& context);

		void SetContext(const Ref<Scene>& context);

		void OnImGuiRender();

	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;

		Entity m_SelectionContext;
	};
}