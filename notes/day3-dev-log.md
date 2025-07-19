# 改进

## 1.学生信息未持久化到内存

在各函数内部新建 `vector<Student> students;` 这样每次操作都只对临时变量操作，没有同步到主程序的 `students` 容器，无法实现真正的增删改查。

可以选择新增一个`loadStudents(vector<Student>& students)`函数，每次程序启动时，先将文件中的学生信息同步到students容器中。

## 2.封装

将多次使用的将学生信息保存到文件中的功能封装成`saveStudents(const vector<Student>& students)`函数，这样就可以复用。

## 3.文件操作重复且效率低

每次操作都重新打开、读取、写入文件，效率较低。文件在程序启动时一次性读取到容器中，直接对容器进行操作。
