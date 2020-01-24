#include <stdio.h>

extern "C" int hello();

int main {
    int x = hello();
    printf("Return code: %x\n", x);
    return 0;
}