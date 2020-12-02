#ifndef __MEM_H__
#define __MEM_H__

#include <windows.h>
#include <vector>

namespace Utility {

	class Mem {

	public:

		static void Patch(void* address, char* value);
		static void PatchStr(char* bytes, size_t len, char* newBytes);
		static void Nop(BYTE* dst, unsigned int size);
		static uintptr_t FindDMAAddy(uintptr_t ptr, std::vector<unsigned int> offsets);
	};
}

#endif // __MEM_H__