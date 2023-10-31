#include <iostream>

using namespace std;

int partition(char * a, int low, int high){
    int i = low - 1; 
    int pivot = high; 
    for(int j = low; j <= high - 1; ++j){ 
        if(a[j] < a[pivot]){ 
            i++; 
            swap(a[i], a[j]); 
        }
    }
    swap(a[i + 1], a[pivot]);
    return i + 1; 
}


void qsort(char * a, int low, int high){ 
    if(low < high){ 
        int pivot = partition(a, low, high); 
        qsort(a, low, pivot - 1);
        qsort(a, pivot + 1, high); 
    }
}

int main(){
    string s;
    cin >> s;
    char a[10000];
    char b[10000];

    int j = 0, k = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            a[j] = s[i];
            j++;
        } else{
            b[k] = s[i];
            k++;
        }
    }

    qsort(a, 0, j);
    qsort(b, 0, k);
    
    for(int i = 1; i < j + 1; i++){
        cout << a[i];
    }
    for(int i = 1; i < k + 1; i++){
        cout << b[i];
    }

    return 0;
}