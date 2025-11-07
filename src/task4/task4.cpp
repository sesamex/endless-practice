#include<iostream>
using namespace std;
int main()
{
int scores[10];//定义一个数组
int max;//定义变量max,记录数组最大值
int sum=0;//定义总和变量
int temp;//用于交换的临时变量
double average;
cout<<"请输入10个学生的成绩:"<<endl;
//遍历数组得到每一个元素，让其与max对比
//若其<=max里面记录的数据，不做任何处理
//若其>max里面记录的数据，max修改为新的值
for(int i=0;i<10;i++)//用循环读取用户输入的十个成绩
{
    cin>>scores[i];//将用户输入的数存入数组对应的位置
    sum=sum+scores[i];//累加每个成绩
}
for(int i=0;i<9;i++)//外循环控制轮数
{
    for(int j=0;j<9-i;j++)//内循环比较相邻元素
    {
        if(scores[j]>scores[j+1])//两两比较，如果前面的数较大则互换
        {
            temp=scores[j];
            scores[j]=scores[j+1];
            scores[j+1]=temp;
        }
    }
}
max=scores[9];
//输出最高分
cout<<"最高分是："<<max<<endl;
//计算平均分
average=static_cast<double>(sum)/10;
//输出平均分
cout<<"平均分是："<<average<<endl;
//从小到大排列
cout<<"从小到大排列："<<endl;
for(int i=0;i<10;i++)//遍历输出循环
{
    cout<<scores[i]<<" ";
}
    cout<<endl;
//从大到小排列
cout<<"从大到小排列："<<endl;
for(int i=9;i>=0;i--)//反向遍历即可
{
    cout<<scores[i]<<" ";
}
cout<<endl;
return 0;
}
