#include <bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    unordered_map<long long,long long> m;
    long long count = 0, prefixsum = 0;

    m[0] = 1; // to count subarrays starting at index 0

    for(int i=0; i<n; i++) {
        prefixsum += arr[i];

        if(m.find(prefixsum - x) != m.end())
            count += m[prefixsum - x];

        m[prefixsum]++;
    }

    cout << count << "\n";
}
