

#increment = lambda x: x+1

#lista1 = list(range(1,6))                   #Lista1 = [1,2,3,4,5]

#lista1 = list(map(increment,lista1))        #Lista1 = [2,3,4,5,6]


#Functor
class Adder:
    def __init__(self,num):
        self.num = num

    def __call__(self,nn):
        return self.num + nn

##Ahora Adder es un restador, no un sumador.
#Adder.__call__ = lambda adder,nn: nn - adder.num

#Adder.__call__ = lambda x: x+1

#Sobreescritura de método __init__.
Adder.__init__ = lambda adder, num: None

add3 = Adder(5)

#El programa se romperá, porque add3.num ahora
#no está definida.
print (add3(1))

#El programa se rompe, porque ahora Adder.__call__ 
#está recibiendo dos parámetros, pero espera uno.
#print (add3(1))

##Lista1 = [1,2,3,4]
#lista1 = list(range(1,5))

##Lista1 = [2,3,4,5]
#lista1 = list(map(Adder(1),lista1))

##Lista1 = [7,8,9,10]
#lista1 = list(map(Adder(5),lista1))




