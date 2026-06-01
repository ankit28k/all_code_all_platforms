#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> fq,int m){

    vector<bool> vis(m,false);
    int cnt=0;

    for(int i=0;i<m;i++){

        if(i==0 || 2*i==m) { //i==m/2 fails for odd number ...where a number is visited twice....
            
            // not above as if fq[0] == 0,it skips the first if block and enters the second block if (!vis[0]). Inside there, it
            // access fq[m - i], which becomes fq[m-0] => fq[m]....which is out of bound
            if(fq[i] !=0){ 
                cnt++;
                vis[i] = true; 
            }
            continue;
        }

        if(!vis[i]){

            if(fq[i]==0 && fq[m-i]==0) continue;

            if(abs(fq[i] -fq[m-i]) <=1) cnt++;

            else  cnt += abs(fq[i] - fq[m-i] ) ;

            // else{

            //     if(fq[i]>fq[m-i]){
            //         cnt = cnt+ ((fq[i] - fq[m-i]) -1) +1;
            //     }

            //     else cnt = cnt+ ((fq[m-i] - fq[i]) -1) +1;

            // }

            vis[i] = true;
            vis[m-i] = true;
        }
        

    }

    return cnt;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m; 

        vector<int> fq(m,0);
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            int k= x%m;
            fq[k]++; 
        }
 
        cout<<fun(fq,m)<<endl;

    }

}