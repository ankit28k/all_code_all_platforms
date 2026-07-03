#include<bits/stdc++.h>
using namespace std;

string fun(int n,char c,vector<string>& arr){
    
    int col = c-'A';
    for(int i=0;i<n;i++){
        if(arr[i][col] == 'o') return "Yes";
    }

    return "No";
}
int main(){
    int n;
    char x;
    cin>>n>>x;
    vector<string> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<fun(n,x,arr)<<endl;

}