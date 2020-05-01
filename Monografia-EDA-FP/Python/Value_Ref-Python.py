n = 5
test_value = 5
v_lambdas = [lambda x: x+i for i in range (n)] #Cargamos la lista con las expresiones lambda.

for lam in v_lambdas:
    print (lam(test_value),end=' ') #Imprime siempre test_value + cant - 1, porque i fue capturado del entorno.
print ('\n')

#Equivalente...
v_lambdas_2 = []
for i in range (n):
    v_lambdas_2.append(lambda x: x + i)

for lam in v_lambdas_2:
    print (lam(test_value), end = ' ') #Imprime siempre test_value + cant - 1, porque i fue capturado del entorno.

print ('\n')

#Además, de esta manera se puede modificar el valor de i, lo que afectaría a las funciones.

i = 0
for lam in v_lambdas_2:
    print (lam(test_value), end = ' ') #Imprime siempre test_value, porque i fue capturado del entorno y ahora vale 0.
print ('\n')


