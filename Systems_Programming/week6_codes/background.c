#include <stdio.h>
#include <unistd.h> //POSIX Standard Lib

int main(int argc, char* argv[]) {
    
    int f = fork();

    if(f == 0) { //* current process is the child
        printf("I'm the child, doing stuff in the background\n\n");
        return 0;
    }
    printf("Just the parent... doing my thing, while my child helps in the background\n\n");

    
}