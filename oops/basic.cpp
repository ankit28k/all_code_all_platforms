#include <bits/stdc++.h>
using namespace std;


//encapsulation
class Teacher{
public:

//attributes / properties
  string name;
  string dept;
  string subject;
  double salary;


  //methods / functions
  void changedept(string newdept){
    dept = newdept;
  }

};

int main(){

  Teacher t1;
  t1.name  = "Ankit";
  t1.dept = "CSE";
  t1.subject = "Data Structures";

  cout << t1.name << endl;
  cout << t1.dept << endl;
  

}