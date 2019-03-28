a1 = [1, 5, 4, 3, 7, 5, 6, 3, 7, 9]
a2 = [11, 45, 23, 81, 28, 34]
a3 = [11, 45, 22, 81, 23, 34, 99, 22, 17, 8]
a4 = [1, 1, 1, 1, 0, 0, 0, 0]
a5 = [2, 2, 1, 1, 3]
a6 = [0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0]

a7 = [i for i in range(1000000, 0, -1)]


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


quick_sort(a1, 0, len(a1)-1)
print(a1)
quick_sort(a2, 0, len(a2)-1)
print(a2)
quick_sort(a3, 0, len(a3)-1)
print(a3)
quick_sort(a4, 0, len(a4)-1)
print(a4)
quick_sort(a5, 0, len(a5)-1)
print(a5)
quick_sort(a6, 0, len(a6)-1)
print(a6)
quick_sort(a7, 0, len(a7)-1)
print(a7)


