t = int(input())
tc = 1

gate = [0 for _ in range(100001)]
original = [0 for _ in range(100001)]
min_heap = [0 for _ in range(100001)]
max_heap = [0 for _ in range(100001)]


def max_upheap(num, n):
    global max_heap
    max_heap[n] = num
    idx = n

    while gate[max_heap[idx]] > gate[max_heap[idx//2]] and idx > 1:
        max_heap[idx], max_heap[idx//2] = max_heap[idx//2], max_heap[idx]
        idx = idx//2


def max_downheap(n):
    global max_heap
    ret_idx = max_heap[1]
    max_heap[1] = max_heap[n]

    idx = 1
    while idx <= (n-1)//2:
        max_idx = idx*2 if gate[max_heap[idx*2]] > gate[max_heap[idx*2+1]] else idx*2+1

        if gate[max_heap[idx]] < gate[max_heap[max_idx]]:
            max_heap[idx], max_heap[max_idx] = max_heap[max_idx], max_heap[idx]
            idx = max_idx
        else:
            break

    return ret_idx


def min_upheap(num, n):
    global min_heap
    min_heap[n] = num
    idx = n

    while idx > 1 and gate[min_heap[idx]] < gate[min_heap[idx//2]]:
        min_heap[idx], min_heap[idx//2] = min_heap[idx//2], min_heap[idx]
        idx = idx//2


def min_downheap(n):
    global min_heap
    ret_idx = min_heap[1]
    min_heap[1] = min_heap[n]

    idx = 1
    while idx <= (n-1)//2:
        min_idx = idx*2 if gate[min_heap[idx*2]] < gate[min_heap[idx*2+1]] else idx*2+1

        if gate[min_heap[idx]] > gate[min_heap[min_idx]]:
            min_heap[idx], min_heap[min_idx] = min_heap[min_idx], min_heap[idx]
            idx = min_idx
        else:
            break

    return ret_idx


while tc <= t:
    ans = 0
    n, m = (map(int, input().split()))
    
    div = m // n
    remain = m % n

    for i in range(0, n):
        gate[i] = int(input())
        original[i] = gate[i]
        gate[i] *= div

    idx = 0
    while remain > 0:
        gate[idx] += original[idx]
        idx += 1
        remain -= 1

    for i in range(0, n):
        max_upheap(i, i+1)
        min_upheap(i, i+1)

    pre_min_idx = 0
    pre_max_idx = 0

    while True:
        find = False
        
        min_idx = min_downheap(n)
        max_idx = max_downheap(n)
        
        max_half = (gate[max_idx]//original[max_idx])//2
        min_half = (gate[min_idx]//original[min_idx])//2

        if gate[min_idx]+original[min_idx] < gate[max_idx]:
            gate[max_idx] = original[max_idx]*max_half
            
            gate[min_idx] = original[min_idx]*(max_half+min_half)

            min_upheap(min_idx, n)
            max_upheap(max_idx, n)
            
            find = True
        
        if not find: break
    
    max_idx = max_heap[1]

    ans = gate[max_idx]
    print("#{} {}".format(tc, ans))
    tc += 1
    
