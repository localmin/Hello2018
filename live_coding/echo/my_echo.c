#include <stdio.h>

static void unescape(char* p){
    for(; *p;  p++){
        if(*p == '\n' || p[1] =='\0'){
            printf("%c", *p);
            continue;
        }

        p++;
        if(*p == 'n'){
            printf("\n");
        }else if(*p == 't'){
            printf("\t");
        }else{
            printf("\\%c", *p);
        }
    }
}

int main(int argc, char** argv){
    char** args = argv + 1;
    for(char** p = argv + 1; *p; p++)
        printf("%s%s",(p == argv ? "": " " ), *p);
        //printf("%s ", *p);
    printf("\n");
    return 0;
}
