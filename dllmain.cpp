#include "dllmain.h"

/*
    Machinetherapi Internal Cheat Framework
    Made by machinetherapist with <3 
    2020
*/


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
     if(ul_reason_for_call == DLL_PROCESS_ATTACH) CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Hack::Constructor, 0, 0, 0);
     return TRUE;
}
