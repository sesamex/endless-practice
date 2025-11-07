#include <iostream>
#include <iomanip> //用于控制输出格式
using namespace std;
int main()
{
    float score1,score2,score3;//定义三门成绩
    cout <<"请输入三门成绩";
    cin >> score1 >> score2 >> score3;
    float num;
    num=(score1+score2+score3)/3;//求平均分
    cout <<"平均分："<<fixed <<setprecision(2)<<num <<endl;//保留两位小数
    return 0;
}