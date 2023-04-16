line = "Там лес и дол видений полны; там о заре прихлынут волны на брег песчаный и пустой. Что ж мы? на зимние квартиры? Не смеют, что ли, командиры чужие изорвать мундиры о русские штыки?"
import math 

a = len(line)
mas_sim = []
#mas1.append(line[0])
flag = 0
for i in range (a - 1):
    flag = 0
    for j in range(i):
        if line[i] == line[j]:
            flag = 1
    if flag == 0:
        mas_sim.append(line[i])
a1 = len(mas_sim)
mas_count = []
for i in range(a1):
    mas_count.append(0)
    for j in range(a):
        if(mas_sim[i] == line[j]):
            mas_count[i] += 1



mas_pi = []
for i in range(a1):
    mas_pi.append(mas_count[i]/a)



mas_q = [] #вспомогательная вероятность
for i in range(a1):
    if (i == 0):
        mas_q.append(0)
    else:
        mas_q.append(mas_q[i-1] + mas_pi[i-1])
        
        

mas_Qi = []
for i in range(a1):
    mas_Qi.append(mas_q[i] + (mas_pi[i]/2))
    
  
    
mas_Li = []
for i in range(a1):
    mas_Li.append(math.ceil((-math.log2(mas_pi[i])) + 1))



mas_Ixi = []
length = 0
for i in range(a1):
    mas_Ixi.append(((-math.log2(mas_pi[i]))))
    length += mas_Li[i] * mas_pi[i]
length = length



mas_kod = []
for i in range(a1):
    q = mas_Qi[i]
    str_ = ''
    for i in range(mas_Li[i]):
        q *= 2
        if q//1 == 1:
            str_ += '1'
            q -= 1
        else:
            str_ += '0'
    mas_kod.append(str_)
    
print("|==================================================================================|")
print("|  N   |   Xi  |     pi     |      qi    |      Qi    |  Ixi  |   Li  |     Ci     |")
print("|----------------------------------------------------------------------------------|")
for i in range(a1):
    print(f"|{i + 1:3}   |   {mas_sim[i]}   |   {mas_pi[i]:.4f}   |   {mas_q[i]:.4f}   |   {mas_Qi[i]:.4f}   |   {mas_Ixi[i]:.4f}   |   {mas_Li[i]}   |   {mas_kod[i]:9}|")



#2
a = len(line)
mas_sim2 = []
#mas1.append(line[0])
flag = 0
mas_for2 = []
for i in range (a-1):
    mas_for2.append(line[i] + line[i+1])
aa = len(mas_for2)
for i in range (a - 1):
    flag = 0
    for j in range(i):
        if mas_for2[i] == mas_for2[j]:
            flag = 1
    if flag == 0:
        mas_sim2.append(mas_for2[i])
a2 = len(mas_sim2)
mas_count2 = []
for i in range(a2):
    mas_count2.append(0)
    for j in range(aa):
        if(mas_sim2[i] == mas_for2[j]):
            mas_count2[i] += 1



mas_pi2 = []
for i in range(a2):
    mas_pi2.append(mas_count2[i]/aa)



mas_q2 = []
for i in range(a2):
    if (i == 0):
        mas_q2.append(0)
    else:
        mas_q2.append(mas_q2[i-1] + mas_pi2[i-1])
       
        
        
mas_Qi2 = []
for i in range(a2):
    mas_Qi2.append(mas_pi2[i] + (mas_count2[i]/2))



mas_Li2 = []
for i in range(a2):
    mas_Li2.append(math.ceil((-math.log2(mas_pi2[i])) + 1))



mas_Ixi2 = []
length2 = 0
for i in range(a2):
    mas_Ixi2.append(((-math.log2(mas_pi2[i]))))
    length2 += mas_Li2[i] * mas_pi2[i]
    
    
    
mas_kod2 = []
for i in range(a2):
    q = mas_Qi2[i]
    str_ = ''
    for i in range(mas_Li2[i]):
        q *= 2
        if q//1 == 1:
            str_ += '1'
            q -= 1
        else:
            str_ += '0'
    mas_kod2.append(str_)
print()
print()
print("|===================================================================================|")
print("|  N   |   Xi   |     pi     |      qi    |      Qi    |  Ixi  |   Li  |     Ci     |")
print("|-----------------------------------------------------------------------------------|")
for i in range(a2):
    print(f"|{i + 1:3}   |   {mas_sim2[i]}   |   {mas_pi2[i]:.4f}   |   {mas_q2[i]:.4f}   |   {mas_Qi2[i]:.4f}   |   {mas_Ixi2[i]:.4f}   |   {mas_Li2[i]}   |   {mas_kod2[i]:9}|")



#3
a = len(line)
mas_sim3 = []
#mas1.append(line[0])
flag = 0
mas_for3 = []
for i in range (a-2):
    mas_for3.append(line[i] + line[i+1]+line[i+2])
aaa = len(mas_for3)
for i in range (aaa - 1):
    flag = 0
    for j in range(i):
        if mas_for3[i] == mas_for3[j]:
            flag = 1
    if flag == 0:
        mas_sim3.append(mas_for3[i])
a3 = len(mas_sim3)
mas_count3 = []
for i in range(a3):
    mas_count3.append(0)
    for j in range(aaa):
        if(mas_sim3[i] == mas_for3[j]):
            mas_count3[i] += 1



mas_pi3 = []
for i in range(a3):
    mas_pi3.append(mas_count3[i]/aaa)



mas_q3 = []
for i in range(a3):
    if (i == 0):
        mas_q3.append(0)
    else:
        mas_q3.append(mas_q3[i-1] + mas_pi3[i-1])
        
        

mas_Qi3 = []
for i in range(a3):
    mas_Qi3.append(mas_pi3[i-1] + (mas_count3[i-1]/2))



mas_Li3 = []
for i in range(a3):
    mas_Li3.append(math.ceil((-math.log2(mas_pi3[i])) + 1))
    
    
    
mas_Ixi3 = []
length3 = 0
for i in range(a3):
    mas_Ixi3.append(((-math.log2(mas_pi3[i]))))
    length3 += mas_Li3[i] * mas_pi3[i]



mas_kod3 = []
for i in range(a3):
    q = mas_Qi3[i]
    str_ = ''
    for i in range(mas_Li3[i]):
        q *= 2
        if q//1 == 1:
            str_ += '1'
            q -= 1
        else:
            str_ += '0'
    mas_kod3.append(str_)
print()
print()
print("|====================================================================================|")
print("|  N   |   Xi    |     pi     |      qi    |      Qi    |  Ixi  |   Li  |     Ci     |")
print("|------------------------------------------------------------------------------------|")
for i in range(a3):
    print(f"|{i + 1:3}   |   {mas_sim3[i]}   |   {mas_pi3[i]:.4f}   |   {mas_q3[i]:.4f}   |   {mas_Qi3[i]:.4f}   |   {mas_Ixi3[i]:.4f}   |   {mas_Li3[i]}   |   {mas_kod3[i]:9}|")

print("Средняя длина для 1 символа:", "%.5f" % length)
print("Средняя длина для 2 символа:", "%.5f" % length2)
print("Средняя длина для 3 символа:", "%.5f" % length3)

print("Средняя скорость для 1 символа:", "%.5f" % length)
print("Средняя скорость для 2 символа:", "%.5f" % (length2/2))
print("Средняя скорость для 3 символа:", "%.5f" % (length3/3))       