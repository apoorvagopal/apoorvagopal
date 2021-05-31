
print("enter the number of test cases")
n=int(input())

for i in range(n):
    print("enter the value of a,b,k")
    a=int(input())
    b=int(input())
    k=int(input())
    if a>=b:
        print(k//b)
    else:
        print(k//a)
    
