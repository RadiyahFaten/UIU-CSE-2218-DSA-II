#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int diamond, stick;
    cout << "Enter the number of diamonds: ";
    cin >> diamond;

    cout << "Enter the number of sticks: ";
    cin >> stick;

    int answer = min(min(diamond, stick), (diamond + stick) / 3);

    // Each tool = 1 dollar
    cout << "Polycorp makes: " << answer << " tools" << endl;
    cout << "Polycarp earns: " << answer << "$";
}