//#define _GNU_SOURCE
// getline はもともとGNU拡張だが標準化された
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // &lenを0にセットしかつline = MULLでバッファを確保
        num_lines++;
    // reallocでlinesのメモリの割り当て
    // reallocでは差分は初期化されない
        lines = (char**)realloc(lines, sizeof(char*) * num_lines);
        lines[num_lines - 1] = line;// line != lines
    }
    fclose(fp);

    int i;
    const char* prev_line = NULL;//const char : アドレス変更可，中身は不可
    for(i = 0; i < num_lines; i++){
        //隣り合った行だけ削除(表示)
        //if は0以外の値が入ったら真値
        if(!prev_line || strcmp(prev_line, lines[i]))
            printf("%s", lines[i]);
        prev_line = lines[i];
    }
    free(lines);
    return 0;
}
