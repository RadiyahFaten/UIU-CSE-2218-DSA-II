#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Find(int x, int parent[]){

if(parent[x]==-1){
    return x;
}

return Find(parent[x],parent);
}

void Union(int u,int v, int parent[], int Rank[]){

int rootU = Find(u,parent);
int rootV = Find(v,parent);

if(Rank[rootU]>Rank[rootV]){
   parent[rootV]=rootU;
   Rank[rootU]+=rootV;
}

else{

    parent[rootU]=rootV;
   Rank[rootV]+=rootU;

}



}

int main(){

int V, E;

// graph as adjacency list

vector<vector<int>>edgeList;
cout<<"Enter vertex and edge number"<<endl;
cin>>V>>E;

for(int i=0;i<E;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edgeList.push_back({w,u,v});
}


//sort the edges by their weights

sort(edgeList.begin(),edgeList.end());

int parent[V] , Rank[V];


//initilize parent and rank

for(int i=0;i<V;i++){
    parent[i]=-1;
    Rank[i]=1;
}

int minCost = 0 , cnt= 0;

//now we will try to include edge one by one

for(auto edge:edgeList){


    int w = edge[0];
    int u = edge[1];
    int v = edge[2];

    if(Find(u,parent)!=Find(v,parent)){

        Union(u,v,parent,Rank);
        minCost+=w;
        cnt+=1;
        cout<<u<<" "<<v<<endl;
    }

    if(cnt==V-1){
        break;
    }

}
cout<<minCost<<endl;

}
