#include "student.h"
int main()
{
    int choice;
    vector<Student> students;
    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            if (addStudent(students))
                return 1; // Error handling for addStudent
            cout << "���ѧ����Ϣ�ɹ�\n";
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
            sortStudents();
            break;
        case 0:
            cout << "�˳�ϵͳ\n";
            break;
        default:
            cout << "�������������\n";
            break;
        }
    } while (choice != 0);
    return 0;
}