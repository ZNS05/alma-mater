line = "Там лес и дол видений полны; там о заре прихлынут волны на брег песчаный и пустой.\nЧто ж мы? на зимние квартиры? Не смеют, что ли, командиры чужие изорвать мундиры о русские штыки?"

import math 

N = len(line)

print()
array_set = set()

for i in line:
    array_set.add(i)

id = 1
h1 = 0
print('===========================================================')
print('  i      xi        Ni     P(xi)          I(xi)         P*I')
print('===========================================================') 
for i in array_set:
    
    if i != '\n':
        print(f"{id:3}  |    {i:3}  | {line.count(i):3}  |   {line.count(i)/N:.4f}  |     {-1*math.log2(line.count(i)/N):.4f}  |    {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
        h1 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))

    else:
        print(f"{id:3}  |    \\n   | {line.count(i):3}  |   {line.count(i)/N:.4f}  |     {-1*math.log2(line.count(i)/N):.4f}  |    {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
        h1 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))
    id += 1
print("H(X1) =% .4f" % h1)
print("H1(X) =% .4f" % h1)
print("H(X|X0) =% .4f" % h1)

array_set = set()

N -= 1

id = 1
h2 = 0
for i in range(N):
    array_set.add(line[i]+line[i+1])
print()
print('================================================================')
print('  i      xi         Ni     P(xi, xj)       I(xi, xj)      P*I')
print('================================================================')

for i in array_set:
    
    if '\n' not in i:
        print(f"{id:3}      {i:4}     {line.count(i):3}      {line.count(i)/N:.4f}          {-1*math.log2(line.count(i)/N):.4f}         {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
        h2 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))
    else:
        bufi = i[1-i.find('\n')]
        if i.find('\n') == 1:
            print(f"{id:3}      {bufi}\\n      {line.count(i):3}      {line.count(i)/N:.4f}          {-1*math.log2(line.count(i)/N):.4f}         {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
            h2 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))
        else:
            print(f"{id:3}      \\n{bufi}      {line.count(i):3}      {line.count(i)/N:.4f}          {-1*math.log2(line.count(i)/N):.4f}         {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
            h2 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))
    id += 1

print("H(X2) =% .4f" % h2)
print("H2(X) =% .4f " % (h2/2))
print("H(X|X1) =% .4f" % (h2-h1))
array_set = set()

N -= 1

id = 1
h3 = 0
for i in range(N):
    array_set.add(line[i]+line[i+1]+line[i+2])

print()
print('====================================================================')
print('  i       xi         Ni     P(xi, xj, xk)     I(xi, xj, xk)      P*I')
print('====================================================================')

for i in array_set:

    if '\n' not in i:
        print(f"{id:3}      {i:5}     {line.count(i):3}      {line.count(i)/N:.4f}            {-1*math.log2(line.count(i)/N):.4f}           {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
        h3 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))

    else:
        if i.find('\n') == 1:
            print(f"{id:3}      {i[0]}\\n{i[2]}      {line.count(i):3}      {line.count(i)/N:.4f}            {-1*math.log2(line.count(i)/N):.4f}           {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
            h3 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))

        elif i.find('\n') == 0:
            print(f"{id:3}      \\n{i[1]}{i[2]}      {line.count(i):3}      {line.count(i)/N:.4f}            {-1*math.log2(line.count(i)/N):.4f}           {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
            h3 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))

        else:
            print(f"{id:3}      {i[0]}{i[1]}\\n      {line.count(i):3}      {line.count(i)/N:.4f}            {-1*math.log2(line.count(i)/N):.4f}           {((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N))):.4f}")
            h3 += ((-1*math.log2(line.count(i)/N)) * ((line.count(i)/N)))

    id += 1
print("H(X3) =% .4f"% h3)
print("H3(X) =% .4f" % (h3/3))
print("H(X|X2) =% .4f" % (h3-h2))