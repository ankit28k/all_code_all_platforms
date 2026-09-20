#include<bits/stdc++.h>
using namespace std;

pair<double,double> fun(vector<pair<int,int>>& arr,double mid,int n){

    double l=0,r=0;
    for(int i=0;i<n;i++){
        if(arr[i].first>mid){
            r = max(r, arr[i].second + abs(arr[i].first - mid));
        }
        else{
            l = max(l,arr[i].second + abs(arr[i].first - mid));
        }
    }

    return {l,r};
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)  cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;i++) arr[i] = {a[i],b[i]};

        sort(arr.begin(),arr.end());

        double l=arr[0].first,h=arr[n-1].first ,idx=arr[0].first,sum=INT_MAX;
        while(h-l>1e-6) {
            double mid = l+(h-l)/2;
            pair<double,double> temp = fun(arr,mid,n);
            
            if(max(temp.first,temp.second)<sum) {
                idx = mid;
                sum=max(temp.first,temp.second);
            }
            if(temp.first>temp.second) h=mid;
            else l=mid;


            // if(max(temp.first , temp.second) < sum){
            //     sum = temp.first + temp.second;
            //     idx = mid;
            //     if(temp.first>temp.second) h=mid;
            //     else l=mid;
            // }
            // else break;
        }

        cout<<fixed<<setprecision(6)<<idx<<endl;
    }

}