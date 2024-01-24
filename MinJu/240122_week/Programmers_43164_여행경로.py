# 여행경로

def solution(tickets):
    answer = []
    dic = {}
    # 출발지:도착지 딕셔너리 생성
    for i, j in tickets:
        dic[i] = dic.get(i, []) + [j]

    # 경로가 2개 이상이면 알파벳 순이므로 뒤에서부터 꺼내기 위해 내림차순 정렬
    for i in dic.keys():
        dic[i].sort(reverse=True)
    stack = ["ICN"]  # 출발점 ICN

    while stack:
        tmp = stack[-1]  # 스택 마지막 원소
        # 딕셔너리에 없거나 tmp를 시작점으로 하는 항공권이 없으면
        if tmp not in dic or len(dic[tmp]) == 0:
            # 스택에서 꺼내 방문하는 경로에 저장
            answer.append(stack.pop())
        # 그렇지 않으면 tmp를 시작점으로 하는 도착지 중 마지막 원소를 꺼내 스택에 추가
        else:
            stack.append(dic[tmp][-1])
            dic[tmp] = dic[tmp][:-1]

    answer = answer[::-1]
    return answer

