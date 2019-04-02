# 1. Disjoint-Set 문제. find와 union을 구현.

t = int(input())
tc = 1


def find(p, x):
    if p[x] == x: return x
    else:
        p[x] = find(p, p[x])
        return p[x]


def union(p, x, y):
    p[find(p, y)] = find(p, x)


while tc <= t:
    ans = 0
    n, m = (map(int, input().split()))
    num_list = list(map(int, input().split()))
    students = [i for i in range(n+1)]
    visited = [False for _ in range(n+1)]

    length = len(num_list)

    for i in range(0, length, 2):
        a = num_list[i]
        b = num_list[i+1]
        small = a if a < b else b
        big = b if a < b else a
        union(students, small, big)
    
    for i in range(1, n+1):
        find(students, i)

    for i in range(1, n+1):
        if not visited[students[i]]:
            visited[find(students, i)] = True
            ans += 1

    print("#{} {}".format(tc, ans))
    tc += 1
        
