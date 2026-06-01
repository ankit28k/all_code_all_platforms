#include<bits/stdc++.h>
using namespace std;

bool comp(int a,int b){
    return a>b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        vector<int> p(n);
        for(int i=0;i<n;i++) p[i] = i+1;
        sort(p.begin(),p.end(),comp);

        int l=-1,r=-1 , k;

        for(int i=0;i<n;i++){
            if(arr[i] != p[i]){
                l=i;
                k=p[i];
                break;
            }
        }

        // if already correct
        if(l == -1){
            for(int x : arr) cout << x << " ";
            cout << endl;
            continue;
        }
        
        for(int j=l;j<n;j++){
            if(arr[j]==k) {
                r=j;
                break;
            }
        }

        for(int i=l,j=r;i<j;i++,j--) swap(arr[i],arr[j]);

        for(int i=0;i<n;i++) cout<<arr[i]<<" ";
        cout<<endl;

    }

}