#include<bits/stdc++.h>
using namespace std;

vector<int> fun(int n){

    //int temp = n;
    vector<int> div;
    for(int i=2;i*i<=n;i++ ){
        if(n%i ==0) {
            div.push_back(i);
            n = n/i;
            break;
        }
    }

    // Prevents segmentation fault if n is prime and div is empty (div[0] doesn't exist)
    if(div.empty()) return div;

    for(int i=2;i*i<=n;i++ ){
        if(n%i ==0 && i != div[0]) {
            div.push_back(i);
            n = n/i;
            break;
        }
    }
    
    // Prevents segmentation fault if a 2nd divisor wasn't found (div[1] doesn't exist)
    if(div.size() < 2) return div;

    // int left = temp/(div[0]*div[1]);
    // if(left >1 && left != div[0] && left != div[1]) div.push_back(left);
 
    if(n >1 && n != div[0] && n != div[1]) div.push_back(n); //as left = n
    return div;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         
        vector<int> ans = fun(n);
        if(ans.size() <3 ) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int x:ans) cout<<x<<" ";
            cout<<endl;
        }
    }

}