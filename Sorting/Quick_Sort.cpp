#include<iostream>
#include<vector>
using namespace std;

int part_func_Index(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i= low;
    int j = high;

    while (i<j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }

        if(i<j){
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = part_func_Index(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main(){
    vector<int> arr = {9, 1, 4, 5, 2, 7, 12};
    quickSort(arr, 0, arr.size() - 1);

    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
