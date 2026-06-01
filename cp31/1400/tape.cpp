#include<bits/stdc++.h>
using namespace std;

/*
THE INTUITION AND IDEA:
-----------------------
1. Start with the maximum pieces:
If we had no restrictions, the cheapest way to cover 'n' broken segments 
is to use exactly 'n' pieces of tape, each 1 cm long (one on every broken spot).
Total length = n. Total pieces = n. This is why we start with `int ans = n;`.

2. Merge pieces to reach 'k':
The problem limits us to 'k' pieces. If n > k, we have too many pieces and 
must connect (merge) adjacent pieces of tape together. 
To get our piece count from 'n' down to 'k', we must perform exactly 'n - k' merges.
To keep the total tape length as small as possible, we merge across the smallest gaps first.

3. The Math: Why `temp[i] - 1`?
If we have broken segments at 20 and 30, the gap calculated in `temp` is 10.
- Before merging: 1cm piece at 20, 1cm piece at 30. (Total tape used = 2)
- After merging: One single piece from 20 to 30. Length is 30 - 20 + 1 = 11. (Total tape = 11)
Merging them increased our total tape length from 2 to 11. That is a net increase of 9 cm.
Notice that 9 is exactly the gap distance minus 1 (10 - 1).
So, merging across any gap 'X' adds exactly 'X - 1' to our total tape length.

or temp[i] - 1......is the number of empty segments between the two broken segments that we are merging across.
like .. 1 2 _ 4 _ _ _ ...its 1 between 2 and 4

4. Example Walkthrough (n=4, k=2, broken at 20, 30, 75, 80):
- Gaps are: 10 (between 20-30), 45 (30-75), 5 (75-80). 
- Sorted gaps (temp array): [5, 10, 45]
- Start with 'n' pieces: ans = 4. 
- We need n - k = 4 - 2 = 2 merges.
- Loop 1 (Merge gap 5): Extra tape added = 5 - 1 = 4. 'ans' becomes 4 + 4 = 8.
- Loop 2 (Merge gap 10): Extra tape added = 10 - 1 = 9. 'ans' becomes 8 + 9 = 17.
- Final answer is 17.
*/

int fun(vector<int>& arr,int n,int k){

    if(k==n) return n;

    vector<int> temp;
    for(int i=1;i<n;i++){
        temp.push_back(arr[i]-arr[i-1] );
    }
    
    sort(temp.begin(),temp.end());

    int ans = n;
    for(int i=0; i<n-k; i++){
        ans += temp[i] - 1;
    }

    return ans;
     
} 

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<fun(arr,n,k)<<endl; 
}