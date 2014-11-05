/**************************************************
	RPlatform.h

	Robert	2014/09/04
**************************************************/
#ifndef __RPLATFORM_H_
#define __RPLATFORM_H_

#if defined(_MSC_VER)

#if defined(WINRT)
#define R_PLATFORM_WINRT	1
#else
#define R_PLATFORM_WIN_DESKTOP	1
#endif

#if defined(_WIN64)
#define R_PLATFORM_64	1
#elif defined(_WIN32)
#define R_PLATFORM_32	1
#endif

#elif defined(__ANDROID__)
#define  R_PLATFORM_ANDROID	1

#if defined(__x86_64__)
#define R_PLATFORM_64	1
#elif
#define R_PLATFORM_32	1
#endif

#elif defined(__linux__)
#define  R_PLATFORM_LINUX	1

#if defined(__x86_64__)
#define R_PLATFORM_64	1
#elif
#define R_PLATFORM_32	1
#endif

#elif defined(__APPLE__)
#define  R_PLATFORM_XOS	1

#if defined(__x86_64__) || defined(__arm64__)
#define R_PLATFORM_64	1
#elif
#define R_PLATFORM_32	1
#endif

#endif

#ifdef __cplusplus
#define R_BEGIN_EXTERN_C	extern "C" {
#define R_END_EXTERN_C	}
#define R_EXTERN_C	extern "C"
#else
#define R_BEGIN_EXTERN_C
#define R_END_EXTERN_C
#define R_EXTERN_C
#endif

#endif