#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string id;
    string name;
    int age;
    float score;
};
void showMenu()
{
    cout << "====学生信息管理系统====\n";
    cout << "1.添加学生信息\n";
    cout << "2.显示全部学生信息\n";
    cout << "0.退出系统\n";
}
int main()
{
    int choice;
    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:

            break;
        case 2:

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