from itertools import accumulate
import operator
import matplotlib.pyplot as plt
from matplotlib.ticker import MultipleLocator
import numpy as np


l = [[] for i in range(10)]
max_level = 0

# with open('output1', 'r') as file:
#     data = file.readlines()
#     for line in data:
#         tmp_l = [int(i) for i in line.split(' ')]
#         cur_level = tmp_l[0]
#         max_level = max(cur_level, max_level)
#         for i in range(1, len(tmp_l)):
#             l[cur_level].append(tmp_l[i])

# for i in range(1, max_level + 1):
#     l[i] = list(accumulate(l[i], operator.add))
#     print(len(l[i]), l[i][-1])

# for i in range(max_level + 1):
#     print(len(l[i]))

with open('output2', 'r') as file:
    data = file.readlines()
    for line in data:
        max_level += 1
        l[max_level] = [float(i) for i in line.strip().split(' ')]

m = [[] for i in range(max_level + 1)]
for i in range(1, max_level + 1):
    # if (len(l[i]) > 100):
    #     t = len(l[i]) // 100
    #     l[i] = [l[i][j * t] for j in range(100)]
    #     m[i] = [j / 100 for j in range(100)]
    # else:
    #     m[i] = [j / len(l[i]) for j in range(len(l[i]))]

    m[i] = [(j + 1) / len(l[i]) for j in range(len(l[i]))]


plt.plot(m[1], l[1], color='blue')
plt.plot(m[2], l[2], color='green')
plt.plot(m[3], l[3], color='yellow')
plt.plot(m[4], l[4], color='orange')
plt.plot(m[5], l[5], color='red')

plt.savefig('1.png')
# plt.show()