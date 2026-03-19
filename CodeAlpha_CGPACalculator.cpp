#include <iostream>
using namespace std;

class Course {
private:
    float grade;
    int creditHours;

public:
    void inputCourse() {
        cout << "Enter Grade Point: ";
        cin >> grade;

        cout << "Enter Credit Hours: ";
        cin >> creditHours;
    }

    float getGradePoints() {
        return grade * creditHours;
    }

    int getCredits() {
        return creditHours;
    }

    string getLetterGrade() {
        if (grade == 4.0) return "A";
        else if (grade >= 3.7) 
        return "A-";
        else if (grade >= 3.3) 
        return "B+";
        else if (grade >= 3.0) 
        return "B";
        else if (grade >= 2.7) 
        return "B-";
        else if (grade >= 2.3) 
        return "C+";
        else if (grade >= 2.0) 
        return "C";
        else if (grade >= 1.7) 
        return "C-";
        else if (grade >= 1.0) 
        return "D";
        else 
        return "F";
    }

    void displayCourse(int i) {
        cout << "Course " << i+1
             << " -> GPA: " << grade
             << " | Grade: " << getLetterGrade()
             << " | Credit Hours: " << creditHours
             << " | Grade Points: " << getGradePoints()
             << endl;
    }
};

class CGPACalculator {
private:
    int semesters;

public:
    void calculate() {
        cout << "Enter number of semesters: ";
        cin >> semesters;

        float overallCredits = 0;
        float overallGradePoints = 0;

        for(int s = 0; s < semesters; s++) {
            cout << " ===== Semester " << s+1 << " ===== " << endl;

            int numCourses;
            cout << "Enter number of courses: ";
            cin >> numCourses;

            Course c[100];

            float semCredits = 0;
            float semGradePoints = 0;

            for(int i = 0; i < numCourses; i++) {
                cout << " Course " << i+1 << endl;
                c[i].inputCourse();

                semCredits += c[i].getCredits();
                semGradePoints += c[i].getGradePoints();
            }

            cout << "----- Semester " << s+1 << " Courses -----";
            for(int i = 0; i < numCourses; i++) {
                c[i].displayCourse(i);
            }

            float sgpa = semGradePoints / semCredits;

            cout << "Semester " << s+1 << " SGPA: " << sgpa << endl;

            overallCredits += semCredits;
            overallGradePoints += semGradePoints;
        }

        float cgpa = overallGradePoints / overallCredits;

        cout << "===== FINAL RESULT =====";
        cout << "Total Credits: " << overallCredits << endl;
        cout << "Total Grade Points: " << overallGradePoints << endl;
        cout << "Final CGPA: " << cgpa << endl;
    }
};

int main() {
    CGPACalculator cgpa;
    cgpa.calculate();

    return 0;
}