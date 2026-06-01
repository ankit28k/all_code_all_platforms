#include<bits/stdc++.h>
using namespace std;
int main(){
    
    map<int , pair<int,int>> mp;
    vector<int> temp = {4,8,15,16,23,42};

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            mp[temp[i]*temp[j]] = {temp[i],temp[j]};
        }
    }

    vector<int> ans(6);

    int val1; // 0,5
    cout<<"? 1 6"<<endl;;
    cin>>val1;
    int val2; //1,5
    cout<<"? 2 6"<<endl;
    cin>>val2;

    int a = mp[val1].first , b = mp[val1].second;
    int x = mp[val2].first , y = mp[val2].second;

    if(a==x || a==y){
        ans[5] = a;
        ans[0] = b;
        if(a==x) ans[1] = y;
        if(a==y) ans[1] = x;
    }

    else if(b==x || b==y) {
        ans[5] = b;
        ans[0] = a;
        if(b==x) ans[1] = y; 
        if(b==y) ans[1] = x; 
    }


    int val3; // 2,4
    cout<<"? 3 5"<<endl;
    cin>>val3;
    int val4; //3,4
    cout<<"? 4 5"<<endl;
    cin>>val4;

    int c = mp[val3].first , d = mp[val3].second;
    int p = mp[val4].first , q = mp[val4].second;

    if(c==p || c==q){

        ans[4] = c;
        ans[2] = d;

        if(c==p)  ans[3] = q;
        if(c==q) ans[3] = p;
        
    }

    else if(d==p || d==q) {

        ans[4] = d;
        ans[2] = c;
        if(d==p) ans[3] = q;
        if(d==q) ans[3] = p;
    }

    cout<<"! ";
    for(int x:ans) cout<<x<<" ";
    cout<<endl;

}