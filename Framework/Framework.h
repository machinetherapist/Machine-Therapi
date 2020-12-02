#include "Framework/Utility/Console.h"
#include "Framework/Utility/Mem.h"
#include "Framework/Utility/CustomAPI.h"
#include "Framework/Utility/MinHook.h"

#if defined _M_X64
#pragma comment(lib, "Framework/Lib/minhook/libMinHook-x64-v141-mtd.lib")
#elif defined _M_IX86
#pragma comment(lib, "Framework/Lib/minhook/libMinHook-x86-v141-mtd.lib")
#endif