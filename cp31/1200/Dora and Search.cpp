#include<bits/stdc++.h>
using namespace std;

//hint - What happens if none of the endpoints are min or max?

pair<int,int> fun(vector<int>& arr,int n){

    int i=0,j=n-1 , cmin = 1 , cmax = n;
    while(i<j){

        if(arr[i] == cmin || arr[i] == cmax || arr[j] == cmax || arr[j] == cmin){

            if(arr[i] == cmin){
                i++;
                cmin++;
            }

            else if(arr[i] == cmax){
                i++;
                cmax--;
            }

            else if(arr[j] == cmax){
                j--;
                cmax--;
            }

            else if(arr[j] == cmin){
                j--;
                cmin++;
            }
        }  

        else break;
    }   

    if(i==j) return {-1,-1};
    return {i+1,j+1};

    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        pair<int,int> p = fun(arr,n);

        if(p.first == -1) cout<<-1<<endl;
        else cout<<p.first<<" "<<p.second<<endl;
    }

}