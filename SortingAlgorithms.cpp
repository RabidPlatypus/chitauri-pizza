#include <stdio.h>
#include <iostream>

using namespace std;


void PrintArray(int nums[], int size) {
    int i = 0;
    for (i = 0; i < size; ++i) {
        if (i == size - 1) {
            cout << nums[i] << endl;
        }
        else {
            cout << nums[i] << ", ";
        }
    }
}
void InsertSort(int nums[], int size) {
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 1; i < size; ++i) {
        j = i;
        while (j > 0 && nums[j] < nums[j - 1]) {
            temp = nums[j];
            nums[j] = nums[j - 1];
            nums[j - 1] = temp;
            --j;
        }
    }
    PrintArray(nums, size);
}

void Merge(int nums[], int left, int middle, int right) {
    int mergedSize = right - left+1;
    int mergePos = 0;
    int leftPos = left;
    int rightPos = middle + 1;
    int *mergedNums = new int[mergedSize];

    while (leftPos <= middle && rightPos <= right) {
        if (nums[leftPos] <= nums[rightPos]) {
            mergedNums[mergePos] = nums[leftPos];
            ++leftPos;
        }
        else {
            mergedNums[mergePos] = nums[rightPos];
            ++rightPos;
        }
        ++mergePos;
    }
    while (leftPos <= middle) {
        mergedNums[mergePos] = nums[leftPos];
        ++leftPos;
        ++mergePos;
    }
    while (rightPos <= right) {
        mergedNums[mergePos] = nums[rightPos];
        ++rightPos;
        ++mergePos;
    }
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        nums[left + mergePos] = mergedNums[mergePos];
    }
}

void MergeSort(int nums[], int left, int right) {
    int j = 0;
    if (left < right) {
        j = (left + right) / 2;
        MergeSort(nums, left, j);
        MergeSort(nums, j + 1, right);
        Merge(nums, left, j, right);

    }  
}

int Partition(int nums[], int low, int high, int pivot) {
    int i = low;
    int j = low;
    int temp = 0;
    while (i <= high) {
        if (nums[i] > pivot) {
            i++;
        }
        else {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j++;
        }
    }
    return j - 1;
}

void QuickSort(int nums[], int low, int high) {
    if (low < high) {
        int pivot = nums[high];
        int pos = Partition(nums, low, high, pivot);

        QuickSort(nums, low, pos - 1);
        QuickSort(nums, pos + 1, high);
    }
}

int main() {
    int input1[6] = { -1, 2, 3, 5, -2, 8 };
    cout << "Quick Sort" << endl;
    QuickSort(input1, 0, 5);
    PrintArray(input1, 6);
    cout << endl;

    int input2[6] = { -1, 2, 3, 5, -2, 8 };
    cout << "Insert Sort" << endl;
    InsertSort(input2, 6);
    cout << endl;

    int input3[6] = { -1, 2, 3, 5, -2, 8 };
    cout << "Merge Sort" << endl;
    MergeSort(input3,0, 5);
    PrintArray(input3, 6);
    
    return 0;
}
       
