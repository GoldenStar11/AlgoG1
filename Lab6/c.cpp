#include <bits/stdc++.h>

using namespace std;

int partition(int * a, int low, int high){
    int i = low - 1; // -1
    int pivot = high;
    for(int j = low; j <= high - 1; j++){
        if(a[j] < a[pivot]){
            i++; // 0
            swap(a[i], a[j]);
        }
    }   
    swap(a[i + 1], a[pivot]); 
    return i + 1;
} 

void qsort(int * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high); 
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }    

    qsort(a, 0, n-1);
    // 1 4 7 9 10
    //def = 3
    int def = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        if(def > a[i+1] - a[i]){
            def = a[i+1] - a[i];
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(def == a[i+1] - a[i]){
            cout << a[i] << ' ' << a[i+1] << endl;
        }
    }
}