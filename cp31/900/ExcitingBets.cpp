#include<bits/stdc++.h>
using namespace std;


//gcd(a,b) == gcd(a-b,b)..... if a>b....since a-b is constant ....=> find maximum of gcd(a-b,b)...where b is variable and a-b is constant....a>b
//=> gcd(a-b,b) <= min( a-b ,b)

// => maximum value of gcd(a,b) = gcd(a-b,b) = |a-b|
// for minimum steps ......fin k such that k(a-b) = b....so that gcd(a-b,b) = gcd(a-b , k(a-b)) = a-b
// let g = a-b => b%g is distance from closest multiple of g from b....ex = 5%3 = 2 ...i.e. 5 is closer to 3 and 6..more to 6
// => we choose min( b%g , g - b%g) ex = 5%3 = 2...3 - 5%3 =1.....min distanceof 5 from a multiple of 3 is 1....which gives steps

int main(){
  int t;
  cin>>t;
  while(t--){
    long long x,y;
    cin>>x>>y; 

    long long a = max(x,y);
    long long b = min(x,y);

    if(a==b) {
      cout<<0<<" "<<0<<endl;
      continue;
    }

    else{
      long long g = a-b;
      long long steps = min(b%g , g - b%g);
      cout<<g<<" "<<steps<<endl;
    }
    

  }
}