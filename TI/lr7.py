import math
s='Там лес и дол видений полны; там о заре прихлынут волны на брег песчаный и пустой. Что ж мы? на зимние квартиры? Не смеют, что ли, командиры чужие изорвать мундиры о русские штыки?'
s = s.encode('cp1251')

def ver(s,n,a):
    flag=0
    if a==1:
        b=0
        c=0
    if a==2:
        b=1
        c=0
    if a==3:
        b=1
        c=2
    Dictionary2=dict()
    count = 0
    for i in range(n - a + 1):
        for j in range(0, i - a + 1, 1):
            if (s[j] == s[i])&(s[j + b] == s[i + b])&(s[j + c] == s[i + c]):
                flag = 1
        for j in range(i, n - a+1, 1):
            if (s[i] == s[j]) & (flag == 0)& (s[j + b] == s[i + b])&(s[j + c] == s[i + c]):
                        count = count + 1
        if (count != 0):
            if a==1:
                s1 =s[i]
            if a == 2:
                s1 = s[i] + s[i + 1]
            if a == 3:
                s1 = s[i] + s[i + 1] + s[i + 2]
            p = count / (n - (a-1))
            Dictionary2.update({s1: p})
        count = 0
        flag = 0
    return Dictionary2

class Node(object):
    def __init__(self, name=None, value=None):
        self.a = None
        self.name = name
        self.value = value
        self.left = None
        self.right = None
        self.rang = 0

class Tree(object):
    def __init__(self, chars):
        self.znach = 0
        self.arr = [Node(k, v) for k, v in chars.items()]
        self.arr2 =[]
        for i in self.arr:
            i.a = 1

        while len(self.arr) != 1:
            self.arr.sort(key=lambda node : node.value, reverse=True)
            n = Node(value=(self.arr[-1].value + self.arr[-2].value))
            n.left = self.arr.pop(-1)
            n.right = self.arr.pop(-1)
            n.a = 0
            self.arr.append(n)
        self.root = self.arr[0]
        self.cod = list(range(10))
        self.vivod = dict()

    def walk_and_print(self, tree, length):
        ss = ''
        node = tree
        node.rang = self.znach
        self.arr2.append(node)
        self.znach = self.znach + 1

        if (not node):
            return
        elif node.name:
            self.vivod.update({node.name:1})
            for i in range(length):
                ss = ss + str(self.cod[i])
            self.vivod[node.name] = ss
            #self.znach-=1
            return

        self.cod[length] = 0
        self.walk_and_print(node.left, length + 1)
        self.cod[length] = 1
        self.znach -= 1
        self.walk_and_print(node.right, length + 1)
        self.znach-=1

    def output(self):
        self.walk_and_print(self.root, 0)
        return self.vivod
    def all(self):
        self.walk_and_print(self.root, 0)
        return self.arr2

n = len(s)
print(n)

slova1 = ver(s, n, 1)

tree = Tree(slova1)
ss = tree.all()
print()
count=0
for i in ss:
    count+=1
count-=1
for i in range(int(count/2)):
    ss[i],ss[count-i]= ss[count-i],ss[i]
count+=1
for i in range(count-1):
    for j in range(count-i-1):
        if(ss[j].rang>ss[j+1].rang):
            ss[j],ss[j + 1]=ss[j+1],ss[j]
c11=''
c12=''
c1=''
for i in ss:
    c11=c11+str(i.a)
for i in ss:
    if i.a==1:
        s_assci=str(format((i.name),'8b'))
        count2=0
        for j in s_assci:
            if j==' ':
                count2+=1
        for j in range(count2):
            c12+='0'
        c12=c12+str(format((i.name),'b'))
c1=c11+c12
vivod1 = tree.output()
c2=''
for i in s:
    c2=c2+vivod1[i]
print("c1 = ",c1)
print("len c1 = ",len(c1))
print("c2 = ",c2)
print("len c2 = ",len(c2))
print("c = ",c1+c2)
print("len c = ",len(c1+c2))
