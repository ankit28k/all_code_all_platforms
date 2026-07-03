#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    list<int> ll;
    for(int i=1;i<=n;i++) ll.push_back(i);

    auto it = ll.begin();
    vector<int> ans;

    while(!ll.empty()){

        it++;
        
        if(it == ll.end()) it = ll.begin();
        
        ans.push_back(*it);

        it = ll.erase(it);

        // If the last remaining child was erased, the list becomes empty.
        // erase() returns end(), and incrementing/using end() later is invalid.
        if(ll.empty()) break;

        // as it = ll.erase(it) can return ll.end() when the erased node was the last node 
        //In the next iteration we do it++; on end(), which is invalid. So you must wrap it back to begin().
        if(it == ll.end()) it = ll.begin(); 
    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;


}