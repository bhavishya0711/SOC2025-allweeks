#include<iostream>
#include<vector>
using namespace std;

vector<int> printRow(int n){
    vector<int> ans;
    long long res = 1;

    for(int i=1; i<=n; i++){
        ans.push_back(res);
        res = res * (n-i);
        res = res / i;
    }
    return ans;
}

vector<vector<int>> printTriangle(int n){
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++){
        vector<int> temp = printRow(i);
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans = printTriangle(n);
    for(auto row : ans){
        for(auto val : row){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
