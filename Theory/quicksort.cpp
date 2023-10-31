#include <iostream>

using namespace std;
// 10 30 40 50 70 90 80    
/*
    pivot = 70
    pivot = 50
    pivot = 40
    pivot = 30
    pivot = 10
    pivot = 80
*/
int partition(int * a, int low, int high){
    int i = low - 1; // i = -1
    int pivot = high; // pivot = 3
    for(int j = low; j <= high - 1; ++j){ // 0 -- 2
        if(a[j] < a[pivot]){ // a[5] = 50 < 70
            i++; // i = 5
            swap(a[i], a[j]); // sw(90,50)
        }
    }
    swap(a[i + 1], a[pivot]); //a[4], a[6] sw(80, 70)
    return i + 1; // i + 1 = 6
}


void qsort(int * a, int low, int high){ // a, 0, 6
    if(low < high){ // 0 < 6
        int pivot = partition(a, low, high);  // part(a,0,6)
        qsort(a, low, pivot - 1); // 0, 3
        qsort(a, pivot + 1, high); // 6, 6
    }
}

int main(){

    int a[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(a)/sizeof(int);

    qsort(a, 0, n - 1);

    for(int i = 0; i < n; ++i){
        cout << a[i] << " ";
    }

    return 0;
}