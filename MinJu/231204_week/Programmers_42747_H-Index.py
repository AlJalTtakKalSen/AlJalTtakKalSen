def solution(citations):
    answer = len(citations)
    citations.sort(reverse=True) # 내림차순 
    
    #H_index가 존재하고 넘는 논문의 개수 
    for i in range(len(citations)):
        if(citations[i] < i+1):
            return i
    return answer # 횟수가 같으면 전체 