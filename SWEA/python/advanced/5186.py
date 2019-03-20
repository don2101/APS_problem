t = int(input())
tc = 1

while tc <= t:
    ans = 0
    n = float(input())
    num_array = [0 for _ in range(12)]
    num_point = 0
    
    while num_point < 12 and n > 0.0:
        n *= 2.0
        if n >= 1.0 :
            n -= 1.0
            num_array[num_point] = 1
        else :
            num_array[num_point] = 0
        num_point += 1
    
    print("#{}".format(tc), end=" ")
    if n > 0.0 and num_point >= 12:
        print('overflow')
    else:
        for i in range(num_point):
            print(num_array[i], end="")
        print()
    
    tc += 1