#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    
    vector<int> ppos;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            ppos.push_back(i+1);
        }
    }

    for(int i=1;i<=n;i++) {
        if(i<=ppos.size()) cout<<ppos[i-1]<<endl;
        else cout<<n<<endl;
    }


}