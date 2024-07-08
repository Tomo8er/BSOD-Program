//windows bsod

#include <windows.h>

int main() {
    // EAX = 0xDEAD
    // ECX = 0xBEEF
    // CRASH! (0xDEADBEEF)
    __asm {
        mov eax, 0xDEAD
        mov ecx, 0xBEEF
        int 0x2e
    }
    return 0;
}
