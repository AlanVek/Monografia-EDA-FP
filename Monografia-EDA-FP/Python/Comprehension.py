
lista1 = list(range(5))         #Lista1 = [0,1,2,3,4]

lista2 = []                     #Se debe declarar lista vacía primero.

for value in lista1:
    lista2.append((value+1) * 2)    #Lista2 = [2,4,6,8,10]

#Equivalentemente...

lista3 = [2*(i+1) for i in lista1]    #En una línea, se logró que lista3 = [2,4,6,8,10]

#Otra forma, con lambdas y comprensión.

my_func = lambda x: 2*(x+1)

lista4 = [my_func(i) for i in lista1]   #Lista4 = [2,4,6,8,10]


