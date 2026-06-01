#include<bits/stdc++.h>
using namespace std;
/*
Logic Breakdown: Why x -= arr[i]?

1. PREPARATION:
   - We sort 'arr' to always build the cheapest possible bundle of size 1, then size 2, etc.

2. THE VARIABLE 'x':
   - Initially, 'x' is the Total Budget.
   - Inside the loop, `x -= arr[i]` subtracts the BASE COST (Day 0 price) of the current item.
   - After this line, 'x' transforms into "Surplus Budget": money left over strictly to cover
     daily price increases (inflation).

3. THE MATH:
   - At index 'i', we are considering a bundle of size `k = i + 1`.
   - The cost of a bundle of size 'k' increases by 'k' coins every day.
   - We have 'x' surplus coins. We need 'k' coins per day.
   - `x / k` tells us how many FUTURE days (Day 1, Day 2...) we can afford this inflation.

4. THE FORMULA: `packs = x / (i + 1) + 1`
   - `x / (i+1)`: The number of future days we can afford.
   - `+ 1`: Adds Day 0 (since we already subtracted the base cost, we know we can afford Day 0).

5. TOTAL ANSWER:
   - Instead of simulating day-by-day, we sum up the "Lifespan" (days affordable) of every
     bundle size. This mathematically equals the total packs bought.
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;

        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sort(arr.begin(),arr.end());

        long long ans=0;
        for(int i=0;i<n;i++){
        
            x -= arr[i];

            // If x is exactly 0, you can still afford the items on Day 0
            if(x<0) break;

            long long packs = x/(i+1) + 1; // a + (n-1)d >=0
            ans+=packs;
        }

        cout<<ans<<endl;

    }

}