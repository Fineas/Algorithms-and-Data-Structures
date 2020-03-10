
// C - Heap Sort 
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
   
void swap(int* a, int* b){ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
void heapify(int arr[], int n, int i){ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i){ 
        swap(&arr[i], &arr[largest]); 
  
        heapify(arr, n, largest); 
    } 
} 
  
void heapSort(int arr[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--){ 
        swap(&arr[0], &arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 

  
int main(int argc, char* argv[]) { 
  
    int *arr = malloc(sizeof(int[10000000]));
    FILE *myFile;
    myFile = fopen(argv[1], "r");

    for (int i = 0; i < 10000000; i++){
        fscanf(myFile, "%d", &arr[i]);
    }

    int arr_size = 10000000; 
    clock_t begin = clock();

    heapSort(arr, arr_size); 

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time= %lf \n", time_spent);
  
    return 0;
} 
