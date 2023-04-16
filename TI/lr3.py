
s='Там лес и дол видений полны; там о заре прихлынут волны на брег песчаный и пустой.\nЧто ж мы? на зимние квартиры? Не смеют, что ли, командиры чужие изорвать мундиры о русские штыки?'
import math
class Node:
    def __init__(self, name=None, value=None):
        self.name = name
        self.value = value
        self.left = None
        self.right = None

class Tree:

    def __init__(self, chars):
        self.arr = [Node(k, v) for k, v in chars.items()]
        while len(self.arr) != 1:
            self.arr.sort(key=lambda node: node.value, reverse=True)
            n = Node(value=(self.arr[-1].value + self.arr[-2].value))
            n.left = self.arr.pop(-1)
            n.right = self.arr.pop(-1)
            self.arr.append(n)
        self.root = self.arr[0]
        self.Buffer = list(range(10))
        self.vivod = dict()

    def walk_and_print(self, tree, length):
        ss = ''
        node = tree
        if (not node):
            return
        elif node.name:
            self.vivod.update({node.name:1})
            for i in range(length):
                ss=ss+str(self.Buffer[i])
            self.vivod[node.name]=ss
            return
        self.Buffer[length] = 0
        self.walk_and_print(node.left, length + 1)
        self.Buffer[length] = 1
        self.walk_and_print(node.right, length + 1)

    def output(self):
        self.walk_and_print(self.root, 0)
        return self.vivod


def veroaytnosti(line):
    slovar = dict()
    for i in line:
          if i in slovar:
              slovar[i] += 1
          else:
              slovar.update({i:1})
    for i in slovar:
        slovar[i]=slovar[i]/len(line)
    return slovar



n = len(s)
print(n)
count = 0
flag = 0
count_c = 1
l = 0
s1 = 0
s2 = 0
s3 = 0
slova = dict()
for i in range(n-1):
    for j in range(0, i-1, 1):
        if (s[j] == s[i])&(s[j+1]==s[i+1]):
            flag = 1
    for j in range(i, n-1, 1):
        if (s[i+1] == s[j+1]) & (s[i] == s[j]) & (flag==0):
            count = count + 1
    if (count!=0):
        p = count / (n-1)
        ss = s[i]+s[i+1]
        slova.update({ss:p})
        count_c=count_c+1

    count = 0
    flag = 0

count_c = 1
slova3=dict()
for i in range(n-2):
    for j in range(0, i-2, 1):
        if (s[j] == s[i])&(s[j+1]==s[i+1])&(s[j+2]==s[i+2]):
            flag = 1
    for j in range(i, n-2, 1):
        if (s[i+2] == s[j+2]) & (s[i+1] == s[j+1]) & (s[i] == s[j]) & (flag==0):
            count = count + 1
    if (count!=0):
        p = count / (n-2)
        slova3.update({s[i]+s[i+1]+s[i+2]:p})
        count_c=count_c+1

    count = 0
    flag = 0

result = veroaytnosti(s)
tree = Tree(result)
vivod1=tree.output()

count1=1
s1=0
print('  i               xi             ni            pi               ci               li')
for k,v in vivod1.items() :
    print('%3d'%count1,'%15s'%k,'%15.0f'%(float(result[k])*n),'%15.3f'%result[k],'%15s'%v,'%15d'%len(v))
    s1=s1+(result[k]*len(v))
    count1 += 1
print('\n\n')

count1=1
print('  i               xi             ni            pi               ci               li')

tree = Tree(slova)
vivod2=tree.output()

for k,v in vivod2.items():
    print('%3d' % count1, '%15s' % k, '%15.0f' %(float(slova[k]) * (n-1)), '%15.3f' % slova[k], '%15s' % v,'%15d' % len(v))
    s2+=slova[k]*len(v)
    count1+=1
print('\n\n')

count1=1
print('  i               xi             ni            pi               ci               li')
tree = Tree(slova3)
vivod3=tree.output()
for k,v in vivod3.items():
    print('%3d' % count1, '%15s' % k, '%15.0f' %(float(slova3[k]) * (n-2)), '%15.3f' % slova3[k], '%15s' % v,'%15d' % len(v))
    s3+=slova3[k]*len(v)

    count1 += 1
print('\n\n')

count1=0
count2=0
count3=0
for i in vivod1:
    count1+=1
for i in vivod2:
    count2 += 1
for i in vivod3:
    count3 += 1

print('Средння длина кодировки для одного символа = ','%.3f'%(s1))
print('Средння длина кодировки для двух символов = ','%.3f'%(s2))
print('Средння длина кодировки для трёх символов  = ','%.3f'%(s3))

print('Средняя скорость R1 = %.3f'%(s1/1))
print('Средняя скорость R2 = %.3f'%(s2/2))
print('Средняя скорость R3 = %.3f'%(s3/3))

