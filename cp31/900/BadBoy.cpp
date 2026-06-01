#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,i,j;
        cin>>n>>m>>i>>j;

        //since all 4 directions its manhatten distance ie |x1-x2| + |y1-y2|...to maximize it....x1,y1 and x2,y2 must be far from ..i,j
        //hence choose extreme points n,m and 1,1
        cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
    }

}