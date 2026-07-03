#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    // vector<int> ax(n),ay(n);
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y};
        // ax[i] =x;
        // ay[i] = y;
    }

    // sort(ax.begin(),ax.end());
    // sort(ay.begin(),ay.end());

    sort(arr.begin(),arr.end());

    int cnt=0 , miny = INT_MAX;
    for(int i=0;i<n;i++){
        int x = arr[i].first , y = arr[i].second;

        // int idxx = lower_bound(ax.begin(),ax.end(),x) - ax.begin();
        // int idxy = lower_bound(ay.begin(),ay.end(),y) - ay.begin();

        // if(idxx == 0 && idxy ==0 ) cnt++;

        if(y<miny) {
            cnt++;
            miny = y;
        }
    }

    cout<<cnt<<endl;

}