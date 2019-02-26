test = 1
tc = int(input())

while test <= tc :
    ans = None
    n, m = tuple(map(int, input().split(' ')))
    t = []
    
    for _ in range(n) :
        tempString = input()
        t.append(tempString)

    for i in range(n) :
        for j in range(n-m+1) :
            s = j
            e = j+m-1
            switch = True
            while s <= e :
                if t[i][s] is not t[i][e] :
                    switch = False
                s +=1
                e -= 1
            if switch :
                temp = []
                for k in range(j, j+m) :
                    temp.append(t[i][k])
                ans = ''.join(temp)
                break
        if ans : break
    
    if ans :
        print(f"#{test} {ans}")
        test += 1
        continue

    for i in range(n) :
        for j in range(n-m+1) :
            s = j
            e = j+m-1
            switch = True
            while s <= e :
                if t[s][i] is not t[e][i] :
                    switch = False
                s += 1
                e -= 1
            if switch :
                temp = []
                for k in range(j, j+m) :
                    temp.append(t[k][i])
                ans = ''.join(temp)
                break
        if ans : break

    print(f"#{test} {ans}")
    test += 1