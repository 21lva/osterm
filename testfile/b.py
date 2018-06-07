fcfs=open("fcfs.txt","r");
nsjf=open("nsjf.txt","r");
psjf=open("psjf.txt","r");
npri=open("npri.txt","r");
ppri=open("ppri.txt","r");
rr=open("rr.txt","r");
X=open("all.txt","w");

awt=0
att=0
util=0
for i in range(700):
    a=fcfs.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

awt=0
att=0
util=0
for i in range(700):
    a=nsjf.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

awt=0
att=0
util=0
for i in range(700):
    a=psjf.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

awt=0
att=0
util=0
for i in range(700):
    a=npri.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

awt=0
att=0
util=0
for i in range(700):
    a=ppri.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

awt=0
att=0
util=0
for i in range(700):
    a=rr.readline()
    l=a.split()
    awt+=float(l[0])
    att+=float(l[1])
    util+=float(l[2])
print(awt/700)
print(att/700)
print(util/700)
X.write(str(awt/700)+" "+str(att/700)+" "+str(util/700)+"\n")

