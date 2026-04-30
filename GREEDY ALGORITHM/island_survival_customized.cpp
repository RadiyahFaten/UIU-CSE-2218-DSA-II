/* Jarif got stuck on an island. There is only one shop on this island, and it is open on all
days of the week except for Thursday and Monday. Consider following constraints: ​

N – The maximum unit of food you can buy each day. ​

S – Number of days you are required to survive. ​

M – Unit of food required each day to survive. ​

Currently, it’s Saturday, and he needs to survive for the next ‘S’ days. ​

Find the minimum number of days on which you need to buy food from the shop so that
he can survive the next ‘S’ days or determine that it isn’t possible to survive. ​

Example 1: ​

Input: N = 16, S = 10, M = 2 ​

Output: 2 */


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    // N -> Maximum unit of food you can buy each day
    // S -> Total number of days to survive
    // M -> Unit of food required each day
    int N, S, M;
    cout << "Maximum unit of food you can buy each day: ";
    cin >> N;
    cout << "Total number of days to survive: ";
    cin >> S;
    cout << "Unit of food required each day: ";
    cin >> M;

    //calculate the minimum number of days need shopping to survive
    int min_days_buy = ceil((double) (M * S) / N);

    //calculate available days to shop

    //calculate full weeks completed in S days
    int full_weeks = S / 7;

    //remaining days after full weeks
    int remaining_days = S % 7;

    //total number of days shop open in a week = 7 - 2 = 5
    int total_days_shop_open = full_weeks * 5;

    //Saturday -> day 1
    //Monday -> day 3
    //Thursday ->day 6

    //include the remaining days of the S in the total shop day count
    for(int i = 1; i <= remaining_days; i++) {
        if((i != 3 && i != 6)) total_days_shop_open++;
    }

    //finally, check survival

    if(min_days_buy <= total_days_shop_open) 
        cout << "Minimum number of day on which Jarif needs to buy food: " << min_days_buy << endl;
    else 
        cout << "Jarif does not survive";    





    
}