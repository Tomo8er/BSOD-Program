#include <windows.h>

int main() {
    // 任意のメモリアドレスにアクセスして破壊する
    *(int *)0x00000000 = 0;
    return 0;
}
