#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cout << "Size of an array: ";
    cin >> N;

    int M;
    cout << "Number of students: ";
    cin >> M;

    vector<int> chocolates(N);

    for(int i = 0; i < N; i++) {
        cin >> chocolates[i];
    }

    sort(chocolates.begin(), chocolates.end());

    //The difference between maximum number of chocolates given to a student 
    //and minimum number of chocolates given to a student is minimum.

    int min_difference = INT_MAX;
    for(int i = 0; i <= N - M; i++) {
        int difference = chocolates[(i + M) - 1]- chocolates[i];
        min_difference = min(difference, min_difference);
    }

     cout << min_difference << endl;
    


}