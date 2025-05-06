a={1,2,3,4}
b={1,2,5,6}
c={6,5}
def addelement():
    print("Enter the element to add in set")
    num = int(input())
    if num not in a:
        a.add(num);
        print("Element added successfully")
    else:
        print("Element is already present")
        
def deleteelement():
    print("Enter the element to delete")
    num=int(input())
    if num not in a:
        print("Element is not present")
    else:
        a.remove(num)
        print("Element is deleted sucessfully")
        
def ispresent():
    print("Enter the element you want to search")
    num = int(input())
    if num in a:
        print("Yes it is present in the set")
    else:
        print("No it is not present in the set")
        
def sizeofset():
    count = 0
    for i in a:
        count = count + 1;
    print(count)
    
def iterator():
    for i in a:
        print(i)

def intersectionofset(a,b):
    inter=set()
    for i in a:
        for j in b:
            if i==j:
               inter.add(i)
    print(inter)

def unionofset(a,b):
    uni=set();
    for i in b:
        if i not in a:
            uni.add(i)
    print(uni)

def diffofset(s1,s2):
    diff=set()
    for i in s1:
        if i not in s2:
            diff.add(i)
    print(diff)

def subset(a,c):
    for i in c:
        if i not in a:
            print("It is not subset")
            break
        else:
            print("It is a subset")
            break
            
        
print(a)
print(b)
#addelement()
#display()
#deleteelement()
#iterator()
#ispresent()
#sizeofset()
intersectionofset(a,b)
unionofset(a,b)
diffofset(a,b)
subset(a,c)