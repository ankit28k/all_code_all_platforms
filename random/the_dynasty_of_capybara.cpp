#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // k salary levels: A[i], B[i] are the min and max salary (both inclusive) of level i (0-indexed).
    // n employees: S[i] is the salary of the i-th employee.
    // Return the 1-based index of the level containing the most employees
    // (smallest index if tied). If no employee fits any level, return 1.
    int solve(int k, int n, vector<int>& A, vector<int>& B, vector<int>& S) {
        
        vector<int> ans(k,0);
        for(int i=0;i<n;i++){
            int idxa = upper_bound(A.begin(),A.end(),S[i]) - A.begin();
            idxa--;
            int r = idxa;
            int idxb = lower_bound(B.begin(),B.end(),S[i]) - B.begin();
            int l = idxb;

            if(l<=r){
                if(l>=0) ans[l]++;
                if(r<k-1) ans[r+1]--;
            }
            
        }
        for(int i=1;i<k;i++) ans[i]+=ans[i-1];
        int cnt=0,idx=1;
        for(int i=0;i<k;i++) {
            if(cnt<ans[i]) {
                idx = i+1;
                cnt=ans[i];
            }
        }
        return idx;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, n;
    cin >> k >> n;
    vector<int> A(k), B(k), S(n);
    for (int i = 0; i < k; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < n; i++) cin >> S[i];
    cout << Solution().solve(k, n, A, B, S) << endl;
    return 0;
}
