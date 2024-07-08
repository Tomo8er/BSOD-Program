#include <windows.h>
#include <winioctl.h>

#define IOCTL_CRASH CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_NEITHER, FILE_ANY_ACCESS)

int main() {
    HANDLE hDevice = CreateFile(TEXT("\\\\.\\MyDriver"), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

    if (hDevice != INVALID_HANDLE_VALUE) {
        DWORD bytesReturned;
        DeviceIoControl(hDevice, IOCTL_CRASH, NULL, 0, NULL, 0, &bytesReturned, NULL);
        CloseHandle(hDevice);
    }

    return 0;
}
