#include "AllocConsole.h" 

/*
Credits unex
2020
*/
void Bypass::AllocConsole() {
    using AllocConsole_t = bool(_stdcall*)();
    uint64_t allocConsole = 0;
    BYTE consoleShell[]{ 0xFF, 0x25, 0x00, 0x00, 0x00, 0x00, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, 0x69, };
    DWORD curPr;
    VirtualProtect((void*)(Utility::CustomAPI::GetModuleA("KERNELBASE.dll") + 0xF1BB0 + 29), 1, PAGE_EXECUTE_READWRITE, &curPr);
    *(BYTE*)(Utility::CustomAPI::GetModuleA("KERNELBASE.dll") + 0xF1BB0 + 29) = 1;
    VirtualProtect((void*)(Utility::CustomAPI::GetModuleA("KERNELBASE.dll") + 0xF1BB0 + 29), 1, curPr, &curPr);
    if (!allocConsole) {
        allocConsole = reinterpret_cast<uint64_t>(VirtualAlloc(NULL, sizeof(consoleShell), MEM_COMMIT, 0x40));
        memcpy((void*)allocConsole, (void*)consoleShell, sizeof(consoleShell));
        *(uint64_t*)(allocConsole + 6) = Utility::CustomAPI::GetModuleA("KERNELBASE.dll") + 0x5C10;
    }
    ((AllocConsole_t)(allocConsole))();
}