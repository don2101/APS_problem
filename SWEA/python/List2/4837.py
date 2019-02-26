tc =1
t = int(input())

numbers = [i for i in range(1, 13)]

while tc <= t :
    n, k = tuple(map(int, input().split(' ')))
    ans = 0
    
    for i in range(1 << 12) :
        nums = 0
        numberSum = 0
        for j in range(12) :
            if (1 << j) & i > 0 :
                nums += 1
                numberSum += numbers[j]
            if nums > n :
                break
        
        if nums == n and numberSum == k :
            ans += 1
    
    print(f"#{tc} {ans}")
    tc += 1