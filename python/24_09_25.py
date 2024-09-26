try :
    print(1/0)
except ZeroDivisionError:
    print("Division by zero error")
else:
    print(" No error ")
finally:
    print("This will always be printed")

def addPrint(a,b):
    print(a+b)
def addReturn(a,b):
    return a + b

addPrint(1,2)
addReturn(1,2)

print('The result is', addPrint(1,2))
print('The result is', addReturn(1,2))