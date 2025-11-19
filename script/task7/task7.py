"""
Python 类与对象演示，宠物店管理系统
体现：封装、继承、多态、抽象类、装饰器等面向对象特性
"""

from abc import ABC, abstractmethod#实现接口规范
from typing import TYPE_CHECKING

# 类型提示声明，防止Pylance未定义警告
if TYPE_CHECKING:
    class PetShop:
        def __init__(self, capacity: int = 10) -> None: ...
        def __len__(self) -> int: ...
        def add_animal(self, animal: 'Animal') -> None: ...
        def remove_animal(self, index: int) -> bool: ...
        def show_all_animals(self) -> None: ...
        def show_animal_list(self) -> None: ...
    
    def add_animal_interactive(shop: 'PetShop') -> None: ...
    def remove_animal_interactive(shop: 'PetShop') -> None: ...
    def give_command_interactive(shop: 'PetShop') -> None: ...
    def demonstrate_polymorphism_interactive(shop: 'PetShop') -> None: ...


class Animal(ABC):
    """动物基类，体现封装和继承"""
    
    # 类变量，体现类的静态成员，所有对象共享
    animal_count = 0
    
    def __init__(self, name: str, age: int):
        """构造函数,体现对象的初始化过程"""
        self._name = name           # 保护成员，体现封装
        self._age = age             # 保护成员
        self.__id = id(self)        # 私有成员，体现封装
        Animal.animal_count += 1    # 操作类变量
    
    def __str__(self):
        """特殊方法,体现Python的对象字符串表示"""
        return f"动物[{self._name}, 年龄: {self._age}]"
    
    # 属性装饰器
    # 体现封装的getter方法
    @property
    def name(self):
        """提供对保护成员的受控访问"""
        return self._name
    
    @property
    def age(self):
        return self._age
    
    # 抽象方法，体现多态和接口规范
    @abstractmethod
    def make_sound(self):
        """抽象方法,强制子类实现，体现多态"""
        pass
    
    @abstractmethod
    def move(self):
        """抽象方法,强制子类实现，体现多态"""
        pass
    
    @classmethod
    def get_animal_count(cls):
        """类方法,体现类级别操作，不依赖于实例"""
        return cls.animal_count


class Dog(Animal):
    """狗类,继承自动物类，体现继承关系"""
    
    def __init__(self, name: str, age: int, breed: str):
        """构造函数,体现继承中的初始化链"""
        super().__init__(name, age)  # 调用父类构造函数，体现继承
        self._breed = breed          # 狗特有的属性，体现扩展性
        print(f"创建狗狗: {name}")
    
    def __str__(self):
        """方法重写,体现多态性"""
        return f"狗[{self._name}, 品种: {self._breed}, 年龄: {self._age}]"
    
    def make_sound(self):
        """方法重写,体现运行时多态"""
        print(f"{self._name}汪汪叫！")
    
    def move(self):
        """方法重写,体现运行时多态"""
        print(f"{self._name}用四条腿奔跑")
    
    def fetch(self):
        """狗特有的方法,体现类的专有行为"""
        print(f"{self._name}正在接飞盘")


class Cat(Animal):
    """猫类,继承自动物类，体现继承关系"""
    
    def __init__(self, name: str, age: int, grooming: float):
        """构造函数,体现继承中的初始化链"""
        super().__init__(name, age)  # 调用父类构造函数
        self._grooming = grooming    # 猫特有的属性
        print(f"创建猫猫: {name}")
    
    def __str__(self):
        """方法重写,体现多态性"""
        return f"猫[{self._name}, 整洁度: {self._grooming}, 年龄: {self._age}]"
    
    def make_sound(self):
        """方法重写,体现运行时多态"""
        print(f"{self._name}喵喵喵！")
    
    def move(self):
        """方法重写,体现运行时多态"""
        print(f"{self._name}优雅地走动")
    
    def jump(self):
        """猫特有的方法,体现类的专有行为"""
        print(f"{self._name}跳得高高！")


class PetShop:
    """宠物店类,管理动物对象，体现类的组合关系"""
    
    def __init__(self, capacity: int = 10):
        """构造函数，体现对象组合和资源管理"""
        self.capacity = capacity
        self.animals = []  # 对象组合 - 包含动物对象列表
        print(f"宠物店开业，可容纳{capacity}只动物")
    
    def __len__(self):
        """特殊方法,使得对象支持len()函数,体现Pythonic设计"""
        return len(self.animals)
    
    def add_animal(self, animal: Animal):
        """添加动物,体现多态（参数为基类类型）"""
        if len(self.animals) < self.capacity:
            self.animals.append(animal)  # 可以接受任何Animal子类
            print(f"成功添加动物: {animal.name}")
        else:
            print("宠物店已满，无法添加新动物")
    
    def remove_animal(self, index: int) -> bool:
        """删除动物,体现对象生命周期管理"""
        if 0 <= index < len(self.animals):
            removed_animal = self.animals.pop(index)
            print(f"删除动物: {removed_animal.name}")
            return True
        return False
    
    def show_all_animals(self):
        """展示所有动物,集中体现多态性"""
        if not self.animals:
            print("宠物店目前没有动物")
            return
        
        print("\n=== 宠物店的小动物们 ===")
        for i, animal in enumerate(self.animals, 1):
            print(f"动物{i}: {animal}")
            animal.make_sound()  # 多态调用,同一接口，不同行为
            animal.move()        # 多态调用,同一接口，不同行为
            print()

            def show_animal_list(self):
             """显示动物列表,体现对象信息的封装访问"""
        if not self.animals:
            print("宠物店目前没有动物")
            return
        
        print("\n=== 动物列表 ===")
        for i, animal in enumerate(self.animals, 1):
            # 使用isinstance检查类型 ,现多态的类型识别
            animal_type = "狗" if isinstance(animal, Dog) else "猫"
            print(f"{i}. {animal.name} ({animal.age}岁) [{animal_type}]")


