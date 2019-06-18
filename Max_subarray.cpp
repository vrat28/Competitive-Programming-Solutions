#include<iostream>
#include <vector>

using namespace std;

int maxSubArray(vector <int >& nums) {
        int size = nums.size();
        vector <long long > dp (size,0);

        long long answer = -INT_MAX;

        for (int i  = 0 ; i < size; i++){

            dp[i + 1] = nums[i];
            dp[i + 1] = max(dp[i+1], nums[i] + dp[i]);
            answer = max(dp[i+1],answer);
        }

        return answer;
    }

int main(){

    vector<int> vector;
    maxSubArray(vector);
    return 0;
}