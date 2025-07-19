#include "student.h"

void showMenu()
{
    cout << "====ѧ����Ϣ����ϵͳ====\n";
    cout << "1.���ѧ����Ϣ\n";
    cout << "2.��ʾȫ��ѧ����Ϣ\n";
    cout << "3.ɾ��ѧ����Ϣ\n";
    cout << "4.����ѧ����Ϣ\n";
    cout << "5.����ѧ����Ϣ\n";
    cout << "0.�˳�ϵͳ\n";
}

void loadStudents(vector<Student> &students)
{
    students.clear();
    fstream file("students.txt", ios::in);
    if (!file)
        return;
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Student student;
        iss >> student.id >> student.name >> student.age >> student.score;
        students.push_back(student);
    }
    file.close();
}

void saveStudents(const vector<Student> &students)
{
    fstream file("students.txt", ios::out | ios::trunc);
    for (const auto &student : students)
    {
        file << student.id << " " << student.name << " " << student.age << " " << student.score << "\n";
    }
    file.close();
}

void addStudent(vector<Student> &students)
{
    cout << "��Ҫ���ѧ����������\n";
    int num;
    cin >> num;
    for (int i = 1; i <= num; ++i)
    {
        Student student;
        cout << "������\n";
        cin >> student.name;
        cout << "ѧ�ţ�\n";
        cin >> student.id;
        cout << "���䣺\n";
        cin >> student.age;
        cout << "������\n";
        cin >> student.score;
        students.push_back(student);
    }
    saveStudents(students);
    cout << "���ѧ����Ϣ�ɹ�\n";
}

void showStudents(const vector<Student> &students)
{
    cout << "ѧ����Ϣ���£�\n";
    for (const auto &student : students)
    {
        cout << "ѧ�ţ�" << student.id << " ������" << student.name
             << " ���䣺" << student.age << " ������" << student.score << "\n";
    }
}

void deleteStudent(vector<Student> &students)
{
    cout << "������Ҫɾ����ѧ��ѧ�ţ�\n";
    string id;
    cin >> id;
    auto it = remove_if(students.begin(), students.end(), [&id](const Student &s)
                        { return s.id == id; });
    if (it != students.end())
    {
        students.erase(it, students.end());
        saveStudents(students);
        cout << "ɾ���ɹ�\n";
    }
    else
    {
        cout << "δ�ҵ���ѧ����Ϣ\n";
    }
}

void findStudent(const vector<Student> &students)
{
    cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�\n";
    string id;
    cin >> id;
    auto it = find_if(students.cbegin(), students.cend(), [&id](const Student &s)
                      { return s.id == id; });
    if (it != students.cend())
    {
        cout << "ѧ�ţ�" << it->id << " ������" << it->name
             << " ���䣺" << it->age << " ������" << it->score << "\n";
    }
    else
    {
        cout << "δ�ҵ���ѧ����Ϣ\n";
    }
}

void sortMenu()
{
    cout << "====����˵�====\n";
    cout << "1.��ѧ����������\n";
    cout << "2.��ѧ�Ž�������\n";
    cout << "3.�������ֵ�������\n";
}

void sortStudents(vector<Student> &students)
{
    int sortChoice;
    cout << "��ѡ������ʽ��\n";
    cin >> sortChoice;
    switch (sortChoice)
    {
    case 1:
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.id < b.id; });
        cout << "��ѧ����������ɹ�\n";
        break;
    case 2:
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.id > b.id; });
        cout << "��ѧ�Ž�������ɹ�\n";
        break;
    case 3:
        sort(students.begin(), students.end(), [](const Student &a, const Student &b)
             { return a.name < b.name; });
        cout << "�������ֵ�������ɹ�\n";
        break;
    }
    saveStudents(students);
}