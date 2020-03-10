/* C - QuickSort */
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
  
void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high){ 
    int pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) {  
        if (arr[j] < pivot){ 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high){ 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

void printarr(int arr[], int n){
    for(int i =0; i < n; i++){
        printf("%d ",arr[i]);
    }
}
   
int main(int argc, char *argv[]){ 
    int *arr = malloc(sizeof(int[10000000]));
    srand(time(0)); 
    FILE *myFile;
    myFile = fopen(argv[1], "r");

    for (int i = 0; i < 10000000; i++){
        fscanf(myFile, "%d", &arr[i]);
    }
    int arr_size = 10000000; 
    clock_t begin = clock();

    quickSort(arr, 0, arr_size-1); 

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time= %lf \n", time_spent);
    free(arr);

    return 0; 
} 
