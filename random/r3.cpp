#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long taxiDriver(const std::vector<int>& pickup, const std::vector<int>& drop, const std::vector<int>& tip) {
        int n = pickup.size();
        vector<vector<int>> arr(n);

        for(int i=0;i<n;i++) arr[i] = {pickup[i],drop[i],tip[i]};
        sort(arr.begin(),arr.end());

        int i=0;
        long long ans=0;
        for(;i<n;i++){
            if(arr[i][1]>arr[i+1][0]){
                int temp = arr[i][1] - arr[i][0] + arr[i][2];
                int j= i+1;
                int val = arr[i][1];

                while(j<n && arr[j][0]<val){
                    int tj = arr[j][1] - arr[j][0] + arr[j][2];
                    temp = max(temp,tj);
                    j++;
                }

                ans += temp;
                i=j-1;
            }
            else ans += arr[i][1] - arr[i][0] + arr[i][2];
        }
        if(i<n) ans += arr[i][1] - arr[i][0] + arr[i][2];
        return ans;
        
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> pickup(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pickup[i];
    }

    std::vector<int> drop(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> drop[i];
    }

    std::vector<int> tip(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> tip[i];
    }

    Solution sol;
    long long result = sol.taxiDriver(pickup, drop, tip);

    std::cout << result << std::endl;

    return 0;
}