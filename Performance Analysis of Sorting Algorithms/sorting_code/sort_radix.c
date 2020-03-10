
// C - Radix Sort 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
  
int getMax(int arr[], int n) { 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
void countSort(int arr[], int n, int exp) { 
    int *output = malloc(sizeof(int[n]));
    int i;
    int* count = malloc(sizeof(int[10]));    
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    for (i = n - 1; i >= 0; i--) { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
void radixsort(int arr[], int n) { 
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
  
int main(int argc, char* argv[]){ 
    int *arr = malloc(sizeof(int[10000000]));
    FILE *myFile;
    myFile = fopen(argv[1], "r");

    for (int i = 0; i < 10000000; i++){
        fscanf(myFile, "%d", &arr[i]);
    }

    int arr_size = 10000000; 
    clock_t begin = clock();

    radixsort(arr, arr_size); 
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time= %lf \n", time_spent);

    return 0; 
} 
