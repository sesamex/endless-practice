#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout<<"九九乘法表："<<endl;
    //由内循环先打印完一行，在到外循环进行下一行打印
    for(int i=1;i<=9;i++)//外循环定义从一到九有9行
    {for(int j=1;j<=i;j++)//内循环定义每一行从一到两个相同的数相乘结束
    {
        cout <<j<<"*"<<i<<"="<<setw(2)<<j*i<<"\t";//打印格式
    }
        cout <<endl;//每行结束换行
    }
    return 0;
}