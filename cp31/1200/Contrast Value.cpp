#include<bits/stdc++.h>
using namespace std;

/*
Logic:
1. The "contrast" of the array depends entirely on its local extrema (peaks and valleys). 
2. Step 1: Remove consecutive duplicates. They contribute 0 to the contrast, so they are unnecessary for the final subsequence.
3. Step 2: Count the alternating monotonic segments (strictly increasing or strictly decreasing sequences). 
4. Every time the sequence changes direction (from increasing to decreasing, or vice versa), it represents a turning point that must be kept to maintain the same total absolute difference.
5. The minimum required size of the subsequence is simply the number of these continuous segments plus the starting element (which your 'cnt' variable tracks perfectly).
*/

int fun(vector<int>& arr,int n){
    
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++){ 
        if(arr[i] != arr[i-1]) temp.push_back(arr[i]);
    }

    // for(int x:temp) cout<<x<<" ";
    // cout<<endl;

    int i=temp.size()-1 , cnt = 1;
    while(i>0){
        if(temp[i] > temp[i-1]){
            while(i>0 && temp[i] > temp[i-1]){
                i--;
            }
            cnt++;
        }

        else if(temp[i] < temp[i-1]){
            while(i>0 && temp[i] < temp[i-1]){
                i--;
            }
            cnt++;
        }
    }

    return cnt;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i]; 
        cout<<fun(arr,n)<<endl;
    }

}