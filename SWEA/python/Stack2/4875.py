t = int(input())
tc = 1

table = [[0 for i in range(100)] for j in range(100)]
stackX = [0] * 20000
stackY = [0] * 20000
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def isInside(y, x, n) :
    if y >= n or y < 0 : return False
    if x >= n or x < 0 : return False
	
    return True

while tc <= t :
    length = int(input())
    ans = 0
    sx = 0
    sy = 0
    top = -1
    
    for i in range(length) :
        tmp = input()
        for j in range(len(tmp)) :
            table[i][j] = tmp[j]
            
            if table[i][j] == '2' :
                sx = j; sy = i
    
    top += 1; stackX[top] = sx; stackY[top] = sy
    cx = sx
    cy = sy
    
    while(top >= 0) :
        if table[cy][cx] == '3' : ans = 1; break
        table[cy][cx] = '1'
        check = False
        d = -1
        for i in range(0, 4) :
            if table[cy+dy[i]][cx+dx[i]] != '1' and isInside(cy+dy[i], cx+dx[i], length) :
                check = True
                d = i
                break
        
        if(check) :
            top += 1; stackX[top] = cx; stackY[top] = cy
            cy = cy+dy[d]
            cx = cx+dx[d]
            continue
            
        cy = stackY[top]
        cx = stackX[top]
        top -= 1
    
    print("#{} {}".format(tc, ans))
    tc += 1