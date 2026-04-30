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

    //shop is opened six days a week, except Sunday
    int full_weeks = S / 7;
    int remaining_days = S % 7;
    int total_days_shop_open = full_weeks * 6 + remaining_days;

    //Monday -> day 1
    //Sunday -> day 7 -it automatically gets counted as missing as remainder of days can come till 6, Sunday is counted in full_weeks

    if(min_days_buy <= total_days_shop_open) 
        cout << "Minimum number of day on which Jarif needs to buy food: " << min_days_buy << endl;
    else 
        cout << "Jarif does not survive"; 

}