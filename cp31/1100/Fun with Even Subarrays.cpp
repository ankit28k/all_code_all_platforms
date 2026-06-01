#include<bits/stdc++.h>
using namespace std;

/*
    LOGIC EXPLANATION:
    ------------------
    1. The problem asks for the minimum operations to make all elements equal.
    2. The operation allows us to copy a segment of length 'k' from the right to the left.
       Basically: arr[l...l+k-1] = arr[l+k...l+2k-1]
       This means information flows from RIGHT to LEFT.
    3. Therefore, the last element arr[n-1] never changes position. It is our "Target".
       We must make the entire array equal to arr[n-1].
    4. We start from the end and find the "valid suffix" (elements already equal to Target).
       Let 'cnt' be the length of this valid suffix.
    5. In one operation, we can double the size of this suffix by copying it to the left.
       So, 'cnt' becomes '2 * cnt'.
    6. OPTIMIZATION (Free Growth):
       Before performing an operation, we check elements immediately to the left of our
       current suffix. If they ALREADY match the target, we include them in our suffix
       for free (increment 'cnt') without using an operation.

    EXAMPLE WALKTHROUGH:
    --------------------
    Input: [1, 1, 2, 1]
    Target: 1 (last element)
    
    1. Start from end. Last element is 1. Suffix length 'cnt' = 1.
    2. Move left to index 2. Value is 2.
       Matches Target (1)? NO.
       -> We must perform an operation.
       -> Operation copies suffix [1] to index 2.
       -> Conceptually array becomes [1, 1, 1, 1].
       -> 'ans' increases by 1.
       -> 'cnt' doubles from 1 to 2.
    3. Move left to index 1. Value is 1.
       Matches Target? YES.
       -> We don't need an operation.
       -> "Free Growth": 'cnt' becomes 3.
    4. Move left to index 0. Value is 1.
       Matches Target? YES.
       -> "Free Growth": 'cnt' becomes 4.
    
    5. 'cnt' covers the whole array. Stop.
    Output: 1 operation.
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i]; 

        int cnt=1,idx =-1; 
        for(int i=n-2;i>=0;i--){
            if(arr[i]==arr[n-1]) cnt++;
            else {
                idx =i;
                break;
            }
        }

        int dist = idx;
        int ans =0;

        while(dist >=0){
            ans++;
            dist -= cnt;
            cnt *=2 ;

            // ADDED: Logic to skip elements that are ALREADY correct
            while(dist >= 0 && arr[dist] == arr[n-1]){
                dist--;
                cnt++; // Suffix grows for free
            }
            
        }

        cout<<ans<<endl;
    }

}