#include "student.h"
int main()
{
    int choice;
    vector<Student> students;
    loadStudents(students);
    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            showStudents(students);
            break;
        case 3:
            deleteStudent(students);
            break;
        case 4:
            findStudent(students);
            break;
        case 5:
            sortMenu();
            sortStudents(students);
            break;
        case 0:
            cout << "退出系统\n";
            break;
        default:
            cout << "输入错误请重试\n";
            break;
        }
    } while (choice != 0);
    return 0;
}