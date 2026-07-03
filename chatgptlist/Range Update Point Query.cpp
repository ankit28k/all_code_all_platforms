#include<bits/stdc++.h>
using namespace std;

int dsum(int n){
    int sum=0;
    while(n){
        sum += n%10;
        n=n/10;
    }
    return sum;
}
class sgt{
    vector<int> seg;
public:
    sgt(int n){
        seg.resize(4*n);
    }

    /*
    * ==========================================
    * RANGE STATE PRUNING LOGIC EXPLANATION
    * ==========================================
    * Why do we maintain the maximum value of a segment and use `seg[idx] <= 9`?
    * 
    * 1. The Operation: The sum of digits of any single-digit number (<= 9) is the number itself. 
    *    Therefore, any further updates will change absolutely nothing (e.g., dsum(8) = 8).
    * 
    * 2. The Limit: Any number up to 10^9 converges [reaches a permanent state] to a single digit 
    *    in a maximum of 3 operations (e.g., 999,999,999 -> 81 -> 9).
    * 
    * 3. The Shortcut (Pruning): By storing the maximum value of the range in the intermediate 
    *    tree nodes, we can instantly check if an entire range has reached this permanent state.
    *    If `seg[idx] <= 9`, it mathematically proves that ALL children in this range are also <= 9. 
    *    We can safely `return` early and skip traversing the leaves, avoiding useless calculations.
    * 
    * EXAMPLE:
    * Let the array be [99, 8, 5, 99]. 
    * - The root node of the segment tree stores the maximum value (99). 
    * - After 3 range updates on the whole array, the leaves become [9, 8, 5, 9]. 
    * - The root node recalculates its maximum, which is now 9. 
    * - If a 4th range update is called, the root checks `if (seg[idx] <= 9)`. 
    *   Since 9 <= 9 is true, it immediately aborts the update in O(1) time instead of 
    *   visiting all the leaves. This heavily amortizes [spreads out and reduces] the time 
    *   complexity, completely preventing a TLE [Time Limit Exceeded] error.
    */
    void build(int idx,int low,int high,vector<int>& arr){
        if(low==high){
            seg[idx] = arr[low];
            return;
        }

        int mid = (low+high)/2;
        build(2*idx+1,low,mid,arr);
        build(2*idx+2,mid+1,high,arr);

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]); //see logic above
    }
    void update(int idx,int low,int high,int l,int r){

        if(l>high || r<low || seg[idx]<=9) return; // <=9 wil not affect the digit sum
        
        if(low==high) {
            seg[idx] = dsum(seg[idx]);
            return;
        }

        int mid = (low+high)/2;
        update(2*idx+1,low,mid,l,r);
        update(2*idx+2,mid+1,high,l,r);

        seg[idx] = max(seg[2*idx+1],seg[2*idx+2]);//see logic above
    }

    int q(int idx,int low,int high,int i){
        if(low==high) return seg[idx];

        int mid = (low+high)/2;
        if(i<=mid) return q(2*idx+1,low,mid,i);
        return q(2*idx+2,mid+1,high,i);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        sgt sg(n);
        sg.build(0,0,n-1,arr);

        while(q--){
            int t;
            cin>>t;
            if(t==1){
                int l,r;
                cin>>l>>r;
                l--;r--;
                sg.update(0,0,n-1,l,r);
            }
            else{
                int x;
                cin>>x;
                x--;
                cout<<sg.q(0,0,n-1,x)<<endl;
            }
        }
    }

}