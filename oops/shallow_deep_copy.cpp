#include <bits/stdc++.h>
using namespace std;


 
class Student{ 
public: 
  string name;
  // double cgpa;
  double* cgpaPtr;

  Student(string name , double cgpa){
    this->name = name;
    // this->cgpa = cgpa;
    cgpaPtr = new double; // allocate memory for cgpa  
    *cgpaPtr = cgpa; // assign value to cgpa
  }

  void getinfo(){
    cout << "Name: " << name << endl;
    // cout << "CGPA: " << cgpa << endl;
    cout << "CGPA: " << *cgpaPtr << endl; // access value using pointer
  }
   
};

int main(){

  Student s1("Ankit",7.72);
  s1.getinfo();

  Student s2(s1);
  s2.getinfo();

}