#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name;
    int id;
    double gpa;
};

Student highest_gpa(vector<Student> &students, int start, int end);

int main()
{
    vector<Student> students = {
        {"Alice", 101, 3.98},
        {"Bob", 102, 4.00},
        {"Charlie", 103, 2.50}};

    Student topper = highest_gpa(students, 0, students.size() - 1);

    cout << "Student with highest CGPA:" << endl;
    cout << "Name: " << topper.name << endl;
    cout << "ID: " << topper.id << endl;
    cout << "CGPA: " << topper.gpa << endl;
}

Student highest_gpa(vector<Student> &students, int start, int end)
{
    //base case
    if(start == end) return students[start];
    int mid = (start + end) / 2;
    Student left, right;
    left = highest_gpa(students, start, mid);
    right = highest_gpa(students, mid + 1, end);

    if(left.gpa >= right.gpa) 
        return left;
    else return right;    
}
