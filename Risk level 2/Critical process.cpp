#include <windows.h>

typedef NTSTATUS(WINAPI *PNtSetInformationProcess)(
    HANDLE ProcessHandle,
    DWORD ProcessInformationClass,
    PVOID ProcessInformation,
    ULONG ProcessInformationLength
    );

int main()
{
    ULONG isCritical = 1;
    DWORD BreakOnTermination = 0x1D;

    HMODULE hNtDll = LoadLibraryA("ntdll.dll");
    if (hNtDll == NULL)
    {
        return 1;
    }

    PNtSetInformationProcess NtSetInformationProcess = (PNtSetInformationProcess)GetProcAddress(hNtDll, "NtSetInformationProcess");
    if (NtSetInformationProcess == NULL)
    {
        FreeLibrary(hNtDll);
        return 1;
    }

    HANDLE hProcess = GetCurrentProcess();

    NTSTATUS status = NtSetInformationProcess(hProcess, BreakOnTermination, &isCritical, sizeof(isCritical));
    if (status != 0)
    {
        // エラーハンドリング
    }

    FreeLibrary(hNtDll);

    return 0;
}
