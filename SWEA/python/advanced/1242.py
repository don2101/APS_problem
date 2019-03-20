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

def isSame(graph, visited, y, x, height):
    cy = y
    cx = x

    for i in range(height):
        visited[cy][cx] = True
        if not visited[cy+1][cx] and graph[cy][cx] == graph[cy+1][cx]:
            cy+=1
        else:
            return False
    
    return True


def calculate(graph, visited, y, x):
    sy = y
    sx = x
    code_array = ['0' for _ in range(500)]
    code_point = 0
    
    height_length = 0

    while graph[sy][x] == graph[sy+1][x]:
        height_length += 1
        sy += 1

    sy = y

    while sx >= 0 and not visited[y][sx]:
        if isSame(graph, visited, y, sx, height_length):
            code_array[code_point] = graph[y][sx]
            code_point += 1
            sx -= 1
        else:
            break
    
    # for i in range(h):
    #     for j in range(w):
    #         print(graph[i][j], end="")
    #     print()

    bin_array = ['0' for _ in range(2000)]
    bin_point = 0

    for i in range(code_point-1, -1, -1):
        num = code[code_array[i]]
        for j in range(4):
            bin_array[bin_point] = num[j]
            bin_point += 1

    bin_width = 1
    
    print(bin_array)

    while True:
        temp_number = ''

        for i in range(bin_point-(7*bin_width), bin_point):
            temp_number += bin_array[i]

        if number_code[temp_number] is not None:
            break
        else: bin_width += 1 
    
    ey = 0
    for i in range(bin_point-1, -1, -1):
        if bin_array[i] != '0':
            ey = i
            break
    
    sy = ey-(bin_width*56)+1
    
    num_array = [0 for _ in range(8)]
    num_point = 0

    count = 0
    temp_array = ['0' for _ in range(7)]
    for i in range(sy, ey+1, bin_width):
        temp_array[count] = bin_array[i]
        count += 1
        if count >= 7:
            string = ''
            for j in range(7):
                string += temp_array[j]
            num_array[num_point] = number_code[string]
            count = 0
            num_point += 1
    
    odd = 0
    even = 0
    for i in range(7):
        if i & 1:
            even += num_array[i]
        else:
            odd += num_array[i]
    
    result = odd*3 + even + num_array[7]
    if result%10 == 0:
        return odd+even+num_array[7]
    else: return 0

sys.stdin = open("sample_input.txt", "r")

t = int(input())
tc = 1           


while tc <= t:
    ans = 0
    h, w = (map(int, input().split()))
    graph = [[0 for _ in range(500)] for _ in range(2000)]
    visited = [[False for _ in range(500)] for _ in range(2000)]

    for i in range(h) :
        graph[i] = input()
    
    for i in range(h) :
        for j in range(w-1, -1, -1) :
            if graph[i][j] != '0' and not visited[i][j]:
                ans += calculate(graph, visited, i, j)
    
    print("#{} {}".format(tc, ans))
    tc += 1

