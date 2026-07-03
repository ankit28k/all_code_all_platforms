#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;

    list<int> ll;
    for(int i=1;i<=n;i++) ll.push_back(i);

    auto it = ll.begin();
    vector<int> ans;

    while(!ll.empty()){

        int d = k%ll.size(); // avoiding the repeating cyclic movement....1->2...->4 ...1->2->3->4...1->2->3......just dop 1->2->3
        for(int i=0;i<d;i++){
            if(it==ll.end()) it = ll.begin();
            it++;
        }
        
        if(it == ll.end()) it = ll.begin();
        
        ans.push_back(*it);

        it = ll.erase(it);
        if(ll.empty()) break;
        if(it == ll.end()) it = ll.begin(); 
    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;


}