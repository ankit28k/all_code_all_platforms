#include<bits/stdc++.h>
using namespace std;
int main(){
     
    int lx = 0,ly=0,hx = 1e9,hy=1e9;

    while(true){
        int my = ly + (hy-ly)/2;
        int mx = lx + (hx-lx)/2;

        cout<<"?"<<" "<<mx<<" "<<my<<endl;
        string s;
        cin>>s;
        if(s == "LEFT") hx = mx-1;
        else if(s == "RIGHT") lx = mx+1;
        else if(s == "UP") ly = my + 1;
        else if(s == "DOWN") hy = my-1;

        else if(s == "LEFT_UP"){
            hx = mx-1;
            ly = my + 1;
        }
        else if(s == "RIGHT_UP"){
            lx = mx+1;
            ly = my + 1;
        }
        else if(s == "LEFT_DOWN"){
            hx = mx-1;
            hy = my-1;
        }
        else if(s == "RIGHT_DOWN"){
            lx = mx+1;
            hy = my-1;
        }
        else {
            cout<<"!"<<" "<<mx<<" "<<my<<endl;
            break;
        }

    }

    

}