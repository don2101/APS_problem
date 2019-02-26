tc = 1
t = int(input())

while tc <= t :
    n = int(input())
    numbers = list(map(int, input().split()))
    
    for i in range(0, n) :
        comparer = numbers[i]
        pos = i
        
        if (i & 1) == 0 :
            for j in range(i, n) :
                if numbers[j] > comparer :
                    pos = j
                    comparer = numbers[j]
        else :
            for j in range(i, n) :
                if numbers[j] < comparer :
                    pos = j
                    comparer = numbers[j]
        
        temp = numbers[i]
        numbers[i] = numbers[pos]
        numbers[pos] = temp
    
    print(f"#{tc}", end=" ")
    for i in range(10) :
        print(numbers[i], end=" ")
    print()
    tc += 1