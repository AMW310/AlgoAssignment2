// AlgorithmsAssignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

using namespace std;

void merge(int a[], int b[], int c[], int sizeA, int sizeB){
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) 
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }

    while (i < sizeA)
        c[k++] = a[i++];

    while (j < sizeB)
        c[k++] = b[j++];
}

void mergeSort(int arr[], int size) 
{
    if (size <= 1)
        return;

    int mid = size / 2;

    int *left = new int[mid];
    int *right = new int[size - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = arr[i];

    }
    

    /**/
    int one = 0;

    for (int i = 0; i < size; i++)
    {
        one = arr[i];
        cout << arr[i] << " ";
    }
        
    cout << endl;

    Sleep(1000);
    /**/

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(left, right, arr, mid, size - mid);

    /**/
    int two = 0;
    for (int i = 0; i < size; i++)
    {
        two = arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    if (one == two)
    {
        cout << "Already Sorted";
        cout << endl;
    }
    else
    {
        bool played = PlaySound(TEXT("Mouse Click - Sound Effect (HD).wav"), NULL, SND_SYNC);
    }

    Sleep(1000);
    /**/

    delete[] left;
    delete[] right;
}

int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;

    int * arr = new int[n];
    cout << "Enter your " << n << " integers" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    return 0;
}
