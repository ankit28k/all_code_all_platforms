#include<bits/stdc++.h>
using namespace std;

int fun(string& s,int n){

    if(n==1) return 1;
    if(n==2 ){

        if(s == "00" || s == "01" || s == "10") return 1; 
        else if(s == "11") return 2;
    }

    int cnt=0,temp=1;

    for(int i=0;i<n;i++){
        if(s[i]=='0') {
            temp++;
            if(temp>=3){
                cnt++;
                temp=0;
            }
        }
        else {
            temp=0;
            cnt++;
        }
    }
    if(temp == 2) cnt++;

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
        cout<<fun(s,n)<<endl;
    }

}