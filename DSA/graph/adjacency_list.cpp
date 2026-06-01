#include <bits/stdc++.h>
using namespace std;


void printgraph(unordered_map<int , vector<int>> graph){

  for(auto x:graph){
    cout<<"node: "<<x.first<<" neighbours: ";

    for(auto node : x.second){

       cout<<node<<" ";

    }
    cout<<endl; 
  }

}
 



int main(){
  vector<vector<int>> edgelist = { {1,2} , {2,3}, {3,4} , {4,2}, {1,3}};

 

  int nodes = 0;
  for (auto edge : edgelist) {
      nodes = max({nodes, edge[0], edge[1]});
  }
  
  // Initialize adjacencyMatrix to (maxNode+1)x(maxNode+1) with zeros
  unordered_map<int , vector<int>> graph;

  for(int i=0;i<edgelist.size();i++){
    
    int a = edgelist[i][0] ,b = edgelist[i][1];

    graph[a].push_back(b);
    graph[b].push_back(a) ;


  }

  printgraph(graph);

   
}