#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
 
int partition(int arr[], int startIndex, int endIndex)
{
    // select the last element as a pivot from the array
    int pivot = arr[endIndex];
 
    // elements smaller than the pivot element goes to the left of `pivotIndex`
    // elements greater than the pivot element goes to the right of `pivotIndex`
    // equal elements can go on either side of the pivotIndex
    int pivotIndex = startIndex;
 
    // if an element is less than or equal to the pivot, we will increase the 'pivotIndex' and we will place that element before the pivot.
    for (int i = startIndex; i < endIndex; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pivotIndex]);
            pivotIndex++;
        }
    }
 
    // swap `pivotIndex` with pivot element
    swap (arr[pivotIndex], arr[endIndex]);
 
    return pivotIndex;
}
 
void Quicksort(int arr[], int n)
{
    //stack for storing start and end Index of the subarrays
    stack<pair<int, int>> s; 

    //starting index of the given array
    int startIdx = 0; 
    //ending index of the given array
    int endIdx = n - 1; 
    
    //pushing the start and end index of the array into the stack
    s.push({startIdx, endIdx});  
 
    while (!s.empty())
    {
        // removing the top pair from the array and get the starting
        // and ending index of the subarray
        startIdx = s.top().first;
        endIdx = s.top().second;
        s.pop();
 
        // partitioning the elements around pivot
        int pivotIdx = partition(arr, startIdx, endIdx);
 
        //push subarray indices to stack which has elements smaller than the current pivot
        if (pivotIdx - 1 > startIdx) {
            s.push({startIdx, pivotIdx - 1});
        }
        
        //push subarray indices to stack which has elements greater than the current pivot
        if (pivotIdx + 1 < endIdx) {
            s.push({pivotIdx + 1, endIdx});
        }
    }
}
 
int main()
{
    
    int n; //size of the array
    cin>>n;

    int arr[n]; //arr is the array to be sorted
    
    cout<<"Enter the elements of the array to be sorted:"<<endl;
    
    for(int i=0;i < n;i++){
        cin>>arr[i];
    }
 
    Quicksort(arr, n);
 
    // print the sorted array
    
    cout<<"Sorted array:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}
