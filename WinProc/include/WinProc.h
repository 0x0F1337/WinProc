#pragma once

#include <Windows.h>
#include <vector>

#include <tlhelp32.h>
#include <Psapi.h>

#define DllExport __declspec( dllexport )


struct Process {
	public:
		DWORD pid;
		HANDLE hProcess;
		MODULEINFO mainModule;

		std::vector<DWORD> allThreads;
};


/// <summary>
/// Gets the process' ID given its name
/// </summary>
/// <param name="processName">The name of the process</param>
/// <returns>ID of the process</returns>
DllExport DWORD GetProcessId(LPSTR processName);


/// <summary>
/// Gets a HANDLE of a process given its name
/// </summary>
/// <param name="processName">The name of the process</param>
/// <returns>HANDLE of the process</returns>
DllExport HANDLE GetProcessHandle(LPSTR processName);


/// <summary>
/// Gets an instance with the information of a determined process given it's name
/// </summary>
/// <param name="processName">The name of the process</param>
/// <returns>The process information</returns>
DllExport Process GetProcessInfo(LPSTR processName);


/// <summary>
/// Gets the information from a determined module of a process
/// </summary>
/// <param name="moduleName">The name of the module to be searched</param>
/// <param name="processName">The name of the process where the module is located</param>
/// <returns>The module's info</returns>
DllExport MODULEINFO GetMainModuleInfo(LPSTR moduleName, LPSTR processName);


/// <summary>
/// Gets all threads of a process
/// </summary>
/// <param name="processName">Name of the process</param>
/// <returns>All threads in the process</returns>
DllExport std::vector<DWORD> GetProcessThreadsIds(LPSTR processName);


