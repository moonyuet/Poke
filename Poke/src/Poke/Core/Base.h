#pragma once
#include <memory>
#ifdef _WIN32
/* Windows x64/x86 */
	#ifdef _WIN64
	/* Windows x64  */
		#define PK_PLATFORM_WINDOWS
#else
	/* Windows x86 */
		#error "x86 Builds are not supported!"
#endif
#elif defined(__APPLE__) || defined(__MACH__)
		#include <TargetConditionals.h>
	/* TARGET_OS_MAC exists on all the platforms
	 * so we must check all of them (in this order)
	 * to ensure that we're running on MAC
	 * and not some other Apple platform */
	#if TARGET_IPHONE_SIMULATOR == 1
		#error "IOS simulator is not supported!"
	#elif TARGET_OS_IPHONE == 1
		#define PK_PLATFORM_IOS
	#error "IOS is not supported!"
		#elif TARGET_OS_MAC == 1
	#define PK_PLATFORM_MACOS
		#error "MacOS is not supported!"
	#else
		#error "Unknown Apple platform!"
	#endif
 /* We also have to check __ANDROID__ before __linux__
  * since android is based on the linux kernel
  * it has __linux__ defined */
#elif defined(__ANDROID__)
	#define PK_PLATFORM_ANDROID
	#error "Android is not supported!"
#elif defined(__linux__)
	#define PK_PLATFORM_LINUX
	#error "Linux is not supported!"
#else
/* Unknown compiler/platform */
	#error "Unknown platform!"
#endif // End of platform detection


#ifdef PK_PLATFORM_WINDOWS
	#if PK_DYNAMIC_LINK
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
	#if defined(PK_PLATFORM_WINDOWS)
		#define PK_DEBUGBREAK() __debugbreak()
	#elif defined(PK_PLATFORM_LINUX)
		#incude <signal.h>

		#define PK_DEBUGBREAK() raise(SIGTRAP)
	#else

		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define PK_ENABLE_ASSERTS
#else

	#define PK_DEBUGBREAK()
#endif

#ifdef PK_ENABLE_ASSERTS
	#define PK_ASSERT(x,...){if(!(x)){PK_ERROR("Assertion Failed: {0}", __VA_ARGS__);PK_DEBUGBREAK();}}
	#define PK_CORE_ASSERT(x,...){if(!(x)){PK_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);PK_DEBUGBREAK();}}
#else
	#define PK_ASSERT(x,...)
	#define PK_CORE_ASSERT(x,...)
#endif
namespace Poke {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
	
}
#define BIT(x) (1 << x)

#define PK_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

