#pragma once
#include <memory>
#ifdef PK_PLATFORM_WINDOWS
#if PK_DYNAMIC_LINKS
	#ifdef PK_BUILD_DLL
		#define POKE_API __declspec(dllexport)
	#else
		#define POKE_API __declspec(dllimport)
#endif
#else 
	#define POKE_API
#endif
#else
	#error Poke only supports Windows!
#endif

#ifdef PK_DEBUG
	#define PK_ENABLE_ASSERTS
#endif

#ifdef PK_ENABLE_ASSERTS
	#define PK_ASSERT(x,...){if(!(x)){PK_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
	#define PK_CORE_ASSERT(x,...){if(!(x)){PK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);__debugbreak();}}
#else
	#define PK_ASSERT(x,...)
	#define PK_CORE_ASSERT(x,...)
#endif
namespace Poke {
	template<typename T>
	using Ref = std::shared_ptr<T>;
}
#define BIT(x) (1 << x)

#define PK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)