#include<bits/stdc++.h>
using namespace std;


// WHY GREEDY FAILS HERE:
// Greedy only looks at the immediate cost to remove the very next '1'. It doesn't 
// realize that paying a slightly higher cost upfront might unlock a tightly packed 
// cluster of '1's right behind it for very cheap.

// Example Array: [0, 1, 0, 0, 0, 0, 1, 1, 0, 0]
// Target Sum: 1 (Meaning we need to remove two '1's)

// - Left side costs: 2 elements to remove the first '1'.
// - Right side costs: 3 elements to remove the first '1'.

// Greedy Approach (Fails): 
// 1. Sees 2 (left) < 3 (right), so it picks the Left side. (Cost: 2, needs 1 more '1').
// 2. To get the next '1', it costs 5 more from the left, or 3 from the right. It picks right.
// 3. Total greedy cost = 2 (left) + 3 (right) = 5.

// Optimal Approach (Checking all combinations):
// - 2 from Left, 0 from Right = cost of 7.
// - 1 from Left, 1 from Right = cost of 5 (Greedy trap).
// - 0 from Left, 2 from Right = cost of 4. (Optimal!)

// By checking all combinations, we see that taking both from the right costs only 4 
// because the '1's are clustered together. Greedy misses this entirely.


int fun(vector<int>& arr,int n,int s,int sum){
    if(sum<s) return -1;
    if(sum == s) return 0;

    vector<int> lcost , rcost;
    
    for(int i=0;i<n;i++){
        if(arr[i]==1) lcost.push_back(i+1);
    }
    for(int i=n-1;i>=0;i--){
        if(arr[i]==1) rcost.push_back(n - i);
    }

    int req = sum - s;

    //greedy
    //int i=0,j=0 , cost =0;
    // while(req>0){

    //     if(lcost[i] <= rcost[j]){
    //         cost +=lcost[i];
    //         lcost[i+1] -= i+1;
    //         i++;
    //         req--;
    //     }

    //     else {
    //         cost += rcost[j];
    //         rcost[j+1] -= j+1;
    //         j++;
    //         req--;
    //     }
    // }
    //return cost;

    int ans = INT_MAX;
    for(int i=0;i<=req;i++){

        int costl = 0 , costr = 0;
        if(i>0) costl = lcost[i-1]; //choose any left 1....else 0 i.e. no one
        if(req-i >0) costr = rcost[req-i-1]; //choose any right 1....else 0 i.e. no one

        ans = min(ans,costl + costr);
    }

    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;

        int sum=0;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            sum+=arr[i];
        }

        cout<<fun(arr,n,s,sum)<<endl;
        
    }

}