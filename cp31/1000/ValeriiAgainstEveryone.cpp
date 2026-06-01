#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        //The sum of a set of distinct powers of 2 has a unique value....ie 2^a + 2^b .... == 2^p + 2^q.....only if set {a,b..} == set{p,q..}
        //as 2^i has distinct value for distinct i.......and even if one element is same ...we have the ans...by choosing only that value
        // ex = i in set1 and j in set => 2^i = 2^j.....and they single values are non-intersecting and equal 
        
        set<int> s;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            s.insert(x);
        }

        if(s.size()<n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;



        // Counter-Example where your code fails
        // Input Array: [3, 10, 100, 3]
        // Correct Answer: YES
        // Your Code: Returns NO

        // for(int i=0;i<n;i++) {
        //     int x;
        //     cin>>x;
        //     arr[i] = pow(2,x);
        // }

        // vector<long long> psum_l(n) , psum_r(n);
        // psum_l[0] = arr[0];
        // psum_r[n-1] = arr[n-1];

        // for(int i=1;i<n;i++) psum_l[i] = psum_l[i-1] + arr[i];
        // for(int i=n-2;i>=0;i--) psum_r[i] = psum_r[i+1] + arr[i];

        // bool flag = false;
        // for(int i=0;i<n-1;i++){
        //     if(psum_l[i]==psum_r[i+1]) {
        //         flag = true;
        //         break;
        //     }
        // }

        // if(flag) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;

    }

}