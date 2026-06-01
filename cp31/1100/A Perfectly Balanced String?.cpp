#include<bits/stdc++.h>
using namespace std;

// bool check(string& s,int i){
    
//     return s[i]==s[i+1] || s[i]==s[i+2] || s[i+1]==s[i+2];
// }

string fun(string& s){

    int n = s.length();

    unordered_set<char> st;

    for(int i=0;i<n;i++) st.insert(s[i]);
    int unique = st.size();

    if(unique == 1) return "YES";
    
    //now for sliding window of size k it must have k distinct characters....if less...like -> s = abcdbcd 
    // k=4 and t = dbcd....it wont make if u=a,v=d...as 
    int k=unique; 

    unordered_map<char,int> m;
    int l=0,r=0;

    while(r-l+1 <k){
        m[s[r]]++;
        if(m[s[r]] > 1) return "NO";
        r++;
    }

    while(r<n){

        m[s[r]]++;
        
        if(m[s[r]] > 1) return "NO";

        m[s[l]]--;
        l++;
        r++;

    }

    return "YES"; 

    //fails as ex - abcdbcd....substring dbcd ....Frequency of d = 2....Frequency of a = 0.
    // for(int i=0;i<n-1;i++){

    //     if(unique>=3 && i<n-2){
    //         if(check(s,i)) return "NO";
    //     }

    //     if(s[i]==s[i+1]) return "NO";
    // }

    // return "YES";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        cout<<fun(s)<<"\n";
        
    }

}