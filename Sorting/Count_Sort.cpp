#include<iostream>
using namespace std;

void CountSort(int arr[], int n){
    int k = arr[0];
    for(int i=0; i<n; i++){
        k =  max(k, arr[i]);
    }

    int count[10] = {0};
    for(int i=0; i<n; i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k; i++){
        count[i] += count[i-1];
    } 

    int output[n];
    for(int j= n-1; j>=0; j--){
        output[--count[arr[j]]] = arr[j]; 
    }

    for(int i=0; i<k; i++){
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {6, 2, 5, 3, 7, 9, 3, 5};
    CountSort(arr, 8);

    for(int i=0; i<8 ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
