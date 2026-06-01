#include <bits/stdc++.h>
using namespace std;

int main(){

  list<int> l;
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) l.push_back(i);

  auto it = l.begin(); 
  
  while(l.size() > 0){
    // Move to next element (wrap if needed)
    it++;
    if (it == l.end()) it = l.begin();

    cout << *it << " ";

    // Erase and move iterator to the returned position
    it = l.erase(it);
    if (it == l.end()) it = l.begin();

  }

}