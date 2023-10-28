#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
//declare functions

void randomize(int* arr, int size);
int** createSquare();
void freeMemory(int** arr);
void printSquare(int** arr);
bool isValidSquare(int** arr);
int i;
time_t t;

int** createSquare(){
    int** arr = (int**)malloc(3*sizeof(int*));
    int numbers[9] = {1,2,3,4,5,6,7,8,9};
    int index = 0;
    randomize(numbers, 9);

    for(int i = 0; i < 3; i++){
        arr[i] = (int*)malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) {
            arr[i][j] = numbers[index];
            index++;
        }
    }
    return arr;
}
bool isValidSquare(int** arr){
    int rowSum = 0;
    int col1Sum = 0;
    int col2Sum = 0;
    int col3Sum = 0;
    int diagTopRSum = 0;
    int diagBotSum = 0;

    for(int i = 0; i < 3; i++){
        rowSum = 0;
        for (int j = 0; j < 3; j++) {
            rowSum += arr[i][j];
            if(j == 0) col1Sum+=arr[i][j];
            if(j == 1) col2Sum+=arr[i][j];
            if(j == 2) col3Sum+=arr[i][j];
        }
        if(rowSum != 15)return false;
    }
    if(col1Sum != 15)return false;
    if(col2Sum != 15)return false;
    if(col3Sum != 15)return false;

    diagTopRSum += arr[0][2];
    diagTopRSum += arr[1][1];
    diagTopRSum += arr[2][0];

    diagBotSum += arr[0][0];
    diagBotSum += arr[1][1];
    diagBotSum += arr[2][2];

    return(diagBotSum == diagTopRSum && diagBotSum == 15);
}

//create method of randomizing an array:
void randomize(int* arr, int size) {
    for (int i = size - 1; i > 0; i--) {  
        // Generate a random index between 0 and i (both inclusive).
        int j = rand() % (i + 1);  
        // Swap elements at indices i and j.
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
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
    srand((unsigned) time(&t));

    int count = 1;
    int** square = createSquare();
    while (!isValidSquare(square))
    {   
        freeMemory(square);
        count++;
        square = createSquare();
    }
    
    printf("It took %d many squares!\n",count);
    printSquare(square);
    freeMemory(square);
    

    return 0;
}