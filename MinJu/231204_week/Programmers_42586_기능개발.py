def solution(progresses, speeds):
    answer = []
    
    while progresses: # 작업 수가 empty일 때까지 반복
        count = 0 # 배포되는 기능 수 
        # 작업이 남아있고 첫 번째 작업이 완료되었다면
        while progresses and progresses[0] >= 100:
            count += 1 # 배포되는 기능 수에 카운트
            # 작업 리스트와 개발 속도 리스트에서 모두 제거 
            progresses.pop(0) 
            speeds.pop(0)
        # 작업 리스트의 진도 증가 
        progresses = [progresses[i] + speeds[i] for i in range(len(progresses))]
        
        # count가 존재하면 (오늘 배포)
        if count:
            answer.append(count) # 결과에 가
    return answer  