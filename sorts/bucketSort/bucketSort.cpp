#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& array);
void printArray(const vector<float>& array);

int
main()
{
    vector<float> array = {64.5, 34.2, 25.8, 12.1, 22.9, 11.3, 90.7};
    printArray(array);

    bucketSort(array);
    printArray(array);

    return 0;
}

void
bucketSort(vector<float>& array)
{
    const int size = array.size();
    if (size <= 0) return;
    
    vector<vector<float>> buckets(size);

    for (int i = 0; i < size; ++i) {
        int bucketIndex = array[i] * size;
        if (bucketIndex >= size) {
            bucketIndex = size - 1;
        }

        buckets[bucketIndex].push_back(array[i]);
    }

    for (int i = 0; i < size; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        for (const auto& element : buckets[i]) {
            array[index++] = element;
        }
    }
}

void
printArray(const vector<float>& array)
{
    for (const auto& element : array) {
        cout << element << " ";
    }
    cout << endl;
}

