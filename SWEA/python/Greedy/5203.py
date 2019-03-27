# 1. 각 카드를 p1, p2에 저장하면서 triplet, run 확인
#   1.1. 카드를 저장할 때 selection sort 방식으로 정렬하면서 저장
# 2. run 확인: 정렬된 숫자 중에서 동일한 3개가 있을 경우 True
# 3. triplet 확인: 숫자 중에서 3개를 선택해서 확인



t = int(input())
tc = 1

def put(p, seq):
    for i in range(seq, 0, -1):
        if p[i-1] > p[i]:
            temp = p[i-1]
            p[i-1] = p[i]
            p[i] = temp
        else:
            break


def isRun(n1, n2, n3):
    if n1 == n2 and n2 == n3:
        return True
    else:
        return False

    
def isTriplet(p, start, seq, level, l):
    if level == 3:
        if l[0]+1 == l[1] and l[1]+1 == l[2]:
            return True
        else:
            return False

    for i in range(start, seq+1):
        l.append(p[i])
        if(isTriplet(p, i+1, seq, level+1, l)): return True
        l.pop()

    return False


def scan(p, seq):
    last = 2
    
    triplet = isTriplet(p, 0, seq, 0, [])
    if triplet:
        return True

    run = False
    while last <= seq:
        a = p[last-2]
        b = p[last-1]
        c = p[last]
        run = isRun(a, b, c)
        if run :
            return True
        last += 1
    
    return False


while tc <= t:
    ans = 0
    cards = list(map(int, input().split()))
    p1 = [-1 for _ in range(6)]
    p2 = [-1 for _ in range(6)]
    
    for i in range(2):
        p1[i] = cards[2*i]
        put(p1, i)
        p2[i] = cards[2*i+1]
        put(p2, i)
    
    for i in range(2, 6):
        p1[i] = cards[2*i]
        put(p1, i)
        win1 = scan(p1, i)
        
        p2[i] = cards[2*i+1]
        put(p2, i)
        win2 = scan(p2, i)
        
        if win1:
            ans = 1
            break
        elif win2:
            ans = 2
            break
        
    print("#{} {}".format(tc, ans))
    tc += 1