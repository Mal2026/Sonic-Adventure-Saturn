#include "pch.h"


HelperFunctions HelperFunctionsGlobal;

void initConfig(const char* path, const HelperFunctions& helperFunctions);

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		HelperFunctionsGlobal = helperFunctions;

		initConfig(path, helperFunctions);

		//	HelperFunctions pointer for external use, "HelperFunctions HelperFunctionsGlobal;" needs to be present outside the extern C, check mod.h for in-depth explanation of this:

		//	Load our .PVR replacements:
		

	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}



