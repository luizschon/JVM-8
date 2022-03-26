#ifndef _WINDOWS_HPP
#define _WINDOWS_HPP

// https://stackoverflow.com/questions/3213037/determine-if-linux-or-windows-in-c
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <unistd.h>
inline void create_dir()
{
    mkdir("out");
}

#else
#include <sys/stat.h>
inline void create_dir()
{
    mkdir("out", 0777);
}
#endif

#endif // _WINDOWS_HPP