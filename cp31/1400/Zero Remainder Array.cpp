#include<bits/stdc++.h>
using namespace std;

long long fun(vector<int>&arr,int n,int k){

    map<int,int> mp;

    for(int i=0;i<n;i++) {
        if(arr[i]%k != 0) mp[ k - arr[i]%k ]++;
    }

    if(mp.empty()) return 0;

    long long x=1,cnt=1 , i=0,vis = mp.size();;

    while(!mp.empty()){

        int val = i*k;
        // for (auto it = mp.begin(); it != mp.end(); it++){

        //     if (x == it->first + val && it->second > 0){
        //         if (it->second > 1) it->second--;

        //         else{
        //             vis--;
        //             it->second--;
        //         }
        //         cnt++;
        //         x++;
        //     }

        //     else if (x != it->first + val && it->second > 0){

        //         int t = it->first + val - x;
        //         x += t;
        //         cnt += t;
        //         if (it->second > 1) it->second--;
        //         else{
        //             vis--;
        //             it->second--;
        //         }

        //         cnt++;
        //         x++;
        //     }
        // }

        // O(n) as only all elemnts and their frequencies is traverse
        for(auto it = mp.begin();it != mp.end();){

            if(x == it->first + val){
                if(it->second > 1 ) {
                    it->second--;
                    it++;
                }
                else it = mp.erase(it);

                cnt++;
                x++;
            }

            else {

                int t = it->first + val - x;
                x += t;
                cnt += t;
                if(it->second > 1 ) {
                    it->second--;
                    it++;
                }
                else it = mp.erase(it);

                cnt++;
                x++;
            }
        }

        i++;
    }

    return cnt;
}

long long fun(vector<int>&arr,int n,int k){

    map<int, int> mp;

    for (int i = 0; i < n; i++){
        if (arr[i] % k != 0) mp[k - arr[i] % k]++;
    }

    if(mp.empty()) return 0;

    long long x = 1, cnt = 1, i = 0, vis = mp.size();

    while (vis){

        int val = i * k;
        for (auto it = mp.begin(); it != mp.end(); it++){

            if (x == it->first + val && it->second > 0){
                if (it->second > 1) it->second--;

                else{
                    vis--;
                    it->second--;
                }
                cnt++;
                x++;
            }

            else if (x != it->first + val && it->second > 0){

                int t = it->first + val - x;
                x += t;
                cnt += t;
                if (it->second > 1) it->second--;
                else{
                    vis--;
                    it->second--;
                }

                cnt++;
                x++;
            }
        }
        i++;
    }

    return cnt;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) {
            cin>>arr[i];
        }
        cout<<fun(arr,n,k)<<endl;
    }

}