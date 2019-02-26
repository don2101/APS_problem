array = [[9, 20, 2, 18, 11], [19, 1, 25, 3, 21], [8, 24, 10, 17, 7], [15, 4, 16, 5, 6], [12, 13, 22, 23, 14]]
newArray = []
checkArray = []

for i in range(5) :
    newArray.append([])
    checkArray.append([])

    for j in range(5) :
        newArray[i].append(0)
        checkArray[i].append(False)

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

x = 0
y = 0
d = 0
num = 1

def isInside(y, x) :
    if y >= 5 or y < 0 : 
        return False
    if x >= 5 or x < 0 :
        return False
    
    return True

for k in range(25) :
    minIndex = k
    minValue = array[minIndex//5][minIndex%5]
    
    for i in range(k, 25) :
        if array[i//5][i%5] < array[minIndex//5][minIndex%5] :
            minIndex = i
            minValue = array[i//5][i%5]

    num = array[minIndex//5][minIndex%5]
    array[minIndex//5][minIndex%5] = array[k//5][k%5]
    array[k//5][k%5] = num

    newArray[y][x] = num
    checkArray[y][x] = True

    if isInside(y+dy[d], x+dx[d]) and not checkArray[y+dy[d]][x+dx[d]] :
        y += dy[d]
        x += dx[d]
    else :
        d = (d+1)%4
        y += dy[d]
        x += dx[d]    

for i in range(5) :
    print(newArray[i], end="\n")


# def isInside(y, x) :
#     if y >= 5 or y < 0 : 
#         return False
#     if x >= 5 or x < 0 :
#         return False
    
#     return True


# dx = [1, 0, -1, 0]
# dy = [0, 1, 0, -1]

# x = 0
# y = 0
# d = 0
# num = 1

# newArray = []
# checkArray = []

# for i in range(5) :
#     newArray.append([])
#     checkArray.append([])

#     for j in range(5) :
#         newArray[i].append(0)
#         checkArray[i].append(False)

# while(num <= 25) :
#     newArray[y][x] = num
#     num += 1
#     checkArray[y][x] = True

#     if isInside(y+dy[d], x+dx[d]) and not checkArray[y+dy[d]][x+dx[d]] :
#         y += dy[d]
#         x += dx[d]
#     else :
#         d = (d+1)%4
#         y += dy[d]
#         x += dx[d]

# for i in range(5) :
#     print(newArray[i], end="\n")