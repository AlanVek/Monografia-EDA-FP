#def apply (itr, func, inplace = False):
#    if inplace:
#        for i in range (len(itr)):
#            itr[i] = func(itr[i])
#        return None
#    else:
#        itr2 = []
#        for value in itr:
#            itr2.append(func(value))
#        return itr2

def add1(num):
    return num + 1

import time

rep = 1000
maxsize = 200

factorial = lambda x: 1 if x<=1 else x*factorial(x-1)

tot = 0
for _ in range(rep):
    start = time.time_ns()

    for i in range (200):
        factorial (i)

    end = time.time_ns()
    tot += end - start

print ("Time taken (microseconds): " + str(tot/rep * 10**-3))

