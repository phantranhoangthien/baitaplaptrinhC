#include <stdio.h>

// Hàm hoán đổi hai phần tử
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm phân hoạch (partition)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Chọn phần tử cuối cùng làm pivot
    int i = (low - 1);  // Chỉ số của phần tử nhỏ hơn

    for (int j = low; j < high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++;  // Tăng chỉ số của phần tử nhỏ hơn
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);  // Trả về chỉ số của phần tử phân hoạch
}

// Hàm thực hiện Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Tìm chỉ số phân hoạch
        int pi = partition(arr, low, high);

        // Sắp xếp các phần tử phân chia trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Mảng cần sắp xếp
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng

    printf("Mảng gốc: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Mảng sau khi sắp xếp: \n");
    printArray(arr, n);

    return 0;
}
