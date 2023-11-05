#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = { "ls", "-l", NULL };

    printf("Running ls with execv\n");
    execv("/bin/ls", args);

    printf("This will only print if execv fails!\n");
    return 0;
}
