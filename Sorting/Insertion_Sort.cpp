#include<iostream>
using namespace std;

void InsertionSort(vector<int> &arr){
    for(int i=0; i<arr.size()-1; i++){
        int j=i+1;
        while(arr[j] < arr[j-1] && j>0){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

int main(){
    vector<int> arr = {2, 1, 5, 4, 3, 2, 6, 3, 6, 3,7 ,9};
    InsertionSort(arr);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
