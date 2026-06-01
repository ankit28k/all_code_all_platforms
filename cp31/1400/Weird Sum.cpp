#include<bits/stdc++.h>
using namespace std;
int main(){ 

    int n,m;
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m));
    map<int,vector<pair<int,int>>> mp;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            mp[arr[i][j]].push_back({i+1,j+1});
        }
    } 

    long long sum=0;
    for(auto it : mp){

        vector<pair<int,int>> temp = it.second;
        int k = temp.size();

        vector<int> x,y;
        for(int i=0;i<k;i++){
            x.push_back(temp[i].first);
            y.push_back(temp[i].second);
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        

        for(int i=0;i<k;i++){ 

            long long bigger = k-1-i;
            long long smaller = i;

            sum += x[i]*smaller - x[i]*bigger;
            sum += y[i]*smaller - y[i]*bigger;
        }

    }

    cout<<sum<<endl;
    

}