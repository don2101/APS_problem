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
    j = e

    while i < j:
        while i <= e and array[i] <= pivot: i += 1
        while j >= s and array[j] > pivot: j -= 1

        if i < j:
            array[i], array[j] = array[j], array[i]
            i += 1
            j -= 1
    
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