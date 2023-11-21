#include<iostream>
using namespace std;

class student;

class GradeCalculator {
public:
    static double calculateAverage(const student&);
};

class student
{
    string name;
    int roll;
    double score[10];
    int subjectCount;

public:
    double avg;

    void getdetails()
    {
        cout << "Enter name:";
        cin >> name;
        cout << endl;
        cout << "ENTER roll number:";
        cin >> roll;
        cout << endl;
        cout << "Enter number of subjects:";
        cin >> subjectCount;
        cout << endl;
    }

    void setscore()
    {
        for (int i = 0; i < subjectCount; i++)
        {
            cout << "Enter subject " << i + 1 << " score" << endl;
            cin >> score[i];
        }
    }

    void calculateGrade()
    {
        avg = GradeCalculator::calculateAverage(*this);
    }

    void printGrade()
    {
        if (avg >= 90)
        {
            cout << "Grade: A+" << endl;
        }
        else if (avg >= 80 && avg < 90)
        {
            cout << "Grade: A" << endl;
        }
        else if (avg >= 65 && avg < 80)
        {
            cout << "Grade: B" << endl;
        }
        else if (avg >= 40 && avg < 65)
        {
            cout << "Grade: C" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }

    friend class GradeCalculator;
};

double GradeCalculator::calculateAverage(const student& s)
{
    double sum = 0;
    for (int i = 0; i < s.subjectCount; i++)
    {
        sum += s.score[i];
    }
    return sum / s.subjectCount;
}

int main()
{
    student S;
    S.getdetails();
    S.setscore();
    S.calculateGrade();
    S.printGrade();

    return 0;
}
