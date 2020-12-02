#ifndef __BASE_H__
#define __BASE_H__

#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace Hack {

	class Base {

	public:

		// Pointers
		void AddPointer(const char* name, uint64_t addr);

		uint64_t GetPointer(const char* name);

		bool ChangePointer(const char* name, uint64_t addr);
	};


	Base* GetBase();
}


#endif // __BASE_H__