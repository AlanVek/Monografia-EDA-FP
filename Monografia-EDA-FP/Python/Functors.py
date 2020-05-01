

#increment = lambda x: x+1

#lista1 = list(range(1,6))                   #Lista1 = [1,2,3,4,5]

#lista1 = list(map(increment,lista1))        #Lista1 = [2,3,4,5,6]



class Adder:
    def __init__(self,num):
        self.num = num

    def __call__(self,nn):
        return self.num + nn

Adder.__init__ = lambda adder,num: None

add3 = Adder(3)          #Add3 pareciera ser una función que suma 3.

print (add3(1))         #El programa se rompe, porque add3.num no está definido.




