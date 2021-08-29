#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<double, string> a, pair<double, string> b)
{
    return a.first < b.first;
}
class StudentInfo
{
    const string name;
    double courses[14];
    const int number_of_courses;
    const int id;
    static int total_student;

public:
    StudentInfo(int idinp, string nameinp, int no_course, double result[]) : id(idinp), name(nameinp), number_of_courses(no_course)
    {
        total_student++;
        for (int i = 0; i < number_of_courses; i++)
            courses[i] = result[i];
    }
    friend class ResultService;
};
int StudentInfo::total_student = 0;
class ResultService
{
public:
    static int CalculateAvgResult(StudentInfo student)
    {
        double sum = 0;
        for (int i = 0; i < student.number_of_courses; i++)
            sum += student.courses[i];
        return sum / student.number_of_courses;
    }
    static void SortStudent(StudentInfo student[])
    {

        pair<double, string> arr[StudentInfo::total_student];
        for (int i = 0; i < StudentInfo::total_student; i++)
        {
            arr[i].first = CalculateAvgResult(student[i]);
            arr[i].second = student[i].name;
        }
        sort(arr, arr + StudentInfo::total_student, comparator);
        for (int i = 0; i < StudentInfo::total_student; i++)
        {
            cout << arr[i].second << endl;
        }
    }
};

int main()
{
    string nam = "arko";
    double arr[14] = {1, 2, 3, 4, 5};
    StudentInfo x(141, nam, 5, arr);
    ResultService::CalculateAvgResult(x);
}
