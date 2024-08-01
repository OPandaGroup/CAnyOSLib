#if defined(_WIN32) || defined(_WIN64)
#define System "Windows"
#define System_ID 0x00000001
#include <Windows.h>
#elif defined(__linux__) || defined(__unix__)
#define System "Linux/Unix"
#define System_ID 0x00000002
#include <sys/types.h>
#elif defined(__APPLE__)
#define System "Apple"
#define System_ID 0x00000003

#else
#define System "Unknown"
#endif