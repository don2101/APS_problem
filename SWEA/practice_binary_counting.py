array = []

for i in range(10) :
    array.append(int(input()))

n = len(array)
ans = []
c = 0

for i in range(1, 1<<n) :
    numArray = []
    for j in range(n) :
        if i & (1<<j) > 0 :
            numArray.append(array[j])

    if sum(numArray) == 0 :
        ans.append(numArray)
        c += 1

for i in ans :
    print(i, end="\n")

print(c)