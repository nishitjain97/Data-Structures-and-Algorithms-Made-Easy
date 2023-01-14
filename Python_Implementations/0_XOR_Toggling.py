x = 10
y = 20

i = 0
n = x
while True:
    print(n)
    n = n ^ (x ^ y)
    i += 1

    if i == 10:
        break