# def swap_by_reference(a,b):#python中好像没有指针和引用
#     return b,a #直接返回交换后的值
# print("请输入两个整数：")
# a,b=map(int,(input().split()))

# a,b = swap_by_reference(a,b)
# print(f"{a},{b}")
def swap_by_reference(a,b):
    temp=a
    a=b
    b=temp
    return a,b
print("请输入两个整数：")
a,b=map(int,(input().split()))
a,b = swap_by_reference(a,b)

print(f"{a},{b}")