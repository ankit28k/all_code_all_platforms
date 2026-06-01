#include<bits/stdc++.h>
using namespace std;

bool comp (int a,int b){
    return a>b;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> inf(m);
        for(int i=0;i<m;i++) cin>>inf[i];

        sort(inf.begin(), inf.end());
        
        vector<int> nodes;
        nodes.push_back(n - inf[m-1] + inf[0] - 1); // nodes from last infected to first infected (circular)
        for(int i=1;i<m;i++){
            nodes.push_back(inf[i] - inf[i-1] - 1); // nodes between consecutive infected
        }

        sort(nodes.begin(),nodes.end(),comp); 

        int saved=0;

        int days = 0;

        //every day, the number of infected people becomes twice. Hence number of infected is equals to 2*days. Now the uninfected are left
        //which are total nodes - Infected....... Check if uninfected >0.... Then save the first one...... Again, 2 become infected ;
        //In which one is saved ..... Now check if uninfected left which all are saved by saving the extreme left person....

        for(int i=0;i<nodes.size();i++){

            int noofinf = 2*days;

            int uninf = nodes[i] - noofinf;

            if(uninf>0){
                saved++;

                uninf -=2;

                if(uninf>0) saved += uninf;
                days +=2;


            }
        } 

        //fails if only 1 uninfected....etc
        // int sum=0 , j=1;

        // for(int i=0;i<nodes.size();i++){
            
        //     if(nodes[i] > (2*j - 1)){
        //         sum += nodes[i] - (2*j - 1) ; //nodes[i]/2 - 0 + nodes[i]/2 -1....protect first from one side...then second from other side
        //         j+=2; 
        //     } 
        //     else break;

        // } 
        // cout<<n-sum<<endl;

        cout<<n-saved<<endl;
    }

}