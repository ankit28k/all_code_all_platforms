#include<bits/stdc++.h>
using namespace std;

bool oppparity(string& a,string& b,int st,int end){

    for(int i=st;i<=end;i++){
        if(a[i]==b[i]) return false;
    }

    return true;
}

bool sameparity(string& a,string& b,int st,int end){

    for(int i=st;i<=end;i++){
        if(a[i] != b[i]) return false;
    }

    return true;
}
bool fun(string& a,string& b,int n){

    if(a==b) return true;
    vector<pair<int,int>> psum(n); //{no. of 1,no. of 0}

    if(a[0]=='1'){
        psum[0] = {1,0};
    }
    else  psum[0] = {0,1};
    
    for(int i=1;i<n;i++){

        if(a[i]=='1')  psum[i] = {psum[i-1].first + 1 , psum[i-1].second }; 
        
        else  psum[i] = {psum[i-1].first , psum[i-1].second + 1}; 
    }

    vector<int> eidx;
    for(int i=0;i<n;i++) {
        if(psum[i].first == psum[i].second) eidx.push_back(i);
    }
    
    if(eidx.size()==0) return false;

    int prev=0;
    for(int i=0;i<eidx.size();i++){ 

        bool opp = oppparity(a,b,prev,eidx[i]);
        bool same = sameparity(a,b,prev,eidx[i]);

        if(!(opp || same)) return false; // both or is false
        prev = eidx[i] + 1;
        
    }

    // as if elements left ...that means they cant be reversed as...no. of 0 != no. of 1...so it must be same
    if(!sameparity(a,b,prev,n-1)) return false; 

    return true;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;

        if(fun(a,b,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }

}