def demonstrate_polymorphism(animal: Animal):
    """演示多态的函数,参数为基类类型，体现多态接口"""
    print("\n=== 多态演示 ===")
    print(f"对象: {animal}")
    print(f"类型: {type(animal).__name__}")
    animal.make_sound()  # 多态调用 - 运行时确定具体方法
    animal.move()        # 多态调用 - 运行时确定具体方法


def add_animal_interactive(shop: PetShop):
    """添加动物交互函数,体现用户与对象的交互"""
    print("\n--- 添加动物 ---")
    name = input("请输入动物名称: ")
    age = int(input("请输入年龄: "))
    animal_type = input("请选择类型(1.狗 2.猫): ")
    
    # 根据用户输入创建不同类型的对象,体现多态的对象创建
    if animal_type == "1":
        breed = input("请输入品种: ")
        animal = Dog(name, age, breed)  # 创建Dog对象
    else:
        grooming = float(input("请输入整洁度(1-10): "))
        animal = Cat(name, age, grooming)  # 创建Cat对象
    
    shop.add_animal(animal)  # 统一接口添加，不关心具体类型


    def remove_animal_interactive(shop: PetShop):
        """删除动物交互函数,体现对象管理"""
    if len(shop) == 0:
        print("宠物店没有动物可以删除！")
        return
    
    shop.show_animal_list()
    index = int(input("请输入要删除的动物编号: ")) - 1
    
    if shop.remove_animal(index):
        print("删除成功！")


def give_command_interactive(shop: PetShop):
    """给动物下指令交互函数,体现对象行为调用"""
    if len(shop) == 0:
        print("宠物店没有动物！")
        return
    
    shop.show_animal_list()
    index = int(input("请选择动物编号: ")) - 1
    animal = shop.animals[index]  # 获取具体动物对象
    
    print(f"\n=== 给 {animal.name} 下指令 ===")
    print("1. 让它叫")
    print("2. 让它移动")
    
    # 根据具体类型提供特定指令,体现多态的类型特定行为
    if isinstance(animal, Dog):
        print("3. 接飞盘（狗狗专属）")
    elif isinstance(animal, Cat):
        print("3. 跳跃（猫猫专属）")
    
    command = int(input("请选择指令: "))
    
    # 多态调用,同一指令接口，不同对象有不同实现
    if command == 1:
        animal.make_sound()  # 多态：狗叫"汪汪"，猫叫"喵喵"
    elif command == 2:
        animal.move()        # 多态：狗"奔跑"，猫"优雅走动"
    elif command == 3:
        # 类型特定行为调用
        if isinstance(animal, Dog):
            animal.fetch()   # 狗特有行为
        else:
            animal.jump()    # 猫特有行为


def demonstrate_polymorphism_interactive(shop: PetShop):
    """交互式多态演示,让用户选择要演示的对象"""
    if len(shop) == 0:
        print("宠物店没有动物可以演示！")
        return
    
    shop.show_animal_list()
    index = int(input("请选择要演示多态的动物编号: ")) - 1
    demonstrate_polymorphism(shop.animals[index])


def main():
    """主函数,程序入口，体现面向对象系统的组织"""
    shop: 'PetShop' = PetShop(10)  # 创建宠物店对象,体现对象实例化
    choice = 0
    
    print("=== Python 宠物店管理系统 ===")
    print("体现：封装、继承、多态、类与对象")
    
    # 主循环,体现用户与对象系统的持续交互
    while choice != 6:
        print("\n=== 主菜单 ===")
        print("1. 添加动物")
        print("2. 删除动物")
        print("3. 查看所有动物")
        print("4. 给动物下指令")
        print("5. 多态演示")
        print("6. 退出")
        
        choice = int(input("请选择操作: "))
        
        # 根据用户选择调用不同功能,体现面向对象的行为分发
        if choice == 1:
            add_animal_interactive(shop)  # 对象创建和添加
        elif choice == 2:
            remove_animal_interactive(shop)  # 对象删除和管理
        elif choice == 3:
            shop.show_all_animals()  # 对象信息展示
        elif choice == 4:
            give_command_interactive(shop)  # 对象行为调用
        elif choice == 5:
            demonstrate_polymorphism_interactive(shop)  # 多态特性演示
        elif choice == 6:
            print("再见！")
            print(f"总共创建过的动物数量: {Animal.get_animal_count()}")  # 类方法调用


if __name__ == "__main__":
    # 程序启动,体现面向对象程序的执行入口
    main()