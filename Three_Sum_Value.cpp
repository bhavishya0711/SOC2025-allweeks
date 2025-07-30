#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> triplet(int n,int k, vector<int> &num){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third = k-(num[i] + num[j]);
            if (hashset.find(third) != hashset.end()){
                vector<int> temp = {num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    if(ans.empty()){
        cout << "IMPOSSIBLE" << endl;
    }
    return ans;

}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    vector<vector<int>> res = triplet(vec.size(),k, vec);

    for (auto trip : res) {
        for (int num : trip) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}
