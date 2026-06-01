#include<bits/stdc++.h>
using namespace std; 

long long fun(string& s,int n){

    if(n==1){
        if(s[0]=='1') return 1;
        else return 0;
    }

    int temp=0 , maxi =0;

    for(int i=0;i<n;i++){
        if(s[i] =='1') temp++;
        else{
            maxi = max(maxi,temp);
            temp=0;
        }
    }
    
    maxi = max(maxi,temp);

    if(maxi == n) return 1LL*n*n; // if all 1 return n^2 ...as maxi incraeses to 2n in next step

    int i=0,j=n-1 , lc=0,rc=0;
    
    while(j>=0 && s[j] == '1') { // Check constraints to avoid out of bounds
        rc++;
        j--;
    }

    while(i<n && s[i]=='1') {
        lc++;
        i++;
    }

    // while(s[j--] == '1') rc++; 
    // while(s[i++]=='1') lc++;
 
    maxi = max(maxi,lc+rc);

    long long ans =0;
    for(int i=0;i<maxi;i++){
        long long k = 1LL*(i+1)*(maxi-i);
        ans = max(ans,k);
    }

    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int n = s.length();
 
        cout<<fun(s,n)<<endl;
    }

}