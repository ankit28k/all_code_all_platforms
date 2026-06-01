#include<bits/stdc++.h>
using namespace std;

class mfind{
public:
    multiset<int> maxh ,minh;

    mfind(){

    }
    
    void addnum(int n){

        maxh.insert(n);

        while(!minh.empty() && !maxh.empty() && *(minh.begin()) < *(maxh.rbegin())){
            int t = *(maxh.rbegin());
            maxh.erase(maxh.find(t));
            minh.insert(t);
        }

        while(minh.size()>maxh.size() + 1){
            int t = *(minh.begin());
            minh.erase(minh.find(t));
            maxh.insert(t);
        }

        while(maxh.size()>minh.size() + 1){
            int t = *(maxh.rbegin());
            maxh.erase(maxh.find(t));
            minh.insert(t);
        }
    }

    int median(){
        if(minh.size()==maxh.size()) return min(*(minh.begin()) , *(maxh.rbegin()));
        else if (minh.size() > maxh.size()) return *(minh.begin());
        else return *(maxh.rbegin());
    }

    void removenum(int n){
        if(minh.find( n) != minh.end()) minh.erase(minh.find(n));
        else maxh.erase(maxh.find(n));

        while(minh.size()>maxh.size() + 1){
            int t = *(minh.begin());
            minh.erase(minh.find(t));
            maxh.insert(t);
        }

        while(maxh.size()>minh.size() + 1){
            int t = *(maxh.rbegin());
            maxh.erase(maxh.find(t));
            minh.insert(t);
        }
    }
};

int main(){
    
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    mfind mf;

    int l=0,r=0;
    for(;r<k;r++){
        mf.addnum(arr[r]);
    }

    
    vector<int> ans;
    ans.push_back(mf.median());

    while(r<n){
        mf.addnum(arr[r]);
        mf.removenum(arr[l]);

        r++;
        l++;
        ans.push_back(mf.median());
    }

    for(int x:ans)cout<<x<<" ";
    cout<<endl;
    

}