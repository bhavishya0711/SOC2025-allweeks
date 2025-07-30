#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bubbleSort(vector<int>& nums) {
        for(int i=nums.size()-1; i>=0; i--){
            for(int j=nums.size()-1; j>0; j--){
                if(nums[j]< nums[j-1]){
                    swap(nums[j-1], nums[j]);
                }
            }
        }
        return nums;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int> sorted = bubbleSort(arr);
    for(auto i : sorted){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
