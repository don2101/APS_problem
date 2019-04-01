# 1. 이진 탐색, 가지 치기 문제
# 2. 조건: 다음으로 find가 갖게 될 값과 이전의 find 값이 동일하면 조건에 부합하지 않는것으로 설정
# 3. find = 1: 오른쪽, find = -1: 왼쪽
# 4. 이진 탐색을 하며 조건에 부합하지 않을 경우 탐색을 종료


t = int(input())
tc = 1
ans = 0

def quick_sort(array, start, end):
    if start < end:
        mid = partition(array, start, end)
        quick_sort(array, start, mid-1)
        quick_sort(array, mid+1, end)


def partition(array, start, end):
    pivot = array[start]
    i = start
    j = end
    
    while j > i:
        while i <= end and pivot >= array[i]: i += 1   
        while j >= start and pivot < array[j]: j -= 1
        
        if j > i: 
            array[i], array[j] = array[j], array[i]
            j -= 1
            i += 1

    array[j], array[start] = array[start], array[j]

    return j


def binary_search(a, s, e, num, find):
    global ans
    if s > e:
        return
    mid = (s+e)//2
    
    if a[mid] < num:
        if find < 1:
            find = 1
            binary_search(a, mid+1, e, num, find)
        else: return
    elif a[mid] > num:
        if find > -1:
            find = -1
            binary_search(a, s, mid-1, num, find)
        else: return
    else:
        if find <= 1 and find >= -1:
            ans += 1
    

while tc <= t:
    ans = 0
    n, m = (map(int ,input().split()))
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    a.sort()
    
    for i in range(m):
        binary_search(a, 0, n-1, b[i], 0)
    
    print("#{} {}".format(tc, ans))
    tc += 1