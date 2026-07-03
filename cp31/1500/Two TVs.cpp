#include<bits/stdc++.h>
using namespace std;

string fun(vector<pair<int,int>>& arr,int n){
    
    pair<int,int> tv1 = {-1,-1},tv2= {-1,-1};

    for(int i=0;i<n;i++){

        if(tv1.second < arr[i].first){
            tv1.first = arr[i].first;
            tv1.second = arr[i].second;
        }

        else if(tv2.second < arr[i].first){
            tv2.first = arr[i].first;
            tv2.second = arr[i].second;
        }

        else return "NO";
    }

    return "YES";

}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i] = {x,y};
    }

    sort(arr.begin(),arr.end());
    cout<<fun(arr,n)<<endl;

}