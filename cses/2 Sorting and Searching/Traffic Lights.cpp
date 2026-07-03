#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,n;
    cin>>x>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    set<int> tl;
    tl.insert(0);
    tl.insert(x);

    multiset<int> gaps;
    gaps.insert(x);

    vector<int> ans(n);

    for(int i=0;i<n;i++){
        
        auto it = tl.upper_bound(arr[i]);
        int r = *it;
        it--;
        int l = *it;

        gaps.erase(gaps.find(r-l));
        
        gaps.insert(r-arr[i]);
        gaps.insert(arr[i]-l);


        tl.insert(arr[i]);
        ans[i] = *gaps.rbegin();

    }

    for(int x:ans) cout<<x<<" ";
    cout<<endl;


}