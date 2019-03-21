# 풀이 논리
# 1. 배열을 받으면서 압축
#   1.1 한줄을 받은 뒤 바로 위 배열과 비교
#   1.2 같다면 배열에 저장하지 않는다
# 2. 코드가 저장된 배열을 2진 배열로 변환
# 3. 2진 배열의 끝부터 읽으면서 1인 부분부터 비교 시작
#   3.1 7칸씩 읽어 dictionary에 있는지 비교
#   3.2 dictionary에 없는 경우 binary_width를 1칸 증가
#   3.3 dictionary에 존재할 경우 일치하지 않을 때 까지 읽고 일치하지 않는 위치를 저장
#       3.3.1 dictionary에 존재 하더라도 다른 width일 수 있으므로 이를 따로 처리
# 4. 일치하지 않는 위치부터 visited 처리


import sys

code = {
    '1': '0001', '2': '0010', '3': '0011', '4': '0100',
    '5': '0101', '6': '0110', '7': '0111', '8': '1000',
    '9': '1001', 'A': '1010', 'B': '1011', 'C': '1100',
    'D': '1101', 'E': '1110', 'F': '1111', '0': '0000'
}

number_code = {
    '0001101': 0, '0011001': 1, '0010011': 2,
    '0111101': 3, '0100011': 4, '0110001': 5,
    '0101111': 6, '0111011': 7, '0110111': 8,
    '0001011': 9,
}

def get_binary_code(graph, width, height):
    binary_code = [['0' for _ in range(2000)] for _ in range(height)]
    
    for k in range(height) :
        binary_point = 0
        for i in range(width):
            temp_code = code[graph[k][i]]
            
            for j in range(4):
                binary_code[k][binary_point] = temp_code[j]
                binary_point += 1
    
    return binary_code, binary_point


def get_number_code(binary_code, visited, y, x, height):
    start_y = y
    start_x = x

    binary_width = 1

    while True:
        temp_string = ''
        
        c1 = 0
        c2 = 0
        for i in range(x+binary_width-7*binary_width, x+1, binary_width):
            if binary_code[y][i] == '1': c1 += 1
            temp_string += binary_code[y][i]
        
        for i in range(x+1-7*binary_width, x+1, 1):
            if binary_code[y][i] == '1': c2 += 1
        
        if temp_string in number_code:
            if c2 // binary_width == c1 :
                break
            else :
                binary_width += 1    
        else:
            binary_width += 1
    
    end_x = x+binary_width-56*binary_width
    
    count = 0
    temp_string = ''
    num_code = [0 for _ in range(8)]
    num_point = 0
    
    for i in range(x+binary_width-56*binary_width, x+1, binary_width):
        temp_string += binary_code[y][i]
        count += 1

        if count >= 7 :
            number = number_code[temp_string]
            num_code[num_point] = number
            num_point += 1
            count = 0
            temp_string = ''

    while binary_code[start_y][x] == '1':
        for i in range(end_x, x+1):
            visited[start_y][i] = True
        start_y += 1
    print(binary_width)
    return num_code

def get_ans(num_code):
    odd = 0
    even = 0
    for i in range(7):
        if i & 1:
            even += num_code[i]
        else:
            odd += num_code[i]
    
    valid_code = num_code[7]
    
    if (odd*3 + even + valid_code) % 10 == 0:
        return odd + even + valid_code
    else:
        return 0


def isSame(temp_list, graph_list, width):
    for i in range(width):
        if temp_list[i] != graph_list[i]:
            return False

    return True


def list_copy(temp_list, graph_list, width):
    for i in range(width):
        graph_list[i] = temp_list[i]

sys.stdin = open("sample_input.txt", "r")

t = int(input())
tc = 1           


while tc <= t:
    ans = 0
    h, w = (map(int, input().split()))
    graph = [[0 for _ in range(500)] for _ in range(2000)]
    
    graph_height = 0
    list_copy(list(input()), graph[graph_height], w) 
    graph_height += 1

    for i in range(1, h) :
        temp_list = list(input())
        if not isSame(temp_list, graph[graph_height-1], w):
            list_copy(temp_list, graph[graph_height], w)
            graph_height += 1
    
    binary_code, binary_point = get_binary_code(graph, w, graph_height)
    visited = [[False for _ in range(binary_point)] for _ in range(graph_height)]

    for i in range(graph_height):
        for j in range(binary_point-1, -1, -1):
            if not visited[i][j] and binary_code[i][j] == '1':
                num_code = get_number_code(binary_code, visited, i, j, graph_height)
                ans += get_ans(num_code)

    print("#{} {}".format(tc, ans))
    tc += 1

