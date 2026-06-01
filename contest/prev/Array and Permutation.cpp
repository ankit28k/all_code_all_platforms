#include<bits/stdc++.h>
using namespace std;

string fun(vector<int>& arr,vector<int>& brr,int n){
    
    set<int> st;
 
    for(int i=0;i<n;i++){ 

        if(i==0){
            if(brr[i]==brr[i+1]){
                st.insert(arr[i]);
                st.insert(arr[i+1]);

            }

            else{
                if(st.find(brr[i]) == st.end()) return "NO";
                st.empty();
            }
        }
        if(i==n-1){

            if(brr[i]==brr[i+1]){
                st.insert(arr[i-1]);
                st.insert(arr[i]);

            }

            else{
                if(st.find(brr[i]) == st.end()) return "NO";
                st.empty();
            }
        }

        else{
            if(brr[i]==brr[i+1]){
                st.insert(arr[i-1]);
                st.insert(arr[i]);
                st.insert(arr[i+1]);

            }

            else{
                if(st.find(brr[i]) == st.end()) return "NO";
                st.empty();
            }
        }
        
    }

    return "YES";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n),brr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++) cin>>brr[i];

        cout<<fun(arr,brr,n)<<endl;

    }

}