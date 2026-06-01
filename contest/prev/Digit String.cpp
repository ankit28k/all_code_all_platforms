#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string st;
        cin>>st;

        int n = st.length() , cnt=0;
        string s="";
        for(int i=0;i<n;i++){
            if(st[i]=='4') cnt++;
            else s.push_back(st[i]);
        }
        
        int k2 = 0, k13 = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '2') k2++;
            else k13 = max(k13, k2) + 1;
        }
        
        cnt += (s.length() - max(k2, k13));

        cout<<cnt<<endl;
    }

}