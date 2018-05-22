// main.cpp
// g++ -o cpp main.cpp winlin.a
#include <stdio.h>
#include "winlin.h"
int main(int argc, char** argv) {
    printf("version is %#x\n", winlin_version());
    return 0;
}
