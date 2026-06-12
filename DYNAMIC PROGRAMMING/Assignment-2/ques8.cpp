// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed.
// the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        
        //base case
        if(nums.size() == 0)
            return 0;

        int prev_2 = 0; // max sum the house before the previous house
        int prev_1 = 0; //max sum the previous house

        int current; //current house decision

        for(int n: nums) {

            current = max(prev_2 + n, prev_1); //choose non adjacently
            prev_2 = prev_1; //the previous house becomes the house before previous
            prev_1 = current; //current house becomes previous
        }    

        return prev_1;
    }
};