#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function to convert letter grade into grade points
double getGradePoint(string grade)
{
    if (grade == "A+" || grade == "A")
        return 4.0;
    else if (grade == "A-")
        return 3.7;
    else if (grade == "B+")
        return 3.3;
    else if (grade == "B")
        return 3.0;
    else if (grade == "B-")
        return 2.7;
    else if (grade == "C+")
        return 2.3;
    else if (grade == "C")
        return 2.0;
    else if (grade == "C-")
        return 1.7;
    else if (grade == "D+")
        return 1.3;
    else if (grade == "D")
        return 1.0;
    else
        return 0.0; // F
}

int main()
{
    int numCourses;

    cout << "======================================" << endl;
    cout << "         CGPA CALCULATOR" << endl;
    cout << "======================================" << endl;

    // Input number of courses
    cout << "Enter Number of Courses: ";
    cin >> numCourses;

    string grades[100];
    double credits[100];
    double gradePoints[100];

    double totalCredits = 0.0;
    double totalGradePoints = 0.0;

    // Input details for each course
    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
        cin >> grades[i];

        cout << "Enter Credit Hours: ";
        cin >> credits[i];

        // Convert grade to grade point
        gradePoints[i] = getGradePoint(grades[i]);

        // Calculate totals
        totalCredits += credits[i];
        totalGradePoints += gradePoints[i] * credits[i];
    }

    // Semester GPA
    double semesterGPA = totalGradePoints / totalCredits;

    // Previous record for overall CGPA
    double previousCGPA;
    double previousCredits;

    cout << "\nEnter Previous CGPA (0 if First Semester): ";
    cin >> previousCGPA;

    cout << "Enter Previous Completed Credit Hours (0 if First Semester): ";
    cin >> previousCredits;

    double overallCGPA;

    if (previousCredits == 0)
    {
        overallCGPA = semesterGPA;
    }
    else
    {
        overallCGPA = ((previousCGPA * previousCredits) + totalGradePoints) /
                      (previousCredits + totalCredits);
    }

    // Display Results
    cout << fixed << setprecision(2);

    cout << "\n======================================";
    cout << "\n          COURSE DETAILS";
    cout << "\n======================================";

    for (int i = 0; i < numCourses; i++)
    {
        cout << "\nCourse " << i + 1 << endl;
        cout << "Grade        : " << grades[i] << endl;
        cout << "Credit Hours : " << credits[i] << endl;
        cout << "Grade Point  : " << gradePoints[i] << endl;
    }

    cout << "\n======================================";
    cout << "\nTotal Credits      : " << totalCredits;
    cout << "\nTotal Grade Points : " << totalGradePoints;
    cout << "\nSemester GPA       : " << semesterGPA;
    cout << "\nOverall CGPA       : " << overallCGPA;
    cout << "\n======================================";

    return 0;
}