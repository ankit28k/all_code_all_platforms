#include<bits/stdc++.h>
using namespace std;

// long long fun(vector<int>& arr,int n){

//     long long ans =0,temp=0;

//     int i=0,j=n-1;
//     while(i<=j){
        
//         if(i==j){
//             if(temp>=arr[i] || arr[i]==1) return ans+temp+1;
//             else {
//                 long long val = (arr[i]-temp+1)/2;
//                 return ans+temp+val+1;
//             }
//         }

//         if(temp>=arr[j]){
//             ans+=temp+1;
//             temp =0;
//             j--;
//             // We 'continue' to restart the loop because the game state just changed.
//             // If we don't, the code falls down and blindly eats arr[i] in the same turn.
//             // Example: temp=4, arr[j]=3. We kill j. 
//             // If no continue, we immediately eat arr[i] for no reason before checking the new j!
//             continue; 
//         }

//         if(i+1==j) {
//             if(temp+arr[i]==arr[j]) {
//                 ans += temp+arr[i]+1;
//                 return ans;
//             }
//             else if(temp+arr[i]<arr[j]){
//                 long long val = (arr[j]-arr[i]-temp+1)/2 ;
//                 ans += temp + arr[i] + val +1;
//                 return ans;
//             }
//             else {
//                 long long val1 = arr[j]-temp;
//                 ans += temp +val1+1;
//                 arr[i]-=val1;

//                 if(arr[i]==1) return ans+1;
//                 else{
//                     ans += (arr[i]+1)/2 + 1;
//                     return ans;
//                 }

//             }
//         }

//         // We check this so we don't over-farm and waste combo points.
//         // Example: If temp=3 and arr[j]=5, we only need 2 more points.
//         // If arr[i]=10, swallowing all 10 wastes 8 points when temp resets to 0.
//         // Instead, we take exactly what is 'needed' and leave the rest in arr[i].
//         if(temp + arr[i] > arr[j]) {
//             long long val = arr[j] - temp;
//             temp += val;
//             arr[i] -= val;
//         } 
//         else {
//             temp += arr[i];
//             i++;
//         }
//     }

//     return ans;
// }

long long fun(vector<int>& arr,int n){

    long long sum=0,ans=0;
    for(int x:arr) sum+=x;

    ans += (sum+1)/2; //ceil(sum/2)
    int cnt=0;
    long long req = sum - ans; // floor(sum/2)
    for(int i=n-1;i>=0;i--){
        if(req>0){
            req-=arr[i];
            cnt++;
        }
        else break;
    }

    return ans+cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end()); 
        cout<<fun(arr,n)<<endl;
    }

}