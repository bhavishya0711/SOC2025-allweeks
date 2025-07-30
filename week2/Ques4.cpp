#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements outside the window
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();

            // Remove smaller elements (they won't be needed)
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            dq.push_back(i);

            // Start pushing max after the first k-1 elements
            if (i >= k - 1)
                res.push_back(nums[dq.front()]);
        }

        return res;
    }

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);
    
    for (int num : result){
        cout << num <<  " ";
    }
    cout << endl;
    return 0;
}
