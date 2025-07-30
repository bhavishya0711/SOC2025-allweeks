#include<iostream>
#include<vector>
using namespace std;

void printF(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }
        if(ds.empty()) cout << "{}";
        cout << endl;
        return;
    }

    printF(ind + 1, ds, arr, n);

    ds.push_back(arr[ind]);
    printF(ind + 1, ds, arr, n);
    ds.pop_back();

}

int main(){
    // int arr[] = {22, 53, 64};
    // int n = 3;
    // vector<int> ds;
    // printF(0, ds, arr, n);

    vector<int> arr = {0, 0, 1, 2, 2, 2 , 3, 4};
    auto x = upper_bound(arr.begin(), arr.end(), 2);
    auto y = lower_bound(arr.begin(), arr.end(), 2);
    cout << x-arr.begin() <<" " << y-arr.begin();
    return 0;
}
