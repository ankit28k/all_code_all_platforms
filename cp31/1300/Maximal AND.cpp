#include<bits/stdc++.h>
using namespace std;

int fun(vector<int>& arr,int n,int k){

    int ans =0; 

    for(int i=30;i>=0;i--){

        int cnt =0;
        for(int j=0;j<n;j++){
            if ((arr[j] & (1 << i)) != 0) cnt++;
        }

        int extra = n - cnt;
        if(k>=extra){
            ans += pow(2,i);
            k-= extra;
        }
    }

    // int maxbit =0;
    // for(int i=0;i<n;i++) {
    //     int cbit;
    //     if(arr[i] == 0 ) cbit = 0; //segmentation fault for arr[i] =0
    //     else cbit = log2(arr[i]);

    //     maxbit = max(maxbit,cbit);
    // }

    // if(maxbit<30){ //only if last bits dont add(&) up to 1
    //     int j=0;
    //     while(k>=n && j< 30 - maxbit){
    //         ans += pow(2,30-j);
    //         k -= n;
    //         j++;
    //     }
    // }

    // vector<int> temp(maxbit+1);

    // for(int i=0;i<=maxbit;i++){

    //     int cnt =0;
    //     for(int j=0;j<n;j++){
    //         if ((arr[j] & (1 << i)) != 0) cnt++;
    //     }

    //     temp[i] = cnt;
    // }

    // reverse(temp.begin(),temp.end()); 

    // for(int i=0;i<temp.size();i++){

    //     if(temp[i] >= n) ans += pow(2,maxbit - i);

    //     else{

    //         if(k >= n - temp[i] ){
    //             ans += pow(2, maxbit - i);
    //             k -= n - temp[i] ;
    //         }
    //     }
        
    // }

    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<fun(arr,n,k)<<endl;
    }

}