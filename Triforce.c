#include <stdio.h>
#include <stdlib.h>

void print_space(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

void print_underline(int n){
    for(int i = 0; i < n; i++){
        printf("_");
    }
}

void generate_triangle(int h){
    // top triangle
    for (int i = 0; i < h; i++){
        for (int j = 0; j < (2*h-i-1); j++){
            printf(" ");
        }
        printf("/");
        if (i == h-1){
            print_underline(2*i);
        }
        else{
            print_space(2*i);
        }

        printf("\\\n");
    }
    // bottom two triangles
    for (int i = 0; i < h; i++){
        for (int j = 0; j < h-i-1; j++){
            printf(" ");
        }
        printf("/");
        if (i == h-1){
            print_underline(2*i);
        }
        else{
            print_space(2*i);
        }
        printf("\\");
        print_space(2*(h-i-1));
        printf("/");
        if (i == h-1){
            print_underline(2*i);
        }
        else{
            print_space(2*i);
        }
        printf("\\\n");
        

    }

}


int main(){
    int h;
    char *buffer = malloc(sizeof(char)*50);
    printf("Enter height: ");
    fgets(buffer, 100, stdin);
    printf("\n");
    //printf("%d\n", atoi(buffer));
    h = atoi(buffer);
    if (h == 0){
        printf("Invalid height.\n");
        return 0;
    }
    else if (h > 20 || h < 2){
        printf("Invalid height.\n");
        return 0;
    }

    generate_triangle(h);


    return 0;
}