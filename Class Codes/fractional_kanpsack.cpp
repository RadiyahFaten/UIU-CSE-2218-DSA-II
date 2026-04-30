#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Item{


public:

    double profit;
    double weight;

};

bool comp(Item i1, Item i2){
    double unit_i1 =i1.profit/i1.weight;
    double unit_i2 =i2.profit/i2.weight;

 return unit_i1>unit_i2;
 }


int main(){


vector<double> weights = { 30,20,10};

vector<double> profits = { 120,100,60 };

int max_cap = 50;

vector<Item> items;

for(int i =0;i<weights.size();i++){

    Item item;

    item.weight= weights[i];
    item.profit= profits[i];
    items.push_back(item);



}


sort(items.begin(),items.end(),comp);

double max_profit=0;

for(Item item: items)


{
    //Wcout<< i.profit<<" " << i.weight<<endl;
    if(item.weight<=max_cap){

        //we can take the whole item
        max_cap-=item.weight;
        max_profit+=item.profit;
    }
    else{
       max_profit+=    max_cap*(item.profit/item.weight);
       max_cap=0;
       break;
    }

//    if(max_cap==0){
//    break;
//}
}

cout<<"max profit: "<<max_profit<<endl;

}
