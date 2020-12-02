#ifndef __CUSTOMAPI_H__
#define __CUSTOMAPI_H__

#pragma once
#include <Windows.h>
#include <stdio.h>
#include <cstdint>
#include <functional>

namespace Utility {
	class CustomAPI {
	public:
		static DWORD64 WINAPI GetModuleA(_In_opt_ LPCSTR lpModuleName);
		static DWORD64 WINAPI GetModuleBySize(_In_opt_ ULONG size);
	};
}

#endif // __CUSTOMAPI_H__