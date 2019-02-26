"""
카드의 갯수를 각 카드 숫자의 인덱스에 저장하고 최종 값을 출력한다.
"""

t = int(input())

for tc in range(1, t+1) :
    n = int(input())
    tempCard = int(input())
    
    number = []
    card = []
    while tempCard > 0 :
        card.append(tempCard % 10)
        tempCard //= 10
    
    for i in range(0, 10) :
        number.append(0)
    
    for i in card :
        number[i] += 1
    
    maxCard = -1
    maxNum = -1
    for i in range(0, 10) :
        if maxNum <= number[i] :
            maxCard = i
            maxNum = number[i]
    
    print("#{} {} {}".format(tc, maxCard, maxNum))
    
    
    