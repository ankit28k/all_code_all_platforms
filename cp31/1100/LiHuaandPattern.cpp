#include<bits/stdc++.h>
using namespace std;

string fun(vector<vector<int>>& arr,int n,int k){

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(arr[i][j]!=arr[n-i-1][n-j-1]) cnt++;
        }
    }

    //due to double counting ....It checks cell A against cell B. If they don't match, cnt increases.
    //Later in the loop, it checks cell B against cell A. cnt increases again.
    cnt = cnt/2;

    //exactly k operations
    if(k<cnt) return "NO";

    if((k-cnt)%2 == 0) return "YES";

    //as we makes changes first then rotate/compare...if n is odd ...the centre holds its position..so if diff is odd it works for that point
    if(n%2==1) return "YES";

    return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(n,vector<int>(n)) ;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                cin>>arr[i][j];
            }
        }

        cout<<fun(arr,n,k)<<endl;
        
    }

}