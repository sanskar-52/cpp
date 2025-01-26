#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    double *Cgpa_ptr;

    // Student(string name,double cgpa){
    //     this->name = name;
    //     this->cgpa = cgpa;
    // }
    
    Student(string name,double cgpa){
        this->name = name;
        Cgpa_ptr = new double;
        *(this->Cgpa_ptr) = cgpa;

    }
    //custom copy-constructor
    Student(Student &obj){
        this->name = obj.name;
        this->Cgpa_ptr = new double;
        *(this->Cgpa_ptr) = *(obj.Cgpa_ptr);
    }

    //destructor
    ~Student(){
        cout << "THis is DEStructor speaking" << endl;
        delete Cgpa_ptr;
    }

    void print_info(){
        cout << "name : " << name << endl;
        cout << "cgpa : " << (*Cgpa_ptr) <<endl;
    }

};

int main(){

    //Student s1;
    
    Student s1("rahul kumar", 5.6 );
    Student s2(s1);
    s2.name = "neha kumari";
    
    s1.print_info();
    *(s2.Cgpa_ptr) = 9.3;
    s2.print_info();
    s1.print_info();

    return 0;
}