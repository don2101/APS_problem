n = 10
r = 5
array = [i for i in range(n)]
count = 0

def permutation(array, k) :
    global r
    global n
    if k == r:
        print(array[:r])
        global count
        count += 1
        return

    for i in range(k, n):
        array[i], array[k] = array[k], array[i]
        permutation(array, k+1)
        array[i], array[k] = array[k], array[i]

permutation(array, 0)
print(count)

