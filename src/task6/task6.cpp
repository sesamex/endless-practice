#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Student {
    string id;
    string name;
    string className;
    vector<string> subjects;
    vector<int> scores;
    int totalScore;
    
    Student(string i, string n, string c, vector<string> sub, vector<int> sc) 
        : id(i), name(n), className(c), subjects(sub), scores(sc) {
        totalScore = 0;
        for(int score : sc) {
            totalScore += score;
        }
    }
};

class StudentManager {
private:
    vector<Student> students;
    vector<string> subjectNames; // 所有学科名称
    
public:
    StudentManager() {
        subjectNames = {"数学", "英语", "物理"}; 
          // 在构造函数中初始化5名学生
        students = {
            Student("1001", "张三", "一班", subjectNames, {85, 92, 78}),
            Student("1002", "李四", "一班", subjectNames, {90, 88, 95}),
            Student("1003", "王五", "二班", subjectNames, {76, 85, 92}),
            Student("1004", "赵六", "二班", subjectNames, {88, 79, 84}),
            Student("1005", "钱七", "三班", subjectNames, {92, 95, 89})
        };
    }
    // 插入学生信息
    void insertStudent() {
        string id, name, className;
        vector<int> scores;
        
        cout << "请输入学号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入班级: ";
        cin >> className;
        
        cout << "请输入3门学科成绩:" << endl;
        for(int i = 0; i < 3; i++) {
            int score;
            cout << subjectNames[i] << "成绩: ";
            cin >> score;
            scores.push_back(score);
        }
        
        Student stu(id, name, className, subjectNames, scores);
        students.push_back(stu);
        cout << "学生信息添加成功!" << endl;
    }
    
    // 显示所有学生信息
    void displayAll() {
        if(students.empty()) {
            cout << "没有学生信息!" << endl;
            return;
        }
        
        cout << "\n==================================================================" << endl;
        cout << left << setw(12) << "学号" << setw(10) << "姓名" << setw(10) << "班级";
        for(auto sub : subjectNames) {
            cout << setw(8) << sub;
        }
        cout << setw(10) << "总成绩" << endl;
        cout << "==================================================================" << endl;
        
        for(auto &stu : students) {
            cout << left << setw(12) << stu.id << setw(10) << stu.name << setw(10) << stu.className;
            for(int i = 0; i < stu.scores.size(); i++) {
                cout << setw(8) << stu.scores[i];
            }
            cout << setw(10) << stu.totalScore << endl;
        }
    }
    
    // 根据学号搜索
    void searchById() {
        string id;
        cout << "请输入要搜索的学号: ";
        cin >> id;
        
        for(auto &stu : students) {
            if(stu.id == id) {
                cout << "找到学生信息:" << endl;
                cout << "学号: " << stu.id << ", 姓名: " << stu.name 
                     << ", 班级: " << stu.className << ", 总成绩: " << stu.totalScore << endl;
                return;
            }
        }
        cout << "未找到该学号的学生!" << endl;
    }
    //修改学生信息
     void modifyStudent() {
        string id;
        cout << "请输入要修改的学生学号: ";
        cin >> id;
        
        for(auto &stu : students) {
            if(stu.id == id) {
                cout << "找到学生: " << stu.name << endl;
                cout << "请输入新的姓名 (当前: " << stu.name << "): ";
                cin >> stu.name;
                cout << "请输入新的班级 (当前: " << stu.className << "): ";
                cin >> stu.className;
                
                cout << "请输入新的成绩:" << endl;
                for(int i = 0; i < stu.scores.size(); i++) {
                    cout << subjectNames[i] << "成绩 (当前: " << stu.scores[i] << "): ";
                    cin >> stu.scores[i];
                }
                
                // 重新计算总分
                stu.totalScore = 0;
                for(int score : stu.scores) {
                    stu.totalScore += score;
                }
                
                cout << "学生信息修改成功!" << endl;
                return;
            }
        }
        cout<<"未找到该学生！"<<endl;
    }
    // 根据学号删除
    void deleteById() {
        string id;
        cout << "请输入要删除的学号: ";
        cin >> id;
        
        for(auto it = students.begin(); it != students.end(); it++) {
            if(it->id == id) {
                students.erase(it);
                cout << "删除成功!" << endl;
                return;
            }
        }
        cout << "未找到该学号的学生!" << endl;
    }
    
