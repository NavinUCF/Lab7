//Navin Singh COP 3502C
//Lab Assignment 7
#include <stdio.h>

//swaps two positions in the array using pointers
void swap(int *xp, int *yp){
    int temp =*xp;
    *xp = *yp;
    *yp = temp;
}

void selection_sort(int arr[], int n, int fArr[]){
    int i,j, min_idx, temp;
    //nested for loop that searches for the smallest value, then swap it with it with the value at i
    //increments i so the search range is smaller at every index
    for(i=0;i<n-1;i++){
        min_idx = i;
        for(j=i+1;j<n;j++)
            if(arr[j]<arr[min_idx])
                min_idx = j;
        if(min_idx != i){
            fArr[arr[i]]++;
            fArr[arr[min_idx]]++;
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    
}
void bubble_sort(int arr[], int n, int fArr[]){
    //nested for loop that swaps the item with the item next to it
    //also uses swap function to swap their positions
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                fArr[arr[j]]++;
                fArr[arr[j+1]]++;
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
void printFreq(int arr[], int n, int fArr[]){
    //prints the counts using a nested loop to search for the index that = the arr[i] value
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<100;j++){
            if(j==arr[i]){
                printf("%d: %d\n", arr[i], fArr[j]);
                total += fArr[j];
                break;
            }
        }
    }
    //prints the total # of swaps
    printf("%d\n", total/2);
}


int main(){
    //intialize arrays

    int arr1bSort[] = {97,16,45,63,13,22,7,58,72};
    int arr1sSort[] = {97,16,45,63,13,22,7,58,72};
    int arr2bSort[]= {90,80,70,60,50,40,30,20,10};
    int arr2sSort[]= {90,80,70,60,50,40,30,20,10};
    int size = 9;
    //frequency array for storing the counts of the swaps
    int freqArr[100];
    //series of calls for sorting and printing the # of swaps
    //also need to reset the freq array each time
    for(int i=0;i<100;i++)
        freqArr[i]=0;
    printf("array1 bubble sort:\n");
    bubble_sort(arr1bSort, size, freqArr);
    printFreq(arr1bSort, size, freqArr);
    
    for(int i=0;i<100;i++)
        freqArr[i]=0;
    printf("array2 bubble sort:\n");
    bubble_sort(arr2bSort, size, freqArr);
    printFreq(arr2bSort, size, freqArr);

    for(int i=0;i<100;i++)
        freqArr[i]=0;
    printf("array1 selection sort:\n");
    selection_sort(arr1sSort, size, freqArr);
    printFreq(arr1sSort, size, freqArr);
     
    for(int i=0;i<100;i++)
        freqArr[i]=0;
    printf("array2 selection sort:\n");
    selection_sort(arr2sSort, size, freqArr);
    printFreq(arr2sSort, size, freqArr);
    

    return 0;
} 