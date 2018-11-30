#include <stdio.h>

int main(int argc, char** argv){
    char** args = argv + 1;
    for(char** p = argv + 1; *p; p++)
        printf("%s%s",(p == argv ? "": " " ), *p);
        //printf("%s ", *p);
    printf("\n");
    return 0;
}
