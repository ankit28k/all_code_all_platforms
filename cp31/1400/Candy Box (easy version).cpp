#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);

        map<int,int> m;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            m[arr[i]]++;
        }

        vector<int> temp;
        for(auto it = m.begin();it!=m.end();it++) temp.push_back(it->second); 
        
        sort(temp.begin(),temp.end()); 

        set<int> st;

        int t=temp.size();
        long long sum= temp[t-1];
        st.insert(temp[t-1]);

        for(int i=temp.size()-2;i>=0;i--){

            if(st.find(temp[i]) == st.end()){
                sum+=temp[i];
                st.insert(temp[i]);
            }

            else if( st.find(temp[i]) != st.end()){

                if(temp[i+1]-1 >0){
                    temp[i]  =temp[i+1]-1;
                    sum+=temp[i];
                    st.insert(temp[i]);
                }
                else break;    
            } 
            
        }

        cout<<sum<<endl; 
        
    }

}