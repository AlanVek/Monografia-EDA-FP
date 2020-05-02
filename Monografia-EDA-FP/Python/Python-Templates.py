

#Devuelve x+x si x es entero o lista, o devuelve x en otro caso.
func = lambda x: x+x if isinstance(x,int) or isinstance(x,list) else x    

 #Imprime 2.
print (func(1))

#Imprime [1,2,3,1,2,3]
print (func([1,2,3]))

#Imprime {'Hola' : 1, 'Chau' : 2}
print (func({'Hola' : 1, 'Chau' : 2}))

#Imprime range(0,5)
print (func(range(5)))

#Imprime "Hola"
print (func("Hola"))                    

#Imprime 1.6
print (func (1.6))                      

#Imprime <function<lambda>>
print (func(lambda x: x+1))             


