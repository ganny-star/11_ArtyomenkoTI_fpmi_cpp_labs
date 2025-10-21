#include <bits/stdc++.h>

std::mt19937 gen(14881488);
std::uniform_int_distribution<int> dist(-100, 100);

void MatrixPrint(int** p, int& n, int& m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) std::cout << p[i][j] << ' ';
        std::cout << std::endl;
    }
}


void RandomFilling(int** p, int& n, int& m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        p[i][j] = dist(gen);
    }
}

void BubbleSort(int** arr,int large,int str) {
    for(int i = 1; i < large; i++) {
        if(arr[str][i] < arr[str][i-1]) {
            int c = arr[str][i-1];
            arr[str][i-1] = arr[str][i];
            arr[str][i] = c;
        }

    }
    if(large >= 2) {
        BubbleSort(arr, large - 1, str);
    }
    else return;
}

void InsertSort(int** arr,int large,int str) {
    for(int i = 1; i < large; i++) {
        int key = arr[str][i];
        int j = i - 1;

        while(arr[str][j] > key && j >= 0) {
            arr[str][j+1] = arr[str][j];
            j -= 1;
        }

        arr[str][j+1] = key;
    }
}

void merge(int** a, int left, int mid, int right, int str, int* temp)
{
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[str][i];
            i++;
        }
        else
        {
            temp[k] = a[str][j];
            j++;
        }
        k++;
    }
    while(i < mid)
    {
        temp[k] = a[str][i];
        i++;
        k++;
    }
    while(j < right)
    {
        temp[k] = a[str][j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        a[str][t] = temp[t];

}

void MergeSort(int** a, int left, int right, int str, int* temp)
{
    if(right - left <= 1) return;

    int mid = (left + right) / 2;

    MergeSort(a, left, mid, str, temp);
    MergeSort(a, mid, right, str, temp);

    merge(a, left, mid, right, str, temp);
}


int main()
{
    int tmp[1000];
    int n, l;
    std::cout << "Write n and l to matrix N*L: " << std::endl;
    std::cin >> n >> l;

    int** matrix = new int* [n];
    for(int i = 0; i < n; i++) {
        matrix[i] = new int[l];
    }

    RandomFilling(matrix, n, l);
    std::cout << "Matrix rand elements:" << std::endl;
    MatrixPrint(matrix, n, l);

    for(int i = 0; i < n; i++) {
        MergeSort(matrix, 0, l, i, tmp);
    }

    std::cout << std::endl;
    std::cout << "Sorted matrix:" << std::endl;
    MatrixPrint(matrix, n, l);

    return 0;
}
