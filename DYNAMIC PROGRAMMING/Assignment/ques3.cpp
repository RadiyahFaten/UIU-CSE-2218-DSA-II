// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();

        vector<int> dp(n + 1, 0);   
        vector<int> passes ={1, 7, 30};

        //base case- when there are no more days left
        dp[n] = 0;

        //min cost counts start

        for(int i = n - 1; i >=0; i--) {

            dp[i] = INT_MAX;

            //check for each day pass
            for(int j = 0; j < 3; j++) {

                //find the covered and uncovered days with passes
                int k = i;
                while(k < n && days[k] < days[i] + passes[j])
                    k++;

                dp[i] = min(dp[i], dp[k] + costs[j]);
            }
        }
        return dp[0];

    }    
    
};