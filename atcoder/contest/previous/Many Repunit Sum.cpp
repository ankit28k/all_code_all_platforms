#include<bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n;
    cin>>n;
    vector<int> cnt(200005);

    
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        
        cnt[0] += 1;
        cnt[x] -= 1;
    } 

    for(int i=1;i<200005;i++){
        cnt[i] += cnt[i-1];
    }

    // long long sum = cnt[0];
    // reverse(cnt.begin(),cnt.end());

    // for(int i=1;i<200005;i++){
    //     sum = sum*10 + cnt[i];
    // }

    // cout<<sum<<endl;

    //long long variable cannot hold the result because the answer can have up to 200,000 digits
    vector<int> ans;
    int carry = 0;
    for(int i=0; i<200005; i++){  
        int val = cnt[i] + carry;
        ans.push_back(val % 10);
        carry = val / 10;
    }

    //Remove leading zeros and print in reverse
    while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
    
    for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
    cout<<endl;
 
    

}