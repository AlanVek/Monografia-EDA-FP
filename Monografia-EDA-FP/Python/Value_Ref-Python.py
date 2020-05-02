#Cargamos la lista con las expresiones lambda.
v_lambdas = []
for i in range (1,5):
    v_lambdas.append(lambda x: x + i)

#Imprime 9 9 9 9, porque i fue capturado del entorno por referencia.
for lam in v_lambdas:
    print (lam(5), end = ' ')

print ('\n')

i = 0

#Imprime 5 5 5 5, porque el cambio de i afecta a las funciones.
for lam in v_lambdas:
    print (lam(5), end = ' ') 
print ('\n')


#def add1(num):
#    return num + 1

##v_function y v_lambda son [1,2,3,4]
#v_function = list(range(1,5))
#v_lambda = list(range(1,5))

##v_function = [2,3,4,5]
#v_function = list(map(add1,v_function))

##v_lambda = [2,3,4,5]
#v_lambda = list(map(lambda x: x+1,v_lambda))


