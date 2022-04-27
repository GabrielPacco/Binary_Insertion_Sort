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
int binarySearch(int A[], int low, int high, int key)
{
    if (low >= high)
        return (key > A[low]) ? (low + 1) : low;
    int mid = (high + low) / 2;
    if (A[mid] == key)
        return mid + 1;
    if (A[mid] > key)
        return binarySearch(A, low, mid - 1, key);
    return binarySearch(A, mid + 1, high, key);
}
void insertionSort(int A[], int n)
{
    int i, pos, j, key;
 
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        key = A[i];
 
        // encontrar el lugar donde se debe insertar la llave
        pos = binarySearch(A, 0, j, key);
 
        // Mover todos los elementos después de la ubicación para crear espacio
        while (j >= pos)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
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
