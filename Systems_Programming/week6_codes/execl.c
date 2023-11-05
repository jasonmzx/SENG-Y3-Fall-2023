#include <stdio.h>
#include <unistd.h>

int main() {
    // execl takes the path to the program that will be executed
    // and all the arguments as separate strings ending with a NULL.
    printf("Before exec function\n");
    
    // Here, "/bin/ls" is the path to the ls program,
    // "-l" is an argument to list files in long format,
    // and NULL is the argument list terminator.
    execl("/bin/ls", "ls", "-l", (char *)NULL);

    // If execl is successful, the following line will not be executed
    // because the current process image is replaced by the new one.
    printf("This will not be printed if execl is successful\n");

    return 0;
}
