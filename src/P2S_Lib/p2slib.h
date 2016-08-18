#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define P2S_LIBSHARED_EXPORT __attribute__ ((dllexport))
    #else
      #define P2S_LIBSHARED_EXPORT __declspec(dllexport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #else
    #ifdef __GNUC__
      #define P2S_LIBSHARED_EXPORT __attribute__ ((dllimport))
    #else
      #define P2S_LIBSHARED_EXPORT __declspec(dllimport) // Note: actually gcc seems to also supports this syntax.
    #endif
  #endif
  #define DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define P2S_LIBSHARED_EXPORT __attribute__ ((visibility ("default")))
    #define P2S_LIBSHARED_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define P2S_LIBSHARED_EXPORT
    #define P2S_LIBSHARED_LOCAL
  #endif
#endif
