#include <bits/stdc++.h>
using namespace std;


// sumbit here https://www.naukri.com/code360/problems/ninja-and-the-greatest-number_1403513?utm_source=chatgpt.com&leftPanelTabValue=PROBLEM
class Solution {
public:

    bool poss(unordered_map<int,int>& mp,int val){
        for(int i=1;i*i<=val;i++){
            if(val%i==0){
                int a =i , b=val/i;
                if(a==b){
                    if(mp.find(a) != mp.end() && mp[a]>1) return true;
                }
                else{
                    if(mp.find(a) != mp.end() && mp.find(b) != mp.end()) return true;
                }

            }
        }
        return false;
    }

    int findGreatestProduct(vector<int>& arr) {

        unordered_map<int,int> mp;
        for(int x:arr) mp[x]++;

        sort(arr.rbegin(),arr.rend());

        int n = arr.size();
        for(int i=0;i<n;i++){
            if(poss(mp,arr[i])) return arr[i];
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin>>arr[i];

    Solution solution;
    int result = solution.findGreatestProduct(arr);
    std::cout << result << std::endl;

    return 0;
}