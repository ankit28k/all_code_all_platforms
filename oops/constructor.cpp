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

  //non - parameterised
  Teacher(){ 
    cout<<"I am constructor"<<endl; // runs first when object created....same name as class and no return type

    dept = "CSE"; // default value using constructor
  }

  //parameterised
  Teacher(string name , string dept , string subject){ 
    cout<<"I am parameterised constructor"<<endl;

    this->name = name; //== *(this).name = name
    this->dept = dept;
    this->subject = subject;

    // name = n;  //string n , string d , string s
    // dept = d;
    // subject = s;
  }

// copy constructor
  Teacher(Teacher &orgObj){ // pass by reference

    cout<<"custom copy constructor"<<endl;
    this->name = orgObj.name;
    this->dept = orgObj.dept;
    this->subject = orgObj.subject;


  }
   
  void getinfo(){
    cout << name << endl;
    cout << dept << endl;
    cout << subject << endl;
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
  Teacher t2("Ank","CSE","DAA");

  t1.name  = "Ankit"; 
  t1.subject = "Data Structures";

  t1.setsalary(50000.0);

  t2.setsalary(60000.0);

  // cout << t1.name << endl;
  // cout << t1.dept << endl;
  // cout << t1.getsalary() << endl;

  Teacher t3(t2); // copy constructor  ....default if no copy constructor is defined
  t2.getinfo();
  t3.getinfo();
  

}