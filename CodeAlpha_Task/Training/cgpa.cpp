#include <iostream>
using namespace std;

int main(){
    int n; //no. of courses
    string sub[20];
    int grade[20];
    int credit[20];
    int TotalCredits = 0, TotalGrades = 0;
    float cgpa = 0;

    cout << "Enter the no. of subjects: ";
    cin >> n;

    cout << "Name all the subjects, Grades(out of 100) and Credit:- \n";
    for(int i = 0; i < n; i++){
        cout << i+1 << ". ";
        cin >> sub[i];
        cout << "   Marks: ";
        cin >> grade[i];
        cout << "   Credit: ";
        cin >> credit[i]; 

        TotalCredits += credit[i];
        TotalGrades += grade[i] * credit[i];  //Credit GPA
    }

    cgpa = (float)TotalGrades / (TotalCredits * 10);
    
    for(int i = 0; i < n; i++){
        cout << i+1 << ". " << sub[i] << ":- Grades: " << grade[i] << " & Credit: " << credit[i] <<endl;
    }
    cout << "CGPA is " << cgpa;
    return 0;
}