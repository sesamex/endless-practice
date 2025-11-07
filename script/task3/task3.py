def is_prime(n):
    if n<2:
        return False
    for i in range(2,n):
        if n%i==0:
            return False
    return True

num = int(input("请输入一个整数："))
if is_prime(num):
    print(f"{num}是素数")
else:
    print(f"{num}不是素数")
