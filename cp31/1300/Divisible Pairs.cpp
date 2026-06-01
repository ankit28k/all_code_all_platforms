#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];


        // TC -> O()
        map<int,vector<int>> my;

        for(int i=0;i<n;i++){   
            my[arr[i]%y].push_back(arr[i]);  //as a[i]%y == a[j]%y
        }

        long long ans =0;
        for(auto it :my){
            //vector<int> temp = it.second;
            
            if(it.second.size() <= 1) continue;

            map<int,int> fx;

            for(int a :it.second) {  
                fx[a%x]++; 
            }

            set<int> vis;

            for(auto i:fx){

                int el = i.first ;

                if(el == x - el || el == 0) { // like (2,2)....and if 0...no need of other
                    if(vis.find(el) == vis.end() ){
                        ans += 1LL*fx[el]*(fx[el]-1)/2; //nc2
                        vis.insert(el);
                        vis.insert(x-el) ;
                    }
                }

                else{
                    if(vis.find(el) == vis.end() && vis.find(x - el) == vis.end()){
                        ans += 1LL*fx[el]*fx[x-el]; // a[i]%x == x - a[j]%x......choosing any 1 from both i.e. nc1*nc1
                        vis.insert(el);
                        vis.insert(x-el) ;
                    }
                }
                
            }
        }
        
        cout<<ans<<endl;
         

    }

}