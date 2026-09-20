#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
    int maxCollectibleArtifacts(std::vector<int> artifacts) {
        int l=0, r=0, ans=0,n=artifacts.size();
        map<int,int> mp;

        while(r<n){
            mp[artifacts[r]]++;
            while(l<=r && mp.size()>2){
                if(mp[artifacts[l]]>1) mp[artifacts[l]]--;
                else mp.erase(artifacts[l]);
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;

    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int> artifacts;
    int val;
    while (std::cin >> val) {
        artifacts.push_back(val);
    }
    Solution sol;
    std::cout << sol.maxCollectibleArtifacts(artifacts) << std::endl;
    return 0;
}