#include<bits/stdc++.h>
using namespace std;

int fun(vector<long long>& arr,int n,long long k,long long x){

    vector<long long> gaps;
    
    for(int i=1;i<n;i++){
        if(arr[i] - arr[i-1] >x) gaps.push_back(arr[i] - arr[i-1]);
    }
    
    sort(gaps.begin(),gaps.end());
    
    long long gn = gaps.size() , i=0;
    long long maxgroup = gn + 1;

    while( i<gn ){
        if(k<=0) break;
        else{
            if(x==1 ) {
                k-= gaps[i] - 1;
                if(k>=0) i++;
                else break;
                
            }
            else  {
                
                if(gaps[i]%x == 0) k -= gaps[i]/x -1;
                else k-= gaps[i]/x;

                if(k>=0) i++;
                else break;
                
            }
        }
        
    }
    
    if(i==gn) return 1;
    return maxgroup-i;

}

int main(){
    
    long long n,k,x;
    cin>>n>>k>>x;
    vector<long long> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr.begin(),arr.end());
 
    cout<<fun(arr,n,k,x)<<endl;

}