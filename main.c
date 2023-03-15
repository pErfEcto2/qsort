#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void q_sort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int mid = (int)((high + low) / 2);
    
    int i = low;

    swap(&arr[mid], &arr[high]);

    for (int j = low; j < high; j++) {
        if (arr[j] < arr[high]) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    q_sort(arr, low, i);
    q_sort(arr, i + 1, high);
}


int main() {
    srand(time(0));

    int* arr = malloc(sizeof(int) * N);

    printf("Before sort: ");
    for (int i; i < N; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    q_sort(arr, 0, N - 1);
    
    printf("After sort:  ");
    for (int i; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}