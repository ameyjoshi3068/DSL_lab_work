def addElements(l):
    n=int(input("How many roll numbers do want to enter?: "))
    for _ in range(n):
        tmp=int(input("Enter the element of set: "))
        if l.count(tmp)==0:
            l.append(tmp)

    print()
    return l

def union(s1,s2):
    ans=s1.copy()
    for i in s2:
        if s1.count(i)==0:
            ans.append(i)

    return ans

def difference(s1,s2):
    ans=[]
    for i in s1:
        if s2.count(i)==0:
            ans.append(i)

    return ans

def intersection(s1,s2):
    ans=[]
    for i in s2:
        if s1.count(i)!=0:
            ans.append(i)

    return ans


print("Enter Roll No of all students playing")
U=int(input("How many students are in total?: "))
print("Enter Roll No of students playing cricket")
cricket=[]
cricket=addElements(cricket)
print("Enter Roll No of students playing badminton")
badminton=[]
badminton=addElements(badminton)
print("Enter Roll No of students playing football")
football=[]
football=addElements(football)

index=9


while index!=0:
    print("Please select an option by entering corresponding index and 0 to quit\n")
    print("1) List of students who play both cricket and badminton")
    print("2) List of students who play either cricket or badminton but not both")
    print("3) Number of students who play neither cricket nor badminton")
    print("4) Number of students who play both cricket and football but not badminton\n")

    index=int(input("Select an option: "))

    if index==1:
        print (intersection(cricket,badminton))
        print("\n\n\n")
    elif index==2:
        x=union(cricket,badminton)
        y=difference(x,intersection(cricket,badminton))
        print (y)
        print("\n\n\n")
    elif index==3:
        print (U-len(union(cricket,badminton)))
        print("\n\n\n")
    elif index==4:
        x=intersection(cricket,football)
        y=difference(x,badminton)
        print (len(x))
        print("\n\n\n")
    

def extraQ2(l1,l2,l3):
    count=0
    for i in l1:
        if (l2.count(i)!=0 and l3.count(i)!=0):
            count+=1
    print("No of students who play all three games is: ",count)
    return count;

def extraQ3(l1,l2,l3):
    unionAll=[]
    templist=l1+l2+l3
    for i in templist:
        if unionAll.count(i)==0:
            unionAll.append(i)

    intersection12=intersection(l1,l2)
    intersection23=intersection(l2,l3)
    intersection13=intersection(l1,l3)

    intersectionAll=extraQ2(l1,l2,l3)

    ans=len(unionAll)-len(intersection12)-len(intersection13)-len(intersection23)+2*intersectionAll
    print("Number of students who play only one game is",ans)

def extraQ1(l1,l2,l3):
    unionAll=[]
    templist=l1+l2+l3
    for i in templist:
        if unionAll.count(i)==0:
            unionAll.append(i)
    print("No of students who play no game is",U-len(unionAll))


extraQ1(cricket,badminton,football)
extraQ3(cricket,badminton,football)

