//Linux BSOD

#include <sys/io.h>

int main() {
    ioperm(0x64, 1, 1); // Get access to the keyboard controller
    outb(0xFE, 0x64); // Send the reset command
    return 0;
}
