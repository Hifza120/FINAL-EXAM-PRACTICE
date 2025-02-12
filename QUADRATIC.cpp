#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    int rollno;
 Student(){
     name="";
     marks=-100;
     rollno=-101;
 }
    bool operator==(const Student& S1) const {
        return rollno == S1.rollno;
    }

    friend ostream& operator<<(ostream &s, const Student &S1) {
        s << "Name: " << S1.name << endl;
        s << "Marks: " << S1.marks << endl;
        s << "Rollno: " << S1.rollno << endl;
        return s;
    }
};

class Quadratic {
    const int size;
    Student *students; // Array of list pointers
int HashFunction(int rollno){
    for(int i=0;i<size;i++){
        int index=(rollno+i*i)%size;
        //where -101 represent empty;
        //where -404 represent Deleted
        if(students[index].rollno==-101||students[index].rollno==-404){
            return index;
        }
    }
    return -1;
}
public:
Quadratic():size(101){
    students=new Student[size];
}
    void add(string &name, int marks, int rollno) {
        Student S1;
        S1.name = name;
        S1.marks = marks;
        S1.rollno = rollno;
    int index=HashFunction(rollno);
    if(index!=-1){
        students[index]=S1;
    }
    }
     bool Delete(int rollno){
    int index=0;
         for(int i=0;i<size;i++){
          index=(rollno+i*i)%size;
             if(students[index].rollno==rollno){
                 students[index].rollno=-404;
                 return true;
             }
             if(students[index].rollno==-101){
                 return false;
             }
         }
         return false;
     }
     void display(int rollno){
     int index=0;
         for(int i=0;i<size;i++){
          index=(rollno+i*i)%size;
             if(students[index].rollno==rollno){
                 cout<<students[index]<<endl;
                 break;
             }
             if(students[index].rollno==-101){
                 cout<<"ITS NOt Found"<<endl;
                 break;
             }
         }

     }
};

int main() {
    Quadratic hashTable;

    string name = "Alice";
    hashTable.add(name, 85, 101);

    name = "Bob";
    hashTable.add(name, 92, 102);

    name = "Charlie";
    hashTable.add(name, 78, 103);

    cout << "Displaying student with rollno 102:" << endl;
    hashTable.display(102);

    hashTable.Delete(102);
        cout << "Displaying student with rollno 102:" << endl;
    hashTable.display(102);

    return 0;
}
