#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//const void*はマスト
int cmp(const void* a, const void* b){
    return strcmp(*(const char**)a,*(const char**)b );
}

int main(int argc, char* argv[]){
    FILE* fp = NULL;
    if(argc < 2){
        fp = stdin;
    }else{
        fp = fopen(argv[1], "rb"); // read binary 
    }
    char** lines = NULL;
    int num_lines = 0;
    char* line = NULL;
    size_t len = 0;
    for(; getline(&line, &len, fp) > 0; line = NULL){
        num_lines++;
        lines = (char**)realloc(lines, sizeof(char*) * num_lines);
        lines[num_lines - 1] = line;
    }
    fclose(fp);

    // クイックソート
    qsort(lines, num_lines, sizeof(char*), cmp);
    int i;
    const char* prev_line = NULL;//const char : アドレス変更可，中身は不可
    for(i = 0; i < num_lines; i++){
        printf("%s", lines[i]);
    }
    free(lines);
    return 0;
}
