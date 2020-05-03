##def apply (itr, func, inplace = False):
##    if inplace:
##        for i in range (len(itr)):
##            itr[i] = func(itr[i])
##        return None
##    else:
##        itr2 = []
##        for value in itr:
##            itr2.append(func(value))
##        return itr2

##def add1(num):
##    return num + 1

##import time

##rep = 1000
##maxsize = 200

##factorial = lambda x: 1 if x<=1 else x*factorial(x-1)

##tot = 0
##for _ in range(rep):
##    start = time.time_ns()

##    for i in range (200):
##        factorial (i)

##    end = time.time_ns()
##    tot += end - start

##print ("Time taken (microseconds): " + str(tot/rep * 10**-3))

##Función que recibe un argumento (x) y devuelve una función que recibe un argumento (y) y 
##devuelve la suma de x e y.
#HOF = lambda x: lambda y: x+y

#num = 1

#increment = HOF(num)

#lista1 = list(range(1,5))           #Lista1 = [1,2,3,4]
#lista1 = list(map(increment,lista1))   #Lista1 = [2,3,4,5]. Sumó 1.

#print (lista1)

#num = 17

#lista1 = list(map(increment,lista1))   #Lista1 = [7,8,9,10]. Sumó 5.

#print (lista1)

#Recibe un parámetro y devuelve una función
#que recibe otro parámetro y devuelve la suma
#de ambos parámetros.
#HOF = lambda x: lambda y: x+y

##Lista1 = [1,2,3,4]
#lista1 = list(range(1,5))

##Lista1 = [2,3,4,5]. Sumó 1.
#lista1 = list(map(HOF(1),lista1))

##Lista1 = [7,8,9,10]. Sumó 5.
#lista1 = list(map(HOF(5),lista1))

from copy import deepcopy
from math import sqrt

#Recibe un valor y una serie de funciones y
#devuelve el resultado de aplicarle sucesivamente 
#las funciones a ese valor.
def HOF (value, *args):
    temp = deepcopy(value)
    for func in args:
        temp = func(temp)

    return temp

def squared(num):
    return num**2

num = 3

#num2 = 3*2 + 6 = 12
num2 = HOF(num,lambda x: x*2, lambda x: x+6)

#num3 = (12/4)^2 + 12/4 = 12
num3 = HOF(num2,lambda x: x/4, squared, lambda x: x + sqrt(x))


print (num2)
print (num3)