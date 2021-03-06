# Iteration
Iteration is the act of repeating a process. Each repetition of the process is also called an "iteration", and the results of one iteration are used as the starting point for the next iteration.

# Recursion
The process in which a function calls itself directly or indirectly. The corresponding function is called as recursive function.

# Iteration vs Recursion
Recursion makes code smaller while iteration makes it longer.
Recursive functions may also be executed more slowly, much more stack space are used. 
Iterations make no such demands on stack space, and may be more efficient where memory is limited.
Recursion generates overhead of repeated function calls. 

# When to use recursion?
### Does the problem obviously break down into subproblems?
If you see a way to break a problem down into subproblems, then it can likely be solved easily using recursion.
### Is it easier to solve it recursively than iteratively?
Eg. BST problem is normally better to be solved by recursion instead of iteration.

# Stack Overflow
The most common cause of stack overflow is deep or infinite recursion. A function calls itself 
so many times that the space needed to store the variables and information associated with each call is more than can fit on the stack. In other words, it runs out stack space.

# Stack：
内存：目前学到的东西都是存在stack里，在一个function里面，一个int会占用一个空间，一个function也会占用空间，出了这个function，在function内部的int
所占用的空间就会被释放,释放空间的顺序是从下到上的。所以stack是first in last out的储存和释放空间的方式。

# Why iteration is better
用stack就可以解释为什么iteration会比recursion更好。以上面的loop为例，因为recursion要call自己的function，所以每call一次都要占用一个空间，而且
recursion是一层套一层的，最开始call的function要等最后call的function被return了才能依次倒着return出来，就是说只有当最后一个被call的function
被return之后，function所占用的空间才能一次逐个被释放，所以就会很慢。
如果recursion次数太多，就会出现stack overflow

```py
import time

def fib_recursive(n):
    print(n,end=' ')
    if n <= 1:
	    return 0
    if n == 2:
	    return 1
    return fib_recursive(n-1)+fib_recursive(n-2)

def fib_recursive_memo(n,dic):
    print(n,end=' ')
    if n <= 1:
	    return 0
    if n == 2:
	    return 1

    if n not in dic:
      dic[n] = fib_recursive_memo(n-1,dic)+fib_recursive_memo(n-2,dic)
    return dic[n]

def fib_iteration(n):
    if n <= 1:
        return 0
    if n == 2:
        return 1

    pre = 0
    current = 1
    
    while n >= 3:
        next = pre+current
        pre = current
        current = next
        n -= 1

    return next
   
time_start=time.time()
print("fib_recursive result:",fib_recursive(10))
time_end=time.time()
print("fib_recursive time:",time_end-time_start)

time_start=time.time()
dic = {}
print("fib_recursive_memo result:",fib_recursive_memo(10,dic))
time_end=time.time()
print("fib_recursive_memo time:",time_end-time_start)

time_start=time.time()
print("fib_iteration result:",fib_iteration(10))
time_end=time.time()
print("fib_iteration time:",time_end-time_start)


###############################################
# Simple recursive vs iteration
###############################################
def loop_recur(n):
  if n == 0:
    return

  loop_recur(n-1)
  print(n)

def loop_iter(n):
  for i in range(1,n+1):
    print(i)

loop_recur(10)
loop_iter(10)
```

# What is tail recursion?
A recursive function is tail recursive when recursive call is the last thing executed by the function. For example the following C++ function print() is tail recursive.

# Why do we care?
The tail recursive functions considered better than non tail recursive functions as tail-recursion can be optimized by compiler. Eg. If the first recursive func called the second recursive func by saying 'return func(n-1)', in this case, the compiler does not have to reserve any stack memory for the first recursive func because the final result is only depending on the next func.

## A NON-tail-recursive function. 
```py
def fact(n): 
  
    if (n == 0): 
        return 1
  
    return n * fact(n-1) 
```
## A tail recursive function 

```py

def factTR(n, a): 
  
    if (n == 0): 
        return a 
  
    return factTR(n - 1, n * a) 
  
# A wrapper over factTR 
def fact(n): 
    return factTR(n, 1) 
 ```















