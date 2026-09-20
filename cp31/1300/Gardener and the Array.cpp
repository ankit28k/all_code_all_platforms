#include<bits/stdc++.h>
using namespace std;

string fun(map<int,int>& bits,int n,map<int,vector<int>>& mp){

    set<int> st;
    for(auto it:bits){
        if(it.second==1) {
            for(int x:mp[it.first]){
                st.insert(x);
            }
        }
    }
    if(st.size()>=n) return "No";
    return "Yes";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        
        //vector<int> bits(31,0); ...as bits can go upto 1e5
        map<int,vector<int>> mp;
        map<int,int> bits;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int bit;
                cin>>bit;
                bits[bit]++;
                mp[bit].push_back(i);
            }
        }

        cout<<fun(bits,n,mp)<<endl;

    }

}