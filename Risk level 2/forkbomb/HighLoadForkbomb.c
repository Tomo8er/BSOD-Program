#include <unistd.h>
#include <stdio.h>

void cpu_stress() {
    while (1) {
        // CPUリソースを消費
    }
}

int main() {
    while (1) {
        fork();
        cpu_stress();
    }
    return 0;
}
