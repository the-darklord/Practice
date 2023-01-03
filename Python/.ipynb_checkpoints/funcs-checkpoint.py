def addNumbers(*args):
    s=0
    for i in args:
        s+=x
    return s

def fact(n):
    facto=1
    for i in range(1,n+1):
        facto*=i
    return facto

def checkNumeric(x):
    if(isinstance(x,(int,float))):
        return True
    return False

def revstr(x):
    x=str(x)
    return x[::-1]