#include<bits/stdc++.h>
using namespace std;

bool poss(double m,vector<int>& arr,int k,int n){
    
    double temp=0;
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            double val = (arr[i]-m)*(100-k)/100.0;
            temp+=val;
        }
        else if(arr[i]<m){
            double diff = m-arr[i];
            if(temp>=diff) temp-=diff;
            else return false;
        }
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);

    double l=INT_MAX , h = 0;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        h+=arr[i];
        l=min(l,(double)arr[i]);
    }
    
    sort(arr.rbegin(),arr.rend());

    h = h/n;
    double ans =h;
    while(h-l>1e-9){
        double m = l+(h-l)/2;
        if(poss(m,arr,k,n)) {
            ans = m;
            l= m;
        }
        else h=m;
    }


    cout<<fixed<<setprecision(9)<<ans<<endl;

}