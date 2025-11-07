#include <iostream>
using namespace std;
bool isPrime(int n)//通过此函数判断素数，并规定是素数为turn，不是为false
{
    if(n<=1)return false;//0和1不是素数，返回false
    for(int i=2;i<n;i++)//判断是否含有除1和它本身以外的因数
    {
    if(n%i==0)
    {
        return false;//能被整除，不是素数,返回false
    }
    }
    return true;//是素数,返回ture
}
int main()
{
    int number;
    cout<<"请输入一个整数：";//获取数字
    cin>>number;//输入数字
    if(isPrime(number))//通过之前的判断，ture执行if后面的代码块，所以输出 是素数
    {
        cout<<number<<"是素数"<<endl;
    }
    else//false执行else后面的代码块，输出 不是素数
    {
        cout<<number<<"不是素数"<<endl;
    }
    return 0;
}
    