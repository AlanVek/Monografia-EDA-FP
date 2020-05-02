 #Lista1 = [0,1,2,3,4]
lista1 = list(range(5))

#Se debe declarar lista vacía primero.
lista2 = []

 #Lista2 = [2,4,6,8,10]
for value in lista1:
    lista2.append((value+1) * 2)

#Equivalentemente...

 #En una línea, se logró que lista3 = [2,4,6,8,10]
lista3 = [2*(i+1) for i in lista1]

#Otra forma, con lambdas y comprensión.
my_func = lambda x: 2*(x+1)

#Lista4 = [2,4,6,8,10]
lista4 = [my_func(i) for i in lista1 ]   

