#include<bits/stdc++.h>
using namespace std;

// We need sum of even indexes and some of odd indexes.....=> se == so => se - so = 0
// => then multiply all odd index numbers with -1 and calculate prefix sum Check whether it becomes zero or not
// Or if the pre sum at any point is same to the existing one

string fun(vector<int>& arr,int n){

    if(n==1) return "NO";

    for(int i=0;i<n;i++){
        if((i+1)%2 != 0 ) arr[i] = -arr[i];
    }
    
    vector<long long> psum(n);

    map<long long,int> mp;
    psum[0] = arr[0];
    mp[arr[0]] = 0;
    for(int i=1;i<n;i++){
        
        psum[i] = psum[i-1] + arr[i];
        if(psum[i]==0 || mp.find(psum[i]) != mp.end()) return "YES";
        mp[psum[i]] = i;
        
    }

    return "NO";
    // vector<long long> posum(n),pesum(n);
    // posum[0] = arr[0];
    // pesum[0] = 0;

    // for(int i=1;i<n;i++){
    //     if((i+1)%2 ==0) {
    //         posum[i] = posum[i-1] ;
    //         pesum[i] = pesum[i-1]+ arr[i];
                
    //     }

    //     else{
    //         posum[i] = posum[i-1] + arr[i];
    //         pesum[i] = pesum[i-1];
    //     }
    // }

    // map<int,int> mo,me;
    // for(int i=0;i<n;i++){
    //     if(mo.find(posum[i]) == mo.end()) mo[posum[i]] = i ;
    //     if(me.find(pesum[i]) == me.end()) me[pesum[i]] = i ; 
    // }

    // for(int i=0;i<n;i++){
    //     if(pesum[i] == posum[i]) return "YES";

    //     int tarfe = pesum[i] - posum[i], tarfo = posum[i] - pesum[i];

    //     int idxo ,idxe;
    //     if(mo.find(tarfo) != mo.end()) {
    //         idxo = mo[tarfo];
    //         if(pesum[i] - pesum[idxo] == posum[i] - posum[idxo]) return "YES";
    //     }

    //     if(me.find(tarfe) != me.end()) {
    //         idxe = me[tarfe];
    //         if(pesum[i] - pesum[idxe] == posum[i] - posum[idxe]) return "YES";
    //     }

    // }

    // return "NO";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<fun(arr,n)<<endl;
        
    }

}