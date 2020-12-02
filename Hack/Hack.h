#ifndef __HACK_H__
#define __HACK_H__

#include "Base.h"


namespace Hack {

	void FindSomeAddresses() {
		// Create new base 
		auto base = new Base;

		// Add pointer to hack base
		base->AddPointer("KERNELBASE", (uint64_t)Utility::CustomAPI::GetModuleA("KERNELBASE.dll"));
		base->ChangePointer("KERNELBASE", 0x1FAD);
		uint64_t KernelBase = base->GetPointer("KERNELBASE");

		std::cout << std::hex << KernelBase << std::endl;
	}

	void Constructor() {

		// Allocate Console 
		auto Console = Utility::GetConsole();
		Console->Allocate();
		Console->SetTitle("MachineTherapist's internal cheat framework");
		Console->SetBackgroundColor(ConsoleBackground::BLACK);
		Console->SetTextColor(ConsoleForeground::DARKGREEN);

		// Find some Addresses 
		FindSomeAddresses();

	}

}

#endif // __HACK_H__
