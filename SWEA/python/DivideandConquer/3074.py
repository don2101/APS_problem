t = int(input())
tc = 1

gate = [0 for _ in range(100001)]
original = [0 for _ in range(100001)]


while tc <= t:
    ans = 0
    n, m = (map(int, input().split()))
    
    div = m // n
    remain = m % n

    for i in range(0, n):
        gate[i] = int(input())
        original[i] = gate[i]
        gate[i] *= div

    while remain > 0:
        min_idx = 0
        for i in range(n):
            if gate[i] < gate[min_idx]:
                min_idx = i

        gate[min_idx] += original[min_idx]
        remain -= 1

    while True:
        find = False

        min_idx = 0
        max_idx = 0
        
        for i in range(n):
            if gate[i] < gate[min_idx]:
                min_idx = i
            if gate[i] > gate[max_idx]:
                max_idx = i
            
        if gate[min_idx]+original[min_idx] < gate[max_idx]:
            gate[min_idx] += original[min_idx]
            gate[max_idx] -= original[max_idx]
            find = True
        
        if not find: break
    
    max_idx = 0
    for i in range(n):
        if gate[i] > gate[max_idx]:
            max_idx = i

    ans = gate[max_idx]
    print("#{} {}".format(tc, ans))
    tc += 1
    
