#include <bits/stdc++.h>
using namespace std;


//encapsulation
class Teacher{

//data hiding
private: //default   
  double salary;


public: 
  string name;
  string dept;
  string subject;
   
  void changedept(string newdept){
    dept = newdept;
  }

  //setter
  void setsalary(double s){
    salary = s;
  }

  //getter
  double getsalary(){
    return salary;
  }

};

int main(){

  Teacher t1;
  t1.name  = "Ankit";
  t1.dept = "CSE";
  t1.subject = "Data Structures";
  t1.setsalary(50000.0);

  cout << t1.name << endl;
  cout << t1.dept << endl;
  cout << t1.getsalary() << endl;
  

}