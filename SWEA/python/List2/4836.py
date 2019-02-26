tc = 1
t = int(input())
MAX_NUM = 99999

while tc <= t :
    n = int(input())
    colorMap = []

    for i in range(10) :
        colorMap.append([])
        for j in range(10) :
            colorMap[i].append(0)
            
    ans = 0
    for _ in range(n) :
        x1, y1, x2, y2, c = tuple(map(int, input().split(' ')))

        for i in range(x1, x2+1) :
            for j in range(y1, y2+1) :
                colorMap[i][j] += c
                if colorMap[i][j] >= 3 and colorMap[i][j] < MAX_NUM :
                    ans += 1
                    colorMap[i][j] = MAX_NUM
    
    print(f"#{tc} {ans}")
    tc += 1