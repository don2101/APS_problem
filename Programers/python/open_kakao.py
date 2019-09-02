 

def solution(record):
    nickname = {}
      
    # 만약 record가 Enter = in_out에 님이 들어왔습니다.
    # Leave = 님이 나갔습니다. 저장
    # 동시에 nickname에 저장
    # 이후 출력
    length = len(record)
    
    in_out = ["" for _ in range(length)]
    answer = ["" for _ in range(length)]
    userid = ["" for _ in range(length)] 
    
    for i in range(length):
        temp = record[i].split()
        
        if temp[0] == "Enter":
            in_out[i] = "님이 들어왔습니다."
            userid[i] = temp[1]
            nickname[temp[1]] = temp[2]
        elif temp[0] == "Leave":
            in_out[i] = "님이 나갔습니다."
            userid[i] = temp[1]
        else:
            nickname[temp[1]] = temp[2]
    print(nickname)

    for i in range(length):
        answer[i] = nickname[userid[i]] + in_out[i]
    

    return answer


solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])