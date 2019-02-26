t = int(input())
tc = 1

table = [[0 for _ in range(0, 10)] for _ in range(0, 10)]
visited = [[False for _ in range(0, 10)] for _ in range(0, 10)]

def calculate(table, visited, length, row, minValue, sumValue) :
    if row == length :
        return minValue if minValue < sumValue else sumValue
    
    
    for i in range(length) :
        if not visited[i] and sumValue+table[row][i] < minValue:
            visited[i] = True
            sumValue += table[row][i]
            minValue = calculate(table, visited, length, row+1, minValue, sumValue)
            sumValue -= table[row][i]
            visited[i] = False
    
    return minValue

while tc <= t :
    ans = 99999
    length = int(input())
    for i in range(length) :
        table[i] = list(map(int, input().split()))
        visited[i] = False
    
    candidate = []
    ans = calculate(table, visited, length, 0, ans, 0)
    
    print("#{} {}".format(tc, ans))
    tc += 1