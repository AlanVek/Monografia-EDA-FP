from functools import partial

#Devuelve la suma de dos números.
adder = lambda x,y: x+y

#Devuelve adder con el primer parámetro fijado en num.
HOF = lambda num: partial(adder,num)

increment = HOF(1)
add5 = HOF(5)

#Imprime 6.
print (increment(5))

#Imprime 10.
print (add5(5))
