import random

f=open("demo.txt","w")
for i in range(400000):
    a=random.randint(1,1000000)
    f.write(str(a)+" ")
print("DONE..")