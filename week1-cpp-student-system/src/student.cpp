#include "student.h"

void showMenu()
{
    cout << "====学生信息管理系统====\n";
    cout << "1.添加学生信息\n";
    cout << "2.显示全部学生信息\n";
    cout << "3.删除学生信息\n";
    cout << "4.查找学生信息\n";
    cout << "5.排序学生信息\n";
    cout << "0.退出系统\n";
}
int addStudent(vector<Student> &students)
{
    cout << "需要添加学生的数量：\n";
    int num;
    cin >> num;
    for (int i = 1; i <= num; ++i)
    {
        Student student;
        cout << "姓名：\n";
        cin >> student.name;
        cout << "学号：\n";
        cin >> student.id;
        cout << "年龄：\n";
        cin >> student.age;
        cout << "分数：\n";
        cin >> student.score;
        students.push_back(student);
    }
    fstream file("students.txt", ios::out | ios::app);
    if (!file)
    {
        cerr << "无法打开文件\n";
        return 1;
    }
    for (const auto &student : students)
    {
        file << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
    }
    file.close();
    return 0;
}
void showStudents(const vector<Student> &students)
{
    cout << "学生信息如下：\n";
    ;
    fstream file("students.txt", ios::in);
    if (!file)
    {
        cerr << "无法打开文件\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name >> student.age >> student.score;
        cout << " 学号：" << student.id << " 姓名：" << student.name
             << " 年龄：" << student.age << " 分数：" << student.score << "\n";
        iss.clear();
        iss.str(""); // Clear the string stream for the next line
    }
}
void deleteStudent(vector<Student> &students)
{
    cout << "请输入要删除的学生学号：\n";
    string id;
    cin >> id;
    auto it = remove_if(students.begin(), students.end(), [&id](const Student &s)
                        { return s.id == id; });
    if (it != students.end())
    {
        students.erase(it, students.end());
        fstream file("students.txt", ios::out | ios::trunc);
        if (!file)
        {
            cerr << "无法打开文件\n";
            return;
        }
        for (const auto &student : students)
        {
            file << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
        }
        cout << "删除成功\n";
    }
    else
    {
        cout << "未找到该学生信息\n";
    }
}
void findStudent(vector<Student> &students)
{
    students.clear();
    fstream file("students.txt", ios::in);
    if (!file)
    {
        cerr << "无法打开文件\n";
        return;
    }
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name >> student.age >> student.score;
        students.push_back(student);
        iss.clear();
        iss.str("");
    }
    cout << "请输入要查找的学生学号：\n";
    string id;
    cin >> id;
    auto it = find_if(students.cbegin(), students.cend(), [&id](const Student &s)
                      { return s.id == id; });
    if (it != students.cend())
    {
        cout << "学号：" << it->id << " 姓名：" << it->name
             << " 年龄：" << it->age << " 分数：" << it->score << "\n";
    }
    else
    {
        cout << "未找到该学生信息\n";
    }
}
void sortMenu()
{
    cout << "====排序菜单====\n";
    cout << "1.按学号升序排序\n";
    cout << "2.按学号降序排序\n";
    cout << "3.按姓名字典序排序\n";
}
void sortStudents()
{
    int sortChoice;
    cout << "请选择排序方式：\n";
    cin >> sortChoice;
    fstream file("students.txt", ios::in);
    if (!file)
    {
        cerr << "无法打开文件\n";
        return;
    }
    vector<Student> students;
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name >> student.age >> student.score;
        students.push_back(student);
        iss.clear();
        iss.str("");
    }
    switch (sortChoice)
    {
    case 1:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.id < b.id; });
        {
            fstream outFile("students.txt", ios::out | ios::trunc);
            if (!outFile)
            {
                cerr << "无法打开文件\n";
                return;
            }
            for (const auto &student : students)
            {
                outFile << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
            }
        }
        cout << "按学号升序排序成功\n";
        break;
    case 2:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.id > b.id; });
        {
            fstream outFile("students.txt", ios::out | ios::trunc);
            if (!outFile)
            {
                cerr << "无法打开文件\n";
                return;
            }
            for (const auto &student : students)
            {
                outFile << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
            }
        }
        cout << "按学号降序排序成功\n";
        break;
    case 3:
        std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
                  { return a.name < b.name; });
        {
            fstream outFile("students.txt", ios::out | ios::trunc);
            if (!outFile)
            {
                cerr << "无法打开文件\n";
                return;
            }
            for (const auto &student : students)
            {
                outFile << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
            }
        }
        cout << "按姓名字典序排序成功\n";
        break;
    }
}
