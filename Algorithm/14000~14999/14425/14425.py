n,m = map(int,input().split())
str_dict={}
sum_of_str=0
for i in range(n):
    str_in=input()
    str_dict[str_in]=1
for j in range(m):
    str_find=input()
    sum_of_str+=bool(str_dict.get(str_find))
print(sum_of_str)