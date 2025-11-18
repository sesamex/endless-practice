#include<iostream>
#include<string>
#include<vector>
using namespace std;
//各种小动物种类，体现封装和继承
class Animal{
    private:
    string name;//私有成员，体现封装
    protected:
    int age;//保护成员，但可在派生类中访问
    public://对照函数，将对象初始化
    Animal(string n,int a):name(n),age(a){
        cout<<"Animal构造函数被调用"<<endl;
    }
    //虚构函数，为多态作准备(清除时自动调用)
    virtual ~Animal(){
        cout<<"Animal析构函数被调用"<<endl;
    }
    //接口：公有成员函数
    string getName() const{return name;}
    int getAge() const{return age;}
    //虚函数，体现多态
    virtual void makeSound() const{
        cout<<name<<"发出某种声音"<<endl;
    }
    //纯虚函数，抽象类
    virtual void move()const=0;
};//类内设定完毕，类外调用
//举个例子，狗狗，继承自动物类，体现：继承，多态
class Dog : public Animal{
    private:
    string breed;//狗的品种
    public:
    //构造函数
    Dog(string n,int a,string b) : Animal(n,a),breed(b){
        cout<<"Dog构造函数被调用"<<endl;
    }
    ~Dog(){
        cout<<"Dog析构函数被调用"<<endl;
    }
    //重写基类虚函数，体现多态
    void makeSound()const override{
        cout<<getName()<<"汪汪叫！"<<endl;
    }
    void move()const override{
        cout<<getName()<<"奔跑"<<endl;
    }
    //狗狗特有的行为
    void fetch(){
        cout<<getName()<<"正在接飞盘"<<endl;
    }
};
//下一个动物，猫猫
class Cat : public Animal{
    private:
    double grooming;//舔毛
    public:
    Cat(string n,int a,double g) : Animal(n,a),grooming(g){
        cout<<"Cat构造函数被调用"<<endl;
    }
    ~Cat(){
        cout<<"Cat析构函数被调用"<<endl;
    }
    //重写基类函数，体现多态
    void makeSound() const override{
        cout<<getName()<<"喵喵喵"<<endl;
    }
    void move()const override{
        cout<<getName()<<"在玩毛线"<<endl;
    }
    //猫猫特有的行为
    void jump(){
        cout<<getName()<<"跳得高高"<<grooming<<"米"<<endl;
    }
};
//现在创建一个宠物店，用于管理动物对象，体现：类的组合，对象数组
class PetShop{
    private:
    Animal** animals;//这里是一个动物指针
    int capacity;
    int count;
    public:
    //依旧构造函数
    PetShop(int cap=10):capacity(cap),count(0){
        animals=new Animal*[capacity];
        cout<<"宠物店开业，可容纳"<<capacity<<"只动物"<<endl;
    }
    //析构函数，资源管理
    ~PetShop(){
        for(int i=0;i<count;++i){
            delete animals[i];
        }
        delete[]animals;
        cout<<"宠物店关门"<<endl;
    }
    //添加动物，体现多态
    void addAnimal(Animal*animal){
        if(count<capacity){
            animals[count++]=animal;
            cout<<"宠物店已满，无法添加新宠物！"<<endl;
        }
    }
    //展示所有动物，，体现多态
    void showAllAnimals()const{
        cout<<"\n宠物店的小动物们"<<endl;
        for (int i=0;i<count;++i){
            cout<<"动物"<<i+1<<":";
            animals[i]->makeSound();//多态调用
            animals[i]->move();//多他调用
            cout<<endl;
        }
    }
};
//演示函数，体现多态
void demonstratePolymorphism(Animal& animal){
    cout<<"\n多态演示"<<endl;
    cout<<"名称："<<animal.getName()<<endl;
    cout<<"年龄："<<animal.getAge()<<"岁"<<endl;
    animal.makeSound();//运行时多态
    animal.move();//运行时多态
}

int main(){
    cout<<"演示类与对象中。。。"<<endl;
    //创建具体对象，体现类的实例化
    Dog myDog("旺财",3,"金毛");
    Cat myCat("小飞",3,1.2);
    //多态演示
    demonstratePolymorphism(myDog);
    demonstratePolymorphism(myCat);
    //宠物店管理，体现对象组合
    PetShop shop(5);
    shop.addAnimal(new Dog("小黄",2,"柴犬"));
    shop.addAnimal(new Cat("小白",2,1.3));
    shop.addAnimal(new Dog("大黄",4,"柯基"));

    shop.showAllAnimals();
    return 0;
}