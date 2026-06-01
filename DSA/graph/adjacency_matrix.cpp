#include <bits/stdc++.h>
using namespace std;


void printgraph(vector<vector<int>> adjacencyMatrix){

  for(int i=1;i<adjacencyMatrix.size();i++){
    cout<<"node:"<<i<<"neighbours:";

    for(int j=1;j<adjacencyMatrix[0].size();j++){

      if(adjacencyMatrix[i][j]==1) cout<<j<<" ";

    }
    cout<<endl;
  }

}


int main(){
  vector<vector<int>> edgelist = { {1,2} , {2,3}, {3,4} , {4,2}, {1,3}};

  int nodes = 0;
  for (auto edge : edgelist) {
      nodes = max({nodes , edge[0], edge[1]});
  }
  

  // Initialize adjacencyMatrix to (maxNode+1)x(maxNode+1) with zeros
  vector<vector<int>> adjacencyMatrix(nodes + 1, vector<int>(nodes + 1, 0));

  for(int i=0;i<edgelist.size();i++){
    
    int a = edgelist[i][0] ,b = edgelist[i][1];

    adjacencyMatrix[a][b] = 1;
    adjacencyMatrix[b][a] = 1;


  }

  printgraph(adjacencyMatrix);
}