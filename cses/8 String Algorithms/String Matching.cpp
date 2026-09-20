#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,str;
    cin>>s>>str;

    int n = s.length() , m = str.length();

    vector<int> lps(m);
    lps[0]=0;
    int i=1,len=0;
    while(i<m){
        if(str[i]==str[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len != 0) len = lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }

    int j=0,cnt=0;
    i=0;
    while(i<n){
        if(s[i]==str[j]){
            i++;
            j++;
        }

        if(j==m) {
            cnt++;
            j=lps[j-1];
        }
        else if(s[i] != str[j]){
            if(j!=0) j = lps[j-1];
            else i++;
        }

    }

    cout<<cnt<<endl;

}