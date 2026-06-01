#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int> arr(n);

        map<int,int> mp ;

        for(int i=0;i<n;i++) {
            cin>>arr[i];
            mp[arr[i]]++;
        }

        vector<int> temp;

        for(auto it : mp) {
            temp.push_back(it.first);
        }

        sort(temp.rbegin(),temp.rend());
        int nt = temp.size(); 

        vector<int> left(n,w);

        int ans=0;

        //not n^2 as... The outer for loop runs for every unique width (at most 20 times) as 1 ≤ 𝑤𝑖 ≤10^6...
        // and j can go upto n ...as only n rows...of mp[val] is max of n
        for(int i=0;i<nt;i++){
            int j=0;
            int val = temp[i];

            int cnt=0;
            while(mp[val]>0){

                if(left[j]>=val){
                    left[j] -= val;
                    mp[val]--;
                    cnt++;
                }
                else j++;

            }

            ans = max(cnt,ans);
        }

        cout<<ans<<endl;
    }

}