#include<bits/stdc++.h>
using namespace std;

string fun(int n){ 

    int k = n%10;
    n=n/10;

    while(n){
        if(n%10 != k) return "No";
        n=n/10;
    }
     

    return "Yes";
}
int main(){ 
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
    

}