#include<bits/stdc++.h>
using namespace std;


//precomputation ....making this O(n + m^2logm) rather O(n^2 logn)....where m is max value...ie 1000

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        vector<int> indexes(1000+1,-1);  //as 1<= arr[i] <=1000 
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            indexes[x] =i; // automatically stores the last index of a number 
        }
 

        int ans = -1; 
        for(int i=1;i<=1000;i++){

            if(indexes[i] == -1) continue;

            for(int j=i;j<=1000;j++){
                if(indexes[j] != -1 && gcd(i,j)==1) ans = max(ans,indexes[i]+ indexes[j]);
            }
        }

        cout<<ans<<endl;
    }

}