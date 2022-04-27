//
//  main.cpp
//  Binary_InsertionSort_Time
//
//  Created by Gabriel on 27/04/22.
//


#include <iostream>
#include <chrono>
#include <fstream>
#include <time.h>
#include <vector>
using namespace std;

struct Timer
{
    std::chrono::system_clock::time_point m_start;
    Timer()
    {
        m_start = std::chrono::system_clock::now();
    }
    ~Timer()
    {
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<float> duration = end - m_start;
        std::cout << duration.count() << " segundos" << std::endl;
    }
};
int binarySearch(int a[], int item, int low, int high)
{
    if (high <= low)
        return (item > a[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == a[mid])
        return mid + 1;
    if (item > a[mid])
        return binarySearch(a, item, mid + 1, high);
    return binarySearch(a, item, low, mid - 1);
}
// Function to sort an array a[] of size 'n'
void insertionSort(int a[], int n)
{
    int i, pos, j, key;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        key = a[i];
        // find location where key should be inseretd
        pos = binarySearch(a, key, 0, j);
        // Move all elements after location to create space
        while (j >= pos)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
// Driver Code
int main()
{
    srand((unsigned int)time(NULL));
    int random;
    vector<int> arr;
    int cant = 1000;
    for (int i = 0; i < 100; i++)
    {
        ofstream archivo("random.txt");
        archivo << "Cantidad de elementos: " << cant << endl;
        for (int j = 0; j < cant; j++)
        {
            random = rand() % cant*2;
            arr.push_back(random);
            archivo << random << " "<< endl;
        }
        cout << "Tiempo con " << cant << " elementos: ";
        Timer t;
        insertionSort(arr.data(), cant);
        arr.clear();
        cant += 2000;
        archivo.close();
    }
    return 0;
}
// this code is contribution by shivanisinghss2110
