line = "Там лес и дол видений полны; там о заре прихлынут волны на брег песчаный и пустой. Что ж мы? на зимние квартиры? Не смеют, что ли, командиры чужие изорвать мундиры о русские штыки?"
import math

a = len(line)
#print(a)
mas_sim = []
# mas1.append(line[0])
flag = 0
for i in range(a - 1):
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
        if (mas_sim[i] == line[j]):
            mas_count[i] += 1

mas_pi = []
for i in range(a1):
    mas_pi.append(mas_count[i] / a)

mas_q = []  # вспомогательная вероятность
for i in range(a1):
    if (i == 0):
        mas_q.append(0)
    else:
        mas_q.append(mas_q[i - 1] + mas_pi[i - 1])

mas_po6 = []
for i in range(a):
    if i % 6 == 0:
        mas_po6.append(line[i] + line[i + 1] + line[i + 2] + line[i + 3] + line[i + 4] + line[i + 5])
Len = len(mas_po6)
N1 = 6
mas_kod = []
for i in range(0, a, 6):
    F = 0
    G = 1
    l = 0
    for k in range(i, i + 6, 1):
        for j in range(a1):
            if (mas_sim[j] == line[k]):
                l = j
        F = F + mas_q[l] * G
        G = G * mas_pi[l]
    Q = F + G / 2
    L = math.ceil((-math.log2(G) + 1))
    str_ = ''
    for p in range(L):
        Q *= 2
        if Q // 1 == 1:
            str_ += '1'
            Q -= 1
        else:
            str_ += '0'
    mas_kod.append(str_)

t = ''
v = 0
length = 0
for i in range(Len):
    length += len(mas_kod[i])
    t += mas_kod[i]
    v += len(mas_kod[i]) / 6
    #print(mas_po6[i], "  ", mas_kod[i])

length = length / Len
print(t)
print("Количество символов в закодированной строке: ", len(t))
print("Средняя длина кодового слова для посимвольного кодирования:", "  %.5f" % length)
print("Средняя скорость для посимвольного кодирования:", "  %.5f" % (v / Len))
print()
# 2

a = len(line)
mas_sim2 = []
# mas1.append(line[0])
flag = 0
mas_for2 = []
for i in range(a - 1):
    mas_for2.append(line[i] + line[i + 1])
aa = len(mas_for2)
#print(aa)
for i in range(aa):
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
        if (mas_sim2[i] == mas_for2[j]):
            mas_count2[i] += 1

mas_pi2 = []
for i in range(a2):
    mas_pi2.append(mas_count2[i] / aa)

mas_q2 = []
for i in range(a2):
    if (i == 0):
        mas_q2.append(0)
    else:
        mas_q2.append(mas_q2[i - 1] + mas_pi2[i - 1])

mas_po6_2 = []
for i in range(0, aa-4, 6):
    mas_po6_2.append(mas_for2[i] + mas_for2[i + 2] + mas_for2[i + 4])
    if i == (aa - 5):
        mas_po6.append(mas_for2[i-1] + mas_for2[i] + mas_for2[i+1])
Len2 = len(mas_po6_2)
mas_kod2 = []
for i in range(0, aa - 2, 3):
    F = 0
    G = 1
    l = 0
    for k in range(i, i + 3, 1):
        for j in range(a2):
            if (mas_sim2[j] == mas_for2[k]):
                l = j
        F = F + mas_q2[l] * G
        G = G * mas_pi2[l]
    Q = F + G / 2
    L = math.ceil((-math.log2(G) + 1))
    str_ = ''
    for p in range(L):
        Q *= 2
        if Q // 1 == 1:
            str_ += '1'
            Q -= 1
        else:
            str_ += '0'
    mas_kod2.append(str_)

t2 = ''
v2 = 0
length2 = 0
for i in range(Len2):
    length2 += len(mas_kod2[i])
    t2 += mas_kod2[i]
    v2 += len(mas_kod2[i]) / 6
    #print(mas_po6_2[i], "  ", mas_kod2[i])

length2 = length2 / Len2
print(t2)
print("Количество символов в закодированной строке: ", len(t2))
print("Средняя длина кодового слова для кодирования пар символов:", "  %.5f" % length2)
print("Средняя скорость для кодирования пар символов:", "  %.5f" % (v2 / Len2))
print()
a = len(line)
mas_sim3 = []
# mas1.append(line[0])
flag = 0
mas_for3 = []
for i in range(a - 2):
    mas_for3.append(line[i] + line[i + 1] + line[i + 2])
aaa = len(mas_for3)
for i in range(aaa):
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
        if (mas_sim3[i] == mas_for3[j]):
            mas_count3[i] += 1

mas_pi3 = []
for i in range(a3):
    mas_pi3.append(mas_count3[i] / aaa)

mas_q3 = []
for i in range(a3):
    if (i == 0):
        mas_q3.append(0)
    else:
        mas_q3.append(mas_q3[i - 1] + mas_pi3[i - 1])

mas_po6_3 = []
for i in range(0, aaa - 2, 6):
    mas_po6_3.append(mas_for3[i] + mas_for3[i + 3])
Len3 = len(mas_po6_3)
mas_kod3 = []
for i in range(0, aaa, 2):
    F = 0
    G = 1
    l = 0
    for k in range(i, i + 2, 1):
        for j in range(a3):
            if mas_sim3[j] == mas_for3[k]:
                l = j
        F = F + mas_q3[l] * G
        G = G * mas_pi3[l]
    Q = F + G / 2
    L = math.ceil((-math.log2(G) + 1))
    str_ = ''
    for p in range(L):
        Q *= 2
        if Q // 1 == 1:
            str_ += '1'
            Q -= 1
        else:
            str_ += '0'
    mas_kod3.append(str_)

t3 = ''
v3 = 0
length3 = 0
for i in range(Len3):
    length3 += len(mas_kod3[i])
    t3 += mas_kod3[i]
    v3 += len(mas_kod3[i]) / 6
    #print(mas_po6_3[i], "  ", mas_kod3[i])
length3 = length3 / Len3
print(t3)
print("Количество символов в закодированной строке: ", len(t3))
print("Средняя длина кодового слова для кодирования троек символов:", "  %.5f" % length3)
print("Средняя скорость для кодирования троек символов:", "  %.5f" % (v3 / Len3))
print()