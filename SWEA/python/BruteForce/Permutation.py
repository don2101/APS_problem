n = 3
r = 2
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


visited = [False for i in range(n)]
temp = [0 for i in range(n)]
array = [i for i in range(n)]
count = 0

def permutation2(array, visited, temp, k):
    if k == n:
        print(temp[:r])
        return

    for i in range(n):
        if visited[i]: continue
        
        temp[k] = array[i]
        visited[i] = True
        permutation2(array, visited, temp, k+1)
        visited[i] = False

permutation2(array, visited, temp, 0)

    