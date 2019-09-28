# 박스에 물건을 담는 문제
# input이 크므로 merge_sort를 통해 정렬하고 greedy로 해결

def merge_sort(array, length):
    divide(array, 0, length-1)
    
def divide(array, start, end):
    if end <= start: return

    mid = (start + end) // 2
    
    divide(array, start, mid)
    divide(array, mid+1, end)
    merge(array, start, mid, end)
    

def merge(array, start, mid, end):
    i = start
    j = mid+1
    length = end - start + 1
    if array[mid] <= array[j]: return
    temp_array = [0 for _ in range(length)]
    
    for k in range(length):
        if i > mid: 
            temp_array[k] = array[j]
            j += 1
        elif j > end:
            temp_array[k] = array[i]
            i += 1
        elif array[i] > array[j]:
            temp_array[k] = array[j]
            j += 1
        else:
            temp_array[k] = array[i]
            i += 1
            
    for k in range(length):
        array[k+start] = temp_array[k]
    
    
def solution(goods, boxes):
    answer = 0
    
    goods = sorted(goods)
    boxes = sorted(boxes)
    
    i = 0
    j = 0
    good_len = len(goods)
    box_len = len(boxes)
    merge_sort(boxes, box_len)
    merge_sort(goods, good_len)
    
    while i < good_len and j < box_len:
        if goods[i] <= boxes[j]:
            answer += 1
            i += 1
            j += 1
        else:
            j += 1
    
    return answer