#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE 100
#define MAX_INPUT_LENGTH 20
void init(int arr[], int *size);
void append(int arr[], int *size, int value);
void insert_at_index(int arr[], int *size; int index, int value); 
void remove_at_index(int arr[], int *size, int index);
void display(const int arr[], int size);
int max(const int arr[], int size);
int min(const int arr[], int size);
void reverse(int arr[], int size);
void merge(int arr1[], int *size1, const int arr2[], int size2);

int main() {
    int arr1[MAX_SIZE];
    int arr2[MAX_SIZE];
    int size1 = 0, size2 = 0;
    char choice[MAX_INPUT_LENGTH];
    int value, index;

    while (1) {
        // Reading user's choice as a string
        scanf("%s", choice);

        if (strcmp(choice, "init") == 0) {
            init(arr1, &size1);
        } else if (strcmp(choice, "append") == 0) {
            scanf("%d", &value);
            append(arr1, &size1, value);
        } else if (strcmp(choice, "insert_at_index") == 0) {
            scanf("%d %d", &index, &value);
            insert_at_index(arr1, &size1, index, value);
        } else if (strcmp(choice, "remove_at_index") == 0) {
            scanf("%d", &index);
            remove_at_index(arr1, &size1, index);
        } else if (strcmp(choice, "display") == 0) {
            display(arr1, size1);
        } else if (strcmp(choice, "max") == 0) {
            printf("%d", max(arr1, size1));
        } else if (strcmp(choice, "min") == 0) {
            printf("%d", min(arr1, size1));
        } else if (strcmp(choice, "reverse") == 0) {
            reverse(arr1, size1);
        } else if (strcmp(choice, "merge") == 0) {
            init(arr2, &size2);
            merge(arr1, &size1, arr2, size2);
        } else {
            break; // Exit the loop if an unrecognized command is entered
        }
    }
    
    return 0;
}

void init(int arr[], int *size) {
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        arr[i] = rand() % 100;
    }
}
void append(int arr[], int *size, int value) {
    if (*size < MAX_SIZE) {
        arr[(*size)++] = value;
    }
}
void insert_at_index(int arr[], int *size, int index, int value) {
    if (*size < MAX_SIZE && index >= 0 && index <= *size) {
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        (*size)++;
    }
}
void remove_at_index(int arr[], int *size, int index) {
    if (index >= 0 && index < *size) {
        for (int i = index; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
    }
}

void display(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
int max(const int arr[], int size) {
    int max_value = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int min(const int arr[], int size) {
    int min_value = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    return min_value;
}
void reverse(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
void merge(int arr1[], int *size1, const int arr2[], int size2) {
    if (*size1 + size2 <= MAX_SIZE) {
        for (int i = 0; i < size2; i++) {
            arr1[(*size1)++] = arr2[i];
        }
    }
}