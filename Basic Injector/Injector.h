#ifndef INJECTOR_H
#define INJECTOR_H

extern "C" {
#pragma once
#include <TlHelp32.h>

	class Injector
	{
		DWORD GetProcId(const char* procName);
		int InjectorMain(const char* dll);

	};
}
#endif // !INJECTOR_H



