#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

bool comp(pair<int, int> s1, pair<int, int> s2){
    return s1.second<s2.second;
}

int main(){
    int n;
    long long s;
    cin >> n >> s;

    vector<pair<long long, int>> vec(n);
    for(int i=0; i<n; i++){
        cin >> vec[i].first;
        vec[i].second = i+1;
    }

    sort(vec.begin(), vec.end());
    for(int i=0; i<n-2; i++){
        if(i>0 && vec[i].first == vec[i-1].first) continue;
        int j=i+1;
        int k=n-1;

        while(j<k){
            int sum = vec[i].first + vec[j].first + vec[k].first;
            if(sum < s){
                j++;
            }
            else if(sum > s){
                k--;
            }
            else {
                vector<pair<long long,int>> temp = {vec[i], vec[j], vec[k]};
                sort(temp.begin(), temp.end(), comp);
                for (auto &p : temp){
                    cout << p.second << " ";
                }
                return 0;
            }
        }
        
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
