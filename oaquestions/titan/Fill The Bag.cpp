#include <bits/stdc++.h>
using namespace std;

long long minDivisions(long long val, const vector<long long>& arr) {
    long long ans=0;
    int n = arr.size();
    
    vector<int> fq(64,0);
    for(int i=0;i<n;i++){
        for(int bit=0;bit<64;bit++){
            if((arr[i]>>bit)&1) fq[bit]++;
        }
    }

    for(int bit=0;bit<64;bit++){

        if((val>>bit)&1) {

            if(fq[bit]>0) {
                fq[bit]--;
                val = val & (~(1<<bit));
            }
            else{
                int i=bit;
                while(i>=0){
                    if(fq[i]>0){
                        fq[i]--;
                        val = val & (~(1<<bit));
                        break;
                    }
                    ans++;
                    i--;
                }

            }
        }
    }
    for(int bit=0;bit<64;bit++){
        if((val>>bit)&1) return -1;
    }
    return ans;

}   

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        int m;
        cin >> n >> m;
        vector<long long> arr(m);
        for (int i = 0; i < m; ++i) cin >> arr[i];
        cout << minDivisions(n, arr) << "\n";
    }
    return 0;
}
