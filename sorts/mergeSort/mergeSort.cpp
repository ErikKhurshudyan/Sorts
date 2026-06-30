#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>& array);
void mergeSortRecursive(vector<int>& array, const int left, const int right);
void merge(vector<int>& array, const int left, const int mid, const int right);

void printArray(const vector<int>& array);

int
main()
{
    vector<int> array = {64, 25, 12, 22, 11, 58};
    mergeSort(array);
    printArray(array);
    return 0;

}

void
printArray(const vector<int>& array)
{
    for (const auto& element : array) {
        cout << element << " ";
    }
    cout << endl;
}

void
mergeSort(vector<int>& array)
{
    if (array.empty()) return;

    mergeSortRecursive(array, 0, array.size() - 1);
}

void
mergeSortRecursive(vector<int>& array, const int left, const int right)
{
    if (left >= right) return;

    const int middle = left + (right - left) / 2;

    mergeSortRecursive(array, left, middle);
    mergeSortRecursive(array, middle + 1, right);
    merge(array, left, middle, right);
}

void
merge(vector<int>& array, const int left, const int mid, const int right)
{
    const int LeftSize = mid - left + 1;
    const int RightSize = right - mid;

    vector<int> leftArray(LeftSize);
    vector<int> rightArray(RightSize);

    for (int i = 0; i < LeftSize; ++i) {
        leftArray[i] = array[left + i];
    }  

    for (int j = 0; j < RightSize; ++j) {
        rightArray[j] = array[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < LeftSize && j < RightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k++] = leftArray[i++];
        } else {
            array[k++] = rightArray[j++];
        }
    }

    while (i < LeftSize) {
        array[k++] = leftArray[i++];
    }

    while (j < RightSize) {
        array[k++] = rightArray[j++];
    }
} 
