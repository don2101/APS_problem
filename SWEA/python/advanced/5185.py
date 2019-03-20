t = int(input())
tc = 1

dictionary = {
    'A': 10, 'B': 11, 'C': 12,
    'D': 13, 'E': 14, 'F': 15,
}

for i in range(10):
    dictionary[chr(i+ord('0'))] = i

while tc <= t:
    ans = 0
    n, string = (input().split())
    n = int(n)

    print("#{} ".format(tc), end="")
    
    for i in range(n):
        number = dictionary[string[i]]
        for j in range(3, -1, -1):
            if number & (1<<j):
                print('1', end="")
            else:
                print('0', end="")
    
    print()
    
    
    tc += 1