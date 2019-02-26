dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

array = []

def isInside(y, x) :
    if y >= 5 or y < 0 :
        return False
    if x >= 5 or x < 0 :
        return False
    
    return True

def numAbs(paraNum) :
    return paraNum if paraNum > 0 else -paraNum

for i in range(5) :
    array.append([])
    for j in range(5) :
        array[i].append(0)

array = [[1, 1, 1, 1, 1], [1, 0, 0, 0, 1], [1, 0, 0, 0, 1], [1, 0, 0, 0, 1], [1, 1, 1, 1, 1],]

ans = 0

for i in range(5) :
    for j in range(5) :
        arraySum = 0
        for d in range(4) :
            if isInside(i+dy[d], j+dx[d]) :
                arraySum += numAbs(array[i][j] - array[i+dy[d]][j+dx[d]])
        
        ans += arraySum

print(ans)