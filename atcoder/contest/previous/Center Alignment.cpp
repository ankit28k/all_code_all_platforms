#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    vector<string> arr(n);

    int maxi = 0;
    for(int i=0;i<n;i++) {
        string s;
        cin>>s; 
        maxi = max(maxi,(int)s.length());
        arr[i] = s;
    }
  
    for(int i=0;i<n;i++){
        
        string s = arr[i];
        int l = s.length();

        int k = (maxi-l)/2;

        string temp = "";
        for(int j=0;j<k;j++) temp.push_back('.');

        temp+= s;

        for(int j=0;j<k;j++) temp.push_back('.'); 

        arr[i] = temp;
        

    }

    for(string x:arr) cout<<x<<endl;




}