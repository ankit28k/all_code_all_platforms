#include<bits/stdc++.h>
using namespace std;

int removecheck(string s,char c,int n){

    int i=0,j=n-1;
    int cnt=0;
    // string ans=""; // no need of this...its just extra work

    while(i<j){

        if(s[i]==s[j]){
            i++;
            j--;
        }

        else{

            if(s[i] == c){
                // s[i]='?';
                i++;
                cnt++;
            }

            else if(s[j] == c){
                //s[j]='?';
                j--;
                cnt++;
            }

            else return -1;
        }
    }

    // for(int i=0;i<n;i++){
    //     if(s[i] != '?') ans.push_back(s[i]);
    // }
    
    // for(int i=0,j=ans.length()-1;i<j;i++,j--){
    //     if(ans[i] != ans[j]) return -1;
    // }

    return cnt;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        set<char> st;
        for(int i=0;i<n;i++) st.insert(s[i]);

        int ans=INT_MAX;
        for(char c:st){
            int k = removecheck(s,c,n);
            if( k < ans && k !=-1){
                ans = k;
            }
        }
        
        if(ans != INT_MAX) cout<<ans<<endl;
        else cout<<-1<<endl;
    }

}