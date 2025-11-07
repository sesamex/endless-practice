print("请输入三门成绩：",end="")
score1,score2,score3=map(float,input().split())
num=(score1+score2+score3)/3
print(f"平均分：{num:.2f}")