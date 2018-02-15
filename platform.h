#pragma once

#define __PLATFORM_WINDOWS     0
#define __PLATFORM_LINUX       1
#define __PLATFORM_BSD         2
#define __PLATFORM_UNDEFINED  -1 


#if defined(_WIN32) || defined(_WIN64)
    #define __PLATFORM_CURRENT __PLATFORM_WINDOWS
#elif defined(__CYGWIN__)
    #define __PLATFORM_CURRENT __PLATFORM_WINDOWS
#elif defined(__linux__)
    // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
    #define __PLATFORM_CURRENT __PLATFORM_LINUX 
#elif defined(__unix__) || defined(__APPLE__) && defined(__MACH__)
    // FreeBSD, NetBSD, OpenBSD, DragonFly BSD
    #define __PLATFORM_CURRENT __PLATFORM_BSD
#else 
    #define __PLATFORM_CURRENT __PLATFORM_UNDEFINED
#endif