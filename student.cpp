#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int sub1,sub2,sub3,sub4,sub5;
public:
    Student(string name, int sub1, int sub2, int sub3, int sub4, int sub5);

    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
    }

    int getSub1() {
        return this->sub1;
    }
    void setSub1(int sub1) {
        this->sub1 = sub1;
    }


    int getSub2() {
        return this->sub2;
    }
    void setSub2(int sub2) {
        this->sub2 = sub2;
    }


    int getSub3() {
        return this->sub3;
    }
    void setSub3(int sub3) {
        this->sub3 = sub3;
    }


    int getSub4() {
        return this->sub4;
    }
    void setSub(int sub4) {
        this->sub4 = sub4;
    }


    int getSub5() {
        return this->sub5;
    }
    void setSub5(int sub5) {
        this->sub5 = sub5;
    }

    int totalMarks() {
        return sub1+sub2+sub3+sub4+sub5;
    }

    float averageMarks() {
        return totalMarks()/5;
    }

    char getGrade() {
        int avg = averageMarks();
        if (avg >= 90)
            return 'A';
        else if (avg >= 80)
            return 'B';
        else if (avg >= 60)
            return 'C';
        else if (avg >= 50)
            return 'D';
        else if (avg >= 30)
            return 'E';
        else
            return 'F';
        
    }

};

Student::Student(string name, int sub1, int sub2, int sub3, int sub4, int sub5)
{
    this->name = name;
    this->sub1 = sub1;
    this->sub2 = sub2;
    this->sub3 = sub3;
    this->sub4 = sub4;
    this->sub5 = sub5;    
}

int main(){
    string name;
    int sub1,sub2,sub3,sub4,sub5;
    cout<<"Enter Student Name: ";
    cin>>name;
    cout<<"Enter marks of subject 1: ";
    cin>>sub1;
    cout<<"Enter marks of subject 2: ";
    cin>>sub2;
    cout<<"Enter marks of subject 3: ";
    cin>>sub3;
    cout<<"Enter marks of subject 4: ";
    cin>>sub4;
    cout<<"Enter marks of subject 5: ";
    cin>>sub5;
    Student student = Student(name, sub1, sub2, sub3, sub4, sub5);
    cout<<endl;
    cout<<"Name: "<<student.getName()<<endl;
    cout<<"Total Marks: "<<student.totalMarks()<<endl;
    cout<<"Average Marks: "<<student.averageMarks()<<endl;
    cout<<"Grade: "<<student.getGrade()<<endl;
}