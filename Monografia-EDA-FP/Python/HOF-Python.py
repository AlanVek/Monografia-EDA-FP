def apply (iter, func, inplace = False):
    if inplace:
        for i in range (len(iter)):
            iter[i] = func(iter[i])
        return None
    else:
        itr2 = []
        for value in iter:
            itr2.append(func(value))
        return itr2

a = list(range(3))

b = apply(a,lambda x: x+1)

print (b)

apply(a, lambda x: x*2, inplace = True)

print (a)