#include<bits/stdc++.h>
using namespace std;
int main(){ 
    
    int n;
    cin>>n;
    
    queue<int> qin,qout;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        qin.push(x);
    }
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        qout.push(x);
    }

    set<int> vis;
    int ans=0;

    while(!qin.empty() && !qout.empty()){

        if(vis.find(qin.front()) == vis.end()){

            int carin = qin.front();
            qin.pop();

            while(qout.front() != carin ){

                if(vis.find(qout.front()) == vis.end()) {
                    vis.insert(qout.front());
                    ans++;
                    qout.pop();
                }

                else qout.pop();
            }

            qout.pop();
        }

        else qin.pop();
        
    }

    cout<<ans<<endl;

    

}