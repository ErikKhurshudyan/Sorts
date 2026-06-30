#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <algorithm>
#include <iterator> 
#include <functional>

using namespace std;

void printArray(const vector<int>& array);
template <typename RandomIt, typename Compare>
void insertionSort(RandomIt first, RandomIt last, Compare comp);

template <typename RandomIt, typename Compare>
void heapify(RandomIt first, const int n, const int i, Compare comp);

template <typename RandomIt, typename Compare>
void heapSort(RandomIt first, RandomIt last, Compare comp);

template <typename RandomIt, typename Compare>
RandomIt partitionMy(RandomIt first, RandomIt last, Compare comp);

template <typename RandomIt, typename Compare>
void introsortUtil(RandomIt first, RandomIt last, const int depthLimit, Compare comp);

template <typename RandomIt, typename Compare>
void sortInAlgorithms(RandomIt first, RandomIt last, Compare comp);

template <typename RandomIt>
void sortInAlgorithms(RandomIt first, RandomIt last);

int
main()
{
    vector<int> array = {64, 25, 12, 22, 11};
    cout << "Original array: ";
    printArray(array);
    
    sortInAlgorithms(array.begin(), array.end(), [] (const int a, const int b) {return 0 == a % b;});
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

template <typename RandomIt, typename Compare>
void 
insertionSort(RandomIt first, RandomIt last, Compare comp)
{
    if (first == last) return;
    
    for (auto it = first + 1; it < last; ++it) {
        auto key = std::move(*it); 
        auto j = it;
        
        while (j > first && comp(key, *(j - 1))) {
            *j = std::move(*(j - 1));
            --j;
        }
        *j = std::move(key);
    }
}


template <typename RandomIt, typename Compare>
void
heapify(RandomIt first, const int n, const int i, Compare comp) 
{
    int largest = i;
    const int left = 2 * i + 1;
    const int right = 2 * i + 2;

    if (left < n && comp(*(first + largest), *(first + left))) 
        largest = left;
    if (right < n && comp(*(first + largest), *(first + right))) 
        largest = right;

    if (largest != i) {
        std::swap(*(first + i), *(first + largest));
        heapify(first, n, largest, comp);
    }
}

template <typename RandomIt, typename Compare>
void 
heapSort(RandomIt first, RandomIt last, Compare comp)
{
    const int n = std::distance(first, last);
    for (int i = n / 2 - 1; i >= 0; --i) 
        heapify(first, n, i, comp);
        
    for (int i = n - 1; i > 0; --i) {
        std::swap(*first, *(first + i));
        heapify(first, i, 0, comp);
    }
}

template <typename RandomIt, typename Compare>
RandomIt
partitionMy(RandomIt first, RandomIt last, Compare comp)
{
    auto pivot_it = last - 1;
    
    using value_type = typename std::iterator_traits<RandomIt>::value_type;
    value_type pivot = *pivot_it; 
    
    auto i = first;
    for (auto j = first; j < pivot_it; ++j) {
        if (!comp(pivot, *j)) { 
            std::swap(*i, *j);
            ++i;
        }
    }
    std::swap(*i, *pivot_it);
    return i;
}

template <typename RandomIt, typename Compare>
void
introsortUtil(RandomIt first, RandomIt last, const int depthLimit, Compare comp)
{
    const int size = std::distance(first, last);

    if (size < 16) {
        insertionSort(first, last, comp);
        return;
    }

    if (0 == depthLimit) {
        heapSort(first, last, comp);
        return;
    }

    RandomIt pivot_it = partitionMy(first, last, comp);
    
    introsortUtil(first, pivot_it, depthLimit - 1, comp);
    introsortUtil(pivot_it + 1, last, depthLimit - 1, comp);
}


template <typename RandomIt, typename Compare>
void
sortInAlgorithms(RandomIt first, RandomIt last, Compare comp)
{
    if (first == last) return;
    const int depthLimit = 2 * std::log2(std::distance(first, last));
    introsortUtil(first, last, depthLimit, comp);
}

template <typename RandomIt>
void
sortInAlgorithms(RandomIt first, RandomIt last)
{
    using value_type = typename std::iterator_traits<RandomIt>::value_type;
    sortInAlgorithms(first, last, std::less<value_type>());
}
