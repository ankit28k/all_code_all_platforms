#include<bits/stdc++.h>
using namespace std;

int sdivisor(){
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string arr;
        cin>>arr;

        set<int> nott ,t , s ;
        for(int i=0;i<n;i++) { 

            if(arr[i]=='1') t.insert(i+1);
            else if(arr[i]=='0') nott.insert(i+1);
            s.insert(i+1);
        }
    }

}