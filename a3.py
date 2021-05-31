a = int(input())
b = int(input())
c = int(input())

largest = max(a,b,c)
least = min(a,b,c)
mid = a+b+c-(largest+least)


print(largest,mid,least,sep=">")
