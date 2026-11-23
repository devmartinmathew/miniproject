#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:

    // Parameterized Constructor
    Student(int r, string n, float m)
    {
        rollNo = r;
        name = n;
        marks = -1;

        setMarks(m);
    }

    // Getter functions
    int getRollNo()
    {
        return rollNo;
    }

    string getName()
    {
        return name;
    }

    float getMarks()
    {
        return marks;
    }

    // Set marks with validation
    void setMarks(float m)
    {
        if (m >= 0 && m <= 100)
        {
            marks = m;
        }
        else
        {
            cout << "Invalid marks! Enter marks between 0 and 100.\n";
        }
    }

    // Display function
    void display()
    {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
    }
};

// Function accepting an object
void printResult(Student s)
{
    cout << "\n\n----- STUDENT RESULT -----";
    cout << "\nRoll Number: " << s.getRollNo();
    cout << "\nName: " << s.getName();
    cout << "\nMarks: " << s.getMarks();

    if (s.getMarks() >= 40)
        cout << "\nResult: PASS";
    else
        cout << "\nResult: FAIL";

    cout << "\n--------------------------\n";
}

int main()
{
    int roll;
    string name;
    float marks;

    // Array of objects
    Student batch[3] = {
        Student(1, "Student1", 0),
        Student(2, "Student2", 0),
        Student(3, "Student3", 0)
    };

    // Get student details
    for (int i = 0; i < 3; i++)
    {
        cout << "\nEnter details of Student " << i + 1;

        cout << "\nEnter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        batch[i] = Student(roll, name, marks);

        // Reject invalid marks
        while (batch[i].getMarks() == -1)
        {
            cout << "Enter valid marks: ";
            cin >> marks;
            batch[i].setMarks(marks);
        }
    }

    // Re-evaluation
    for (int i = 0; i < 3; i++)
    {
        char choice;

        cout << "\nRe-evaluate " << batch[i].getName() << "? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Enter new marks: ";
            cin >> marks;

            batch[i].setMarks(marks);

            while (batch[i].getMarks() == -1)
            {
                cout << "Enter valid marks: ";
                cin >> marks;
                batch[i].setMarks(marks);
            }
        }
    }

    // Print all results
    for (int i = 0; i < 3; i++)
    {
        printResult(batch[i]);
    }

    return 0;
}