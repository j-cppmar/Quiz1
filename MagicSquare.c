#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** createSquare(){
    int** arr = (int**)malloc(3*sizeof(int*));

    for(int i = 0; i < 3; i++){
        arr[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            arr[i][j] = 0;  // initializing each element to 0
        }
    }
    return arr;
}

void printSquare(int** arr){
    for(int i = 0; i <3;i++){
        for(int j = 0; j < 3; j++){
            if(j ==0) printf("[");
            printf(" %d " ,arr[i][j]);
            if(j==2)printf("]\n");
        }
    }
}

void freeMemory(int** arr){
    for(int i = 0; i < 3; i++){
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char const *argv[])
{
    int** square = createSquare();

    printSquare(square);
    return 0;
}
