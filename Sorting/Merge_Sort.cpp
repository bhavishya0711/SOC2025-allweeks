#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> vec;
    int low = left;
    int high = mid + 1;

    while(low <= mid && high <= right){
        if(arr[low] < arr[high]){
            vec.push_back(arr[low]);
            low++;
        }
        else {
            vec.push_back(arr[high]);
            high++;
       }
    }
    while(low <= mid){
        vec.push_back(arr[low]);
        low++;
    }
    while(high <= right){
        vec.push_back(arr[high]);
        high++;
    }

    for(int i=left; i<=right; i++){
        arr[i] = vec[i-left];
    }
}

void mergeSort(vector<int> &arr, int left, int right){     
    if(left == right) return ; 
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
}

int main(){
    vector<int> arr = {9, 1, 4, 5, 2, 7, 12};
    mergeSort(arr, 0, arr.size() - 1);

    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