    // 按总成绩排序
    void sortByTotal(bool descending = true) {
        if(descending) {
            sort(students.begin(), students.end(), 
                 [](const Student &a, const Student &b) { return a.totalScore > b.totalScore; });
            cout << "按总成绩从高到低排序完成!" << endl;
        } else {
            sort(students.begin(), students.end(), 
                 [](const Student &a, const Student &b) { return a.totalScore < b.totalScore; });
            cout << "按总成绩从低到高排序完成!" << endl;
        }
        displayAll();
    }
    // 按单科成绩排序
    void sortBySubject(int subjectIndex, bool descending = true) {
        if(subjectIndex < 0 || subjectIndex >= 3) {
            cout << "无效的学科索引!" << endl;
            return;
        }
        
        if(descending) {
            sort(students.begin(), students.end(), 
                 [subjectIndex](const Student &a, const Student &b) { 
                     return a.scores[subjectIndex] > b.scores[subjectIndex]; 
                 });
            cout << "按" << subjectNames[subjectIndex] << "成绩从高到低排序完成!" << endl;
        } else {
            sort(students.begin(), students.end(), 
                 [subjectIndex](const Student &a, const Student &b) { 
                     return a.scores[subjectIndex] < b.scores[subjectIndex]; 
                 });
            cout << "按" << subjectNames[subjectIndex] << "成绩从低到高排序完成!" << endl;
        }
        displayAll();
    }
    
    // 按数学成绩排序
    void sortByMath(bool descending = true) {
        sortBySubject(0, descending);
    }
    
    // 按英语成绩排序
    void sortByEnglish(bool descending = true) {
        sortBySubject(1, descending);
    }
    
    // 按物理成绩排序
    void sortByPhysics(bool descending = true) {
        sortBySubject(2, descending);
    }
    
    // 显示排序菜单
    void showSortMenu() {
        cout << "\n===== 排序选项 =====" << endl;
        cout << "1. 按总成绩从高到低排序" << endl;
        cout << "2. 按总成绩从低到高排序" << endl;
        cout << "3. 按数学成绩从高到低排序" << endl;
        cout << "4. 按数学成绩从低到高排序" << endl;
        cout << "5. 按英语成绩从高到低排序" << endl;
        cout << "6. 按英语成绩从低到高排序" << endl;
        cout << "7. 按物理成绩从高到低排序" << endl;
        cout << "8. 按物理成绩从低到高排序" << endl;
        cout << "0. 返回主菜单" << endl;
        cout << "请选择排序方式: ";
    }
    
    // 处理排序选择
    void handleSortChoice() {
        int sortChoice;
        do {
            showSortMenu();
            cin >> sortChoice;
            
            switch(sortChoice) {
                case 1:
                    sortByTotal(true);
                    break;
                case 2:
                    sortByTotal(false);
                    break;
                case 3:
                    sortByMath(true);
                    break;
                case 4:
                    sortByMath(false);
                    break;
                case 5:
                    sortByEnglish(true);
                    break;
                case 6:
                    sortByEnglish(false);
                    break;
                case 7:
                    sortByPhysics(true);
                    break;
                case 8:
                    sortByPhysics(false);
                    break;
                case 0:
                    cout << "返回主菜单" << endl;
                    break;
                default:
                    cout << "无效选择!" << endl;
            }
        } while(sortChoice != 0);
    }
    // 显示菜单
    void showMenu() {
        cout << "\n========== 学生信息管理系统 ==========" << endl;
        cout << "1. 插入学生信息" << endl;
        cout << "2. 显示所有学生信息" << endl;
        cout << "3. 根据学号搜索" << endl;
        cout << "4. 修改学生信息" << endl;
        cout << "5. 根据学号删除" << endl;
        cout << "6. 成绩排序" << endl;
        cout << "0. 退出系统" << endl;
        cout << "请选择操作: ";
    }
};
int main() {
    StudentManager manager;
    int choice;
    do {
        manager.showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                manager.insertStudent();
                break;
            case 2:
                manager.displayAll();
                break;
            case 3:
                manager.searchById();
                break;
            case 4:
                manager.modifyStudent();
                break;
            case 5:
                manager.deleteById();
                break;
            case 6:
                manager.handleSortChoice();
                break;
            case 7:
                manager.sortByTotal(false);
                break;
            case 0:
                cout << "感谢使用!" << endl;
                break;
            default:
                cout << "无效选择!" << endl;
        }
    } while(choice != 0);
    
    return 0;
}