# 1. k-selection 알고리즘
# 2. 퀵 소트를 구현하고 찾는 인덱스가 포함된 부분만 다시 퀵소트
# 3. nlogn이 걸릴 문제를 줄일 수 있다

t = int(input())
tc = 1


def quick_sort(array, s, e, find):
    if s >= e:
        return
    m = divide(array, s, e)
    if find < m:
        quick_sort(array, s, m-1, find)
    elif find > m:
        quick_sort(array, m+1, e, find)
    else:
        return 


def divide(array, s, e):
    pivot = array[s]
    i = s
    j = e+1

    while i < j:
        i += 1
        while i <= e and array[i] < pivot: i += 1
        j -= 1
        while j >= s and array[j] > pivot: j -= 1

        if i < j:
            array[i], array[j] = array[j], array[i]
            
    array[s], array[j] = array[j], array[s]

    return j


while tc <= t:
    ans = 0
    n = int(input())
    array = list(map(int, input().split()))
    
    quick_sort(array, 0, n-1, n//2)
    ans = array[n//2]

    print("#{} {}".format(tc, ans))
    tc += 1
    