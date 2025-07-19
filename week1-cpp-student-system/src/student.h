#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

struct Student
{
    string id;
    string name;
    int age;
    float score;
};

void showMenu();
void loadStudents(vector<Student> &students);
void saveStudents(const vector<Student> &students);
void addStudent(vector<Student> &students);
void showStudents(const vector<Student> &students);
void deleteStudent(vector<Student> &students);
void findStudent(const vector<Student> &students);
void sortMenu();
void sortStudents(vector<Student> &students);