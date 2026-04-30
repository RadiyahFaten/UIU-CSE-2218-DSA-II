#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int weight;
    int value;
    float ratio;
};

bool compareRatio(Item item1, Item item2)
{
    return item1.ratio > item2.ratio;
}

int main()
{

    vector<int> weights = {30, 20, 10};
    vector<int> values = {120, 100, 60};

    int capacity = 50;

    // 2D array to store items
    vector<Item> items;

    for (int i = 0; i < weights.size(); i++)
    {
        // each item store
        Item item;

        item.weight = weights[i];
        item.value = values[i];
        item.ratio = values[i] / weights[i];

        items.push_back(item);
    }

    // sort by ratio
    sort(items.begin(), items.end(), compareRatio);

    // calculate max profit

    int max_profit = 0;

    for (Item item : items)
    {
        if (item.weight <= capacity)
        {
            capacity -= item.weight;
            max_profit += item.value;
        }
        else
        {
            max_profit += (item.value / item.weight) * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum profit= " << max_profit << endl;
}