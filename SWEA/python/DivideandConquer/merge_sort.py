a1 = [1, 5, 4, 3, 7, 5, 6, 3, 7, 9]
a2 = [11, 45, 23, 81, 28, 34]
a3 = [11, 45, 22, 81, 23, 34, 99, 22, 17, 8]
a4 = [1, 1, 1, 1, 0, 0, 0, 0]


def mergesort(array, new_array, start, end):
    if start < end:
        mid = (end+start) // 2
        mergesort(array, new_array, start, mid)
        mergesort(array, new_array, mid+1, end)
        merge(array, new_array, start, mid, end)
        

def merge(array, new_array, start, mid, end):
    i = start
    j = mid+1
    k = 0
    
    for p in range(start, end+1):
        new_array[p] = array[p]

    for k in range(start, end+1):
        if i > mid:
            array[k] = new_array[j]
            j += 1
        elif j > end:
            array[k] = new_array[i]
            i += 1
        elif array[i] < array[j]:
            array[k] = new_array[i]
            i += 1
        elif array[i] >= array[j]:
            array[k] = new_array[j]
            j += 1


new_array = [0 for _ in range(len(a1))]
mergesort(a1, new_array, 0, len(a1)-1)
print(a1)

new_array = [0 for _ in range(len(a2))]
mergesort(a2, new_array, 0, len(a2)-1)
print(a2)

new_array = [0 for _ in range(len(a3))]
mergesort(a3, new_array, 0, len(a3)-1)
print(a3)

new_array = [0 for _ in range(len(a4))]
mergesort(a4, new_array, 0, len(a4)-1)
print(a4)
