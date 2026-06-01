#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        int cnt =0,ans=0;
        long long suml=arr[0],sumr=arr[n-1];

        for(int i=0,j=n-1;i<j;){

            if(suml==sumr){

                cnt = n-j;
                cnt+= i+1;
                ans = max(ans,cnt);

                i++;
                j--;

                suml += arr[i];
                sumr += arr[j];
                
            }

            else if(suml>sumr){
                j--;
                sumr+=arr[j];
            }
            else{
                i++;
                suml +=arr[i];
            }

        }

        cout<<ans<<endl;
    }

    

}