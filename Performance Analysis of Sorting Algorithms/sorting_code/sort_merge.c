
/* C - Merge Sort */
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

void merge(int arr[], unsigned int l,unsigned int m, unsigned int r) 
{ 
    unsigned int i, j, k; 
    unsigned int n1 = m - l + 1; 
    unsigned int n2 =  r - m; 
  
    int *L = malloc(sizeof(int[n1]));
    int* R = malloc(sizeof(int[n2])); 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0;
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], unsigned int l, unsigned int r) { 
    if (l < r) {  
        unsigned int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}  
  
int main(int argc, char* argv[]) { 

    int *arr = malloc(sizeof(int[10000000]));
    FILE *myFile;
    myFile = fopen(argv[1], "r");

    for (int i = 0; i < 10000000; i++){
        fscanf(myFile, "%d", &arr[i]);
    }

    unsigned int arr_size = 10000000; 
    clock_t begin = clock();
    
    mergeSort(arr, 0, arr_size - 1); 
    
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Execution Time= %lf \n", time_spent);
    
    return 0; 
} 
