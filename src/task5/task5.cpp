#include<iostream>
using namespace std;
int temp;//temp用于交换的临时变量
void swapValue(int *a,int *b)//使用指针
{
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int x,y;
    cout<<"请输入两个整数：";
    cin>>x>>y;
    swapValue(&x,&y);//传递变量地址
    cout<<"交换后："<<x<<" "<<y<<endl;
    return 0;
}