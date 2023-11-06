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
} // 10 80 50 40 70
// i = 0 a[0] = 10   10 80 50 40 70
// i = 1 a[1] = 50   10 50 80 40 70
// i = 2 a[2] = 40   10 50 40 80 70
// a[3], a[4] ==   10 50 40 70 80  
//                low = 0  high = 3-1 = 2
//               low = pivot + 1 = 4   high = 4
void qsort(int * a, int low, int high){
    if(low < high){
        int pivot = partition(a, low, high); //3
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high);
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[n], b[m];
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    qsort(a, 0, n-1);
    qsort(b, 0, m-1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i] == b[j]){
                v.push_back(b[j]);
                b[j] = 0;
                break;
            }
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
}