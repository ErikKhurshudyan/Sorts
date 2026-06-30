#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int>& array);
void printArray(const vector<int>& array);

int
main()
{
    vector<int> array = {64, 25, 12, 22, 11};
    cout << "Original array: ";
    printArray(array);
    
    selectionSort(array);
    
    cout << "Sorted array: ";
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
selectionSort(vector<int>& array)
{
    const int size = array.size();
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(array[i], array[minIndex]);
        }
    }
}
