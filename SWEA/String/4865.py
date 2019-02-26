test = 1
tc = int(input())

while test <= tc :
    ans = 0
    p = input()
    t = input()
    
    table = [0] * 128
    p = set(p)
    
    for i in range(len(t)) :
        table[ord(t[i])] += 1
    
    for i in p :
        if table[ord(i)] > ans :
            ans = table[ord(i)]
    
    print(f"#{test} {ans}")
    test += 1