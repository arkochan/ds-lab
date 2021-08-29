import math
# a = 25
# b = 4

# print(math.ceil(a/b)+1)
n = 222
m = 332
a = 5


if m%a == 0:
    x = int(m/a)
    print(x)
else:
    x = int(math.ceil(m/a))
    print(x)
if n%a == 0:
    y = int(n/a)
    print(y)
else:
    y = int(math.ceil(n/a))
    print(y)
print(x*y)