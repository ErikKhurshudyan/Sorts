#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

void insertionSort(vector<int>& array);
void printArray(const vector<int>& array);

int
main()
{
    vector<int> array = {12, 11, 13, 5, 6};
    cout << "Original array: ";
    printArray(array);
    
    insertionSort(array);
    
    cout << "Sorted array: ";
    printArray(array);
    
    return 0;

}

void
insertionSort(vector<int>& array)
{
    const int size = array.size();
    
    for (int i = 1; i < size; ++i) {
        const int value = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;
    }
}
 
void
printArray(const vector<int>& array)
{
    for (const auto& element : array) {
        cout << element << " ";
    }
    cout << endl;
}
