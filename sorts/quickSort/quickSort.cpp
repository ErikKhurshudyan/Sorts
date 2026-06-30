#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& array);
void quickSortRecursive(vector<int>& array, const int low, const int high);
int partition(vector<int>& array, const int low, const int high);
void printArray(const vector<int>& array);

int
main()
{
    vector<int> array1 = {64, 25, 12, 22, 11, 58};
    quickSort(array1);
    printArray(array1);
   
    return 0;
}

void
printArray(const vector<int>& array)
{
    for (const auto& element : array) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void
quickSort(vector<int>& array)
{
    if (array.empty()) return;

    quickSortRecursive(array, 0, array.size() - 1);
}

void
quickSortRecursive(vector<int>& array, const int low, const int high)
{
    if (low >= high) return;

    const int pivotIndex = partition(array, low, high);

    quickSortRecursive(array, low, pivotIndex - 1);
    quickSortRecursive(array, pivotIndex + 1, high);
}

int
partition(vector<int>& array, const int low, const int high)
{
    const int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}
