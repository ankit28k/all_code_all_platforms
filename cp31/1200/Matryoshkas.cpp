#include<bits/stdc++.h>
using namespace std;

// int fun(vector<int>& arr,int n){

//     sort(arr.begin(),arr.end());
//     vector<int> rep;
//     vector<int> nrep;
//     nrep.push_back(arr[0]);

//     for(int i=1;i<n;i++){
//         if(arr[i]==arr[i-1]) rep.push_back(arr[i]);
//         else nrep.push_back(arr[i]);
//     }

//     int cnt=1;

//     for(int i=1;i<nrep.size();i++) {
//         if(nrep[i] != nrep[i-1]+1) cnt++;
//     }
    
    
//     while(rep.size()>0){

//         cnt++;
//         vector<int> temp_rep;
//         vector<int> temp_nrep;

//         temp_nrep.push_back(rep[0]);

//         for(int i=1;i<rep.size();i++){
//             if(rep[i]==rep[i-1]) temp_rep.push_back(rep[i]);
//             else temp_nrep.push_back(rep[i]);
//         } 

//         for(int i=1;i<temp_nrep.size();i++) {
//             if(temp_nrep[i] != temp_nrep[i-1]+1) cnt++;
//         }

//         rep = temp_rep;
//     }

//     return cnt;
// } 

/* * LOGIC & INTUITION:
 * 1. We use a map to both count the frequencies of each doll size and automatically sort them in ascending order.
 * 2. To minimize the number of sets, we greedily place a doll of size X into an available doll of size X-1.
 * 3. A new set is ONLY forced to start when we have more dolls of the current size (m[el]) 
 * than the immediately preceding size (m[el-1]).
 * 4. The number of new sets we must start at size 'el' is simply the surplus: max(0, m[el] - m[el-1]).
 * 5. This logic automatically handles gaps in consecutive numbers (e.g., having size 12 but no size 11). 
 * If there's a gap, m[el-1] defaults to 0, correctly forcing all current dolls to start their own new sets.
 */

int fun(vector<int>& arr,int n){

    map<int,int> m;
    for(int i=0;i<n;i++) m[arr[i]]++; 

    int ans =0;

    for(auto it=m.begin();it!=m.end();it++){

        int el = it->first;
        ans += max(0,m[el] - m[el - 1]);
    } 
     
    return ans;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n); 

        for(int i=0;i<n;i++)  cin>>arr[i]; 

        cout<<fun(arr,n)<<endl;
    }

}