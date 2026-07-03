#include<bits/stdc++.h>
using namespace std;

string fun(string& s,int n,int a,int b,int pcnt,int ncnt){

    if(pcnt==ncnt) return "YES";
    if(a==b)return "NO";

    if(pcnt>ncnt){
        long long mini = min(a,b) , maxi = max(a,b);

        // while(pcnt>0 && ncnt>0){
        //     if(1LL*mini*pcnt == 1LL*maxi*ncnt) return "YES"; 
        //     pcnt--;
        //     ncnt--;
        // }

        // mini*(p-k) == maxi(n-k) 
        //if((maxi*ncnt - mini*pcnt )%(maxi-mini) == 0) return "YES"; // it allows diff<0 

        /* Why check diff >= 0? 
        'mini * pcnt' is the smallest total we can add.
        'maxi * ncnt' is the largest total we can subtract.

        If (maxi * ncnt) < (mini * pcnt), then diff < 0. This means the additions 
        are so large that even the maximum possible subtractions cannot compensate 
        them. The score will forever remain above 0.

        Example of diff < 0:
        Let pcnt = 5 (+ appears 5 times) and ncnt = 1 (- appears 1 time).
        Let the buttons be 10 and 20. So, mini = 10, maxi = 20.
        Smallest possible addition = 10 * 5 = 50.
        Largest possible subtraction = 20 * 1 = 20.
        The absolute lowest final score we can physically get is 50 - 20 = 30.
        Since the lowest score is 30, we can never reach exactly 0. 
        Our formula gives: diff = 20 - 50 = -30. Because diff < 0, it correctly rejects this impossible case!
        */

        long long diff = maxi*ncnt - mini*pcnt;
        if(diff>=0 && diff%(maxi- mini)==0) return "YES";
        return "NO";

    }

    else{

        long long mini = min(a,b) , maxi = max(a,b);

        // while(pcnt>0 && ncnt>0){
        //     if(1LL*mini*ncnt == 1LL*maxi*pcnt) return "YES";
        //     pcnt--;
        //     ncnt--;
        // }

        // mini*(n-k) == maxi(p-k) 
        // if((maxi*pcnt - mini*ncnt)%(maxi-mini) == 0) return "YES";

        long long diff = maxi*pcnt - mini*ncnt;
        if(diff>=0 && diff%(maxi-mini)==0) return "YES";
        return "NO";

    }
}

int main(){

    int n;
    cin>>n;
    string s;
    cin>>s;

    int pcnt=0,ncnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+') pcnt++;
        if(s[i]=='-') ncnt++;
    }

    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<fun(s,n,a,b,pcnt,ncnt)<<endl;
    }


}