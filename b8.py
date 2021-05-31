a=int(input())
b=int(input())
c=int(input())
d=int(input())
list1=(a,b,c,d)
list2=sorted(list1)
large=(max(a,b,c,d))
small=(min(a,b,c,d))
middle1=list2[2]
middle2=list2[1]
print(large,middle1,middle2,small,sep='>')

