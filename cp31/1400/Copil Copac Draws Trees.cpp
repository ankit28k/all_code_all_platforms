#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
 
        vector<pair<int,int>> arr(n-1);
        for(int i=0;i<n-1;i++) {
            int x,y;
            cin>>x>>y;
            arr[i] = {x,y};
        }

        set<int> drawn;
        drawn.insert(1);

        int ans =0;
        for(int i=0;i<n;i++){

            int x =  arr[i].first , y = arr[i].second;

            if(drawn.find(x) == drawn.end() && drawn.find(y) == drawn.end()){
                drawn.insert(y);
                drawn.insert(x);
                ans++;
            }

            else if(drawn.find(x) == drawn.end() || drawn.find(y) == drawn.end()){

                if(drawn.find(x) == drawn.end()) drawn.insert(x);
                if(drawn.find(y) == drawn.end()) drawn.insert(y);
            }

            else continue;
        }
        // while(drawn.size()<n){
        //     vector<pair<int,int>> temp;

        //     for(int i=0;i<arr.size();i++){

        //         int x =  arr[i].first , y = arr[i].second;

        //         if(drawn.find(x) != drawn.end()){
        //             drawn.insert(y);
        //         }

        //         else if(drawn.find(y) != drawn.end()){
        //             drawn.insert(x);
        //         }

        //         else temp.push_back({x,y});

        //     }

        //     arr = temp;

        //     ans++;
        // }

        cout<<ans<<endl;
    }

}