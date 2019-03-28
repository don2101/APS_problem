t = int(input())
tc = 1
cnt = 0

new_array = [0 for _ in range(1000000)]


def merge(array, new_array, s, m, e):
    a1_last = array[m]
    a2_last = array[e]
    i = s
    j = m+1

    for p in range(s, e+1):
        new_array[p] = array[p]

    for k in range(s, e+1):
        if i > m:
            array[k] = new_array[j]
            j += 1
        elif j > e:
            array[k] = new_array[i]
            i += 1
        elif new_array[i] < new_array[j]:
            array[k] = new_array[i]
            i += 1
        else:
            array[k] = new_array[j]
            j += 1
    return True if a1_last > a2_last else False


def merge_sort(array, new_array, s, e):
    if s >= e:
        return
    global cnt
    mid = (s+e+1)//2
    merge_sort(array, new_array, s, mid-1)
    merge_sort(array, new_array, mid, e)
    
    if array[mid-1] < array[mid]: 
        return
    if merge(array, new_array, s, mid-1, e):
        cnt += 1


while tc <= t:
    ans = 0
    cnt = 0
    n = int(input())
    array = list(map(int, input().split()))

    merge_sort(array, new_array, 0, n-1)
    ans = array[n//2]
    print("#{} {} {}".format(tc, ans, cnt))
    tc += 1
    