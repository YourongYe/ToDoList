# Override keywords:
1. virtual function
2. only happen in class inheritance
3. the same signature (same function name, same parameters, and same return type)

# Overload keywords:
1. same function name, but must have different return type or parameter
2. can happen anywhere

```py
class people:
    sex = ''
    
    def __init__(self):
        self.arm = 4
        self.eye = 2

    def average_tempreture(self):
        print('Human aerage tempreture is 36.5')

class women(people):
    children = ''
    
    def __init__(self):
        super().__init__()
        self.period = 30
        
    def average_tempreture(self):
        print('Women average tempreture is 36.8')

    def pregnant(self,num):
        self.children = num

    def pregnant(self,age,height):
        print('She is %d years old and %d cm' % (age,height))



Amy = women()
print(Amy.period)
print(Amy.arm)
print(Amy.average_tempreture())
Amy.pregnant(34,168)
```
