n = 3
r = 2
array = [i for i in range(n)]
visited = [False for i in range(n)]
temp = [0 for i in range(n)]
count = 0

def combination(array, visited, temp, k):
    global r
    global n
    global count
    
    if k == r:
        print(temp[:r])
        count += 1
        return
    elif n < r: return

    for i in range(k, n):
        temp[k] = array[i]
        combination(array, visited, temp, k+1)

combination(array, visited, temp, 0)
print(count)

