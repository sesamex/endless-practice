scores=[]
print("请输入10个学生成绩:")
scores=list(map(float,input().split()))
#input()键盘输入 split()按空格分割字符串 map(float,)把字符串转成浮点数 list()转成python列表
max_score=max(scores)#找最高分
average_scores=sum(scores)/len(scores)#计算平均分
#排序
sorted_low_to_high=sorted(scores)#从小到大
sorted_high_to_low=sorted(scores,reverse=True)#从大到小

#输出
print (f"最高分：{max_score}")
print(f"平均分：{average_scores:.2f}")
print("\n从低到高:",sorted_low_to_high)
print("\n从高到低:",sorted_high_to_low)