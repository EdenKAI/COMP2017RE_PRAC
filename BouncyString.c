#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * bouncystr(char* str, int index, int len){
    char *result_ptr;
    int is_upward = 1;
    int len_str = strlen(str);
    int len_rest_first_run = len_str - index;

    int index_print = index;
    int count_upward = 0;
    int count_backward = 0;
    for (int i = 0; i <= len; i++){
        if (is_upward){
            printf("%c", str[index_print]);
            index_print += 1;
            if (str[index_print] == '\0'){
                index_print -= 2;
                is_upward = 0;
            }
        }
        else{
            printf("%c", str[index_print]);
            index_print -= 1;
            count_backward += 1;
            if (count_backward == len_str - 1){
                index_print += 2;
                is_upward = 1;
                count_backward = 0;
            }
        }
    }
    printf("\n");
    return result_ptr;
}


// int main(int argc, char **argv){
int main(int argc, char *argv[]){
    if (argc != 4){
        printf("Invalid arguments length\n");
        return 1;
    }
    int index = atoi(argv[2]);
    int len = atoi(argv[3]);
    if (index < 0){
        printf("Invalid start position\n");
        return 2;
    }
    else if (len < 0){
        printf("Invalid iteration count\n");
        return 3;
    }
    bouncystr(argv[1], index, len);
    return 0;
}