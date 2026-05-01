#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;

    vector<double> products(N);
    for (int i = 0; i < N; i++)
    {
        cin >> products[i];
    }
    sort(products.begin(), products.end(), greater<double>());

    double sum = 0;
    for (int i = 0; i < K; i++)
    {
        sum += products[i] * 0.7;
    }
    for(int i = K; i < N; i++) {
        sum += products[i];
    }

    cout << sum;
}