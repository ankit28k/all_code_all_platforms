#include<bits/stdc++.h>
using namespace std;

int fun(string s,char c,int n){

    if(c=='g') return 0;

    string s2 = s+s;

    int firstgidx = s.find('g');
    int k  = firstgidx + n; // first g index in appended string

    vector<int> rdg(n);
    int temp =-1;
    for(int i=k;i>=0;i--){ 
        if(s2[i]=='g') {
            temp =i;
            if(i<n)rdg[i] =0;
        }
        
        else if(s2[i] != 'g' && temp !=-1 && i<n)rdg[i] = temp - i;
        
    }

    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        if(s[i]==c) ans = max(ans,rdg[i]);
    }

    return ans;
    // unordered_set<int> st;

    // for(int i=0;i<n;i++){
    //     if(s[i]==c) st.insert(i);
    // }

    // int ans = INT_MIN;

    // for(int x:st){
    //     int i=x+1;
    //     while(s2[i] != 'g') i++;
    //     ans = max(ans,abs(i-x));
    // }

    // return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s; 
        cout<<fun(s,c,n)<<endl;
    }

}