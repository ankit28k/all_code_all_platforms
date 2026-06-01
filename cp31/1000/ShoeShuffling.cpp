#include<bits/stdc++.h>
using namespace std;

void cyclicRightShift(vector<int>& a, int l, int r) {
    int last = a[r];
    for(int i = r; i > l; i--) {
        a[i] = a[i-1];
    }
    a[l] = last;
}

bool check(map<int,int>& m){
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second == 1) return false;
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        map<int,int> m;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            m[arr[i]]++;
        }

        bool flag = true;

        vector<int> ans(n);

        for(int i=0;i<n;i++)  ans[i] = i+1; 
        

        if(!check(m)){
            cout<<-1<<endl;
            continue;
        }

        else{

            vector<int> ans(n);
            for(int i=0;i<n;i++)  ans[i] = i+1; 

            int l=0,r=1;
            for(int i=0;i<n-1;i++){  

                if(arr[i]==arr[i+1]){ 
                    r++;
                }

                else{
                    cyclicRightShift(ans,l,r-1);
                    l=i+1;
                    r=i+2;  
                }
            }

            cyclicRightShift(ans, l, n-1);

            for(int x:ans) cout<<x<<" ";
            cout<<endl;
            continue;
        }

    }

}