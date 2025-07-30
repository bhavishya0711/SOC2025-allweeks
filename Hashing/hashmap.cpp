#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        mpp[arr[i]]++;
    }

//     for(auto x : mpp){
//         cout << x.first << "->" << x.second << endl;
//     }
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for(auto x : mpp){
        int count = x.second;
        int element = x.first;

        if(count > maxFreq){
            maxFreq = count;
            maxEle = element;
        }
        if(count < minFreq){
            minFreq = count;
            minEle = element;
        }
    }
    cout << maxEle << " " << minEle << "\n";
}
