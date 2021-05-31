unit=int(input())
if unit>0 and unit<=20:
   cost=3.75*unit
elif unit>=31 and unit<=100:
   cost=5.20*unit
elif unit>=101 and unit<=200:
   cost=6.75*unit
elif n>201:
   cost=7.8*n

EB_BILL=cost+60
EB_BILL_TOTAL=(EB_BILL*0.05)+EB_BILL
print("The EB bill is =",EB_BILL_TOTAL)
