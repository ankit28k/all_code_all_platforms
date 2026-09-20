#include<bits/stdc++.h>
using namespace std;

vector<int> fun(){

}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long l=0,h=0;
    for(int i=0;i<n;i++){
        l = max(l,arr[i]);
        h += arr[i];
    }
    long long ans = l;

    while(l<=h){
        long long mid = l+(h-l)/2;
        
    }


}