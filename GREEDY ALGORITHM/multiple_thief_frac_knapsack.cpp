#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Item
{
    string name;
    double weight;
    double price;
    double unitPrice;
};

bool compareUnitPrice(Item a, Item b)
{
    return a.unitPrice > b.unitPrice;
}

int main()
{

    vector<Item> items = {
        {"Rice", 12, 840, 840.0 / 12},
        {"Salt", 10, 870, 870.0 / 10},
        {"Saffron", 8, 2000, 2000.0 / 8},
        {"Sugar", 5, 500, 500.0 / 5}};

    // sort unitPrice in descending order
    sort(items.begin(), items.end(), compareUnitPrice);

    double total_weight = 0;

    for (Item item : items)
    {
        total_weight += item.weight;
    }

    int total_thief = ceil(total_weight / 9.0);

    cout << "Total number of thiefs required: " << total_thief << endl;

    for (int i = 1; i <= total_thief; i++)
    {

        double capacity = 9;
        double profit = 0;

        cout << "Thief " << i << " carries: " << endl;

        // check if one thief's capacity filled or all items are taken
        while (capacity > 0 && !items.empty())
        {

            // when full item taken
            if (items[0].weight <= capacity)
            {
                capacity -= items[0].weight;
                profit += items[0].price;

                cout << items[0].weight << " kg " << items[0].name << endl;

                // take the whole item, remove item
                items.erase(items.begin());
            }

            // when take fraction
            else
            {
                profit += capacity * items[0].unitPrice;

                cout << capacity << " kg " << items[0].name << endl;

                // update the remaining weight and price for next theif
                items[0].weight -= capacity;
                items[0].price -= capacity * items[0].unitPrice;

                // after taking fraction, capacity is filled
                capacity = 0;
            }
        }

        cout << "Total profit of thief " << i << " = " << profit << endl;
    }
}