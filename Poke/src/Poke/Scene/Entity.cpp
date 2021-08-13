#include "pkpch.h"
#include "Entity.h"
namespace Poke
{
	Entity::Entity(entt::entity handle, Scene* scene)
		:m_EntityHandle(handle), m_Scene(scene)
	{
	}
}