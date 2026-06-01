#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        stack<char> st;

        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push('(');
            
            if(s[i]==')' && st.size()==0) cnt++;
            else if(s[i]==')' && st.top()=='(') st.pop();

            
        }

        cout<<cnt<<endl;
    }

}