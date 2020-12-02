#include "Base.h"

namespace Hack {

	static Base g_Base;


	// Pointers 
	std::map<std::string, uint64_t> pointers;

	void Base::AddPointer(const char* name, uint64_t addr) {
		pointers.insert(std::pair<std::string, uint64_t>(name, addr));
	}

	uint64_t Base::GetPointer(const char* name) {
		return pointers[name];
	}

	bool Base::ChangePointer(const char* name, uint64_t addr) {
		try {
			pointers.at(name) = addr;
		}
		catch (...) {
			return false;
		}
		return true;
	}

	Base* GetBase() {

		return &g_Base;
	}
}