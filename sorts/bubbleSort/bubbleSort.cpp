#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& array);
void printArray(const vector<int>& array);

int
main()
{
    vector<int> array = {64, 34, 25, 12, 22, 11, 90};
    printArray(array);

    bubbleSort(array);
    printArray(array);

    return 0;
}

void 
bubbleSort(vector<int>& array)
{
    const int size = array.size();

    bool swapped = true;

    for (int i = 0; i < size; ++i) {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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