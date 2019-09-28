# 체스의 비숍이 서로 잡히지 않도록 놓을 수 있는 공간을 구한다
# 일반 비숍을 다 놓고 가능한 공간을 탐색

dx = [1, 1, -1, -1]
dy = [-1, 1, 1, -1]

def isInside(i, j):
    if i >= 8 or i < 0: return False
    if j >= 8 or j < 0: return False
    
    return True
    

def check(chess_map, i, j):
    chess_map[i][j] = 1
    
    for d in range(4):
        x = j+dx[d]
        y = i+dy[d]
        
        while isInside(y, x) and (chess_map[y][x] == 0 or chess_map[y][x] == 2):
            chess_map[y][x] = 2
            x += dx[d]
            y += dy[d]
    

def solution(bishops):
    answer = 0
    chess_map = [[0 for _ in range(8)] for _ in range(8)]
    
    for bishop in bishops:
        j = ord(bishop[0]) - 65
        i = int(bishop[1]) - 1
        
        check(chess_map, i, j)
    
    for i in range(0, 8):
        for j in range(0, 8):
            if chess_map[i][j] == 0:
                answer += 1
                
    print(chess_map)
    
    return answer