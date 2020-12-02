#include "Mem.h"

void Utility::Mem::Patch(void* address, char* value) {

	// keep old protect 
	DWORD oldProtect;

	// give r/w permisson the spesificated addr 
	VirtualProtect((void*)address, sizeof(value), PAGE_EXECUTE_READWRITE, &oldProtect);

	// Write to addr 
	memcpy((void*)address, &value, sizeof(value));

	// Get old page protect  
	VirtualProtect((void*)address, sizeof(value), oldProtect, &oldProtect);

}

void Utility::Mem::PatchStr(char* bytes, size_t len, char* newBytes) {
	DWORD oldProtect;
	VirtualProtect(bytes, len, PAGE_WRITECOPY, &oldProtect);
	strcpy(bytes, newBytes);
	VirtualProtect(bytes, len, oldProtect, nullptr);
}

void Utility::Mem::Nop(BYTE* dst, unsigned int size)
{
	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

uintptr_t Utility::Mem::FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets)
{
	uintptr_t addr = ptr;
	for (unsigned int i = 0; i < offsets.size(); ++i)
	{
		addr = *(uintptr_t*)addr;
		addr += offsets[i];
	}
	return addr;
}