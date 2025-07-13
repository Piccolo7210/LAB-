#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int first, int mid, int end) {
    int n1 = mid - first + 1;
    int n2 = end - mid;
    
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    
    for(int i = 0; i < n1; i++) {
        L[i] = arr[first + i];	
    }
    for(int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];	
    }
    
    L[n1] = 20000;  // Sentinel value
    R[n2] = 30000;  // Sentinel value
    
    int m = 0;
    int n = 0;
    int k = first;
    
    for(; m < n1 && n < n2; k++) {
        if(L[m] < R[n]) {
            arr[k] = L[m];
            m++;
        }	
        else {
            arr[k] = R[n];
            n++;		
        }
    }
    
    for(; m < n1; m++) {
        arr[k] = L[m];
        k++;	
    }
    for(; n < n2; n++) {
        arr[k] = R[n];
        k++;
    }
}

void mergesort(vector<int>& arr, int first, int end) {
    if(first < end) {
        int mid = (first + end) / 2;
        mergesort(arr, first, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, first, mid, end);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> array(n);
    for(int i = 0; i < n; i++) {	
        cin >> array[i];
    }	
    
    mergesort(array, 0, n - 1);
    
    for(int i = 0; i < n; i++) {	
        cout << array[i] << " ";
    }
    cout << endl;
    
    return 0;
}