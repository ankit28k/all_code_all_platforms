#include<bits/stdc++.h>
using namespace std;

bool checkfair(long long n){

    long long temp =n;
    
    while(temp){
        int ld=temp%10;
        if(ld!=0){
            if(n%ld != 0) return false;
        }
        temp= temp/10; 
    }

    return true;
}

//brute force works as lcm(1,2....9) = 2520.....so maximum number = 2520k k-> 0,1,2,......so maximum value to add is 2520...
//TC = 18 * 2520 * 10^3 => n(number length) * k(while loop) * t
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n; 

        while(!checkfair(n)) n++;
        cout<<n<<endl;

    }

}