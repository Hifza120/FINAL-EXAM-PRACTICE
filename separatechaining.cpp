#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
    int rollno;

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

class SeparateChaining {
    const int size = 101; // Size of hash table (array)
    list<Student> *lists[101]; // Array of list pointers

public:
    SeparateChaining() {
        // Initialize each list in the array to a new list
        for (int i = 0; i < size; i++) {
            lists[i] = new list<Student>; // Create a new list at each index
        }
    }

    void add(string &name, int marks, int rollno) {
        Student S1;
        S1.name = name;
        S1.marks = marks;
        S1.rollno = rollno;

        int index = rollno % size; // Hash function to find the index
        lists[index]->push_back(S1); // Add the student to the list at that index
    }

    void display(int rollno) {
        int index = rollno % size;
        for (auto &student : *lists[index]) {
            if (student.rollno == rollno) {
                cout << student;
                return;
            }
        }
        cout << "Student not found!" << endl;
    }
};

int main() {
    SeparateChaining hashTable;

    string name = "Alice";
    hashTable.add(name, 85, 101);

    name = "Bob";
    hashTable.add(name, 92, 102);

    name = "Charlie";
    hashTable.add(name, 78, 103);

    cout << "Displaying student with rollno 102:" << endl;
    hashTable.display(102);

    return 0;
}
