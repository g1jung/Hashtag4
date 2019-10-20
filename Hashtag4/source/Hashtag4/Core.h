#pragma once

#ifdef H4_PLATFORM_WINDOWS
	#ifdef H4_BUILD_DLL
		#define HASHTAG4_API __declspec(dllexport)
	#else
		#define HASHTAG4_API __declspec(dllimport)
	#endif
#else
	#error Hashtag4 only supports Windows!
#endif

#define BIT(x) (1 << x)
