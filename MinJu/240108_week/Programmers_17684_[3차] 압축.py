# 압축
# 사전에서 입력과 일치하는 가장 긴 문자열 w 찾기
# w의 사전 인덱스 출력 후 입력에서 w 제거
# 입력에 글자가 남아있다면(c) w+c에 해당하는 단어를 사전에 등록
# 위 과정 반복 -> 압축 후 사전 인덱스 번호 구하기

def solution(msg):
    answer = []
    # 사전 만들기
    dic = {} # 알파벳:색인번호(1부터)
    for i in range(26): # A(65)부터 Z까지
        dic[chr(65+i)] = i+1
    w, c = 0, 0
    while True:
        # 사전에 현재글자+다음글자 있으면 c값만 +1
        c += 1
        if c == len(msg): # c가 마지막이면
            answer.append(dic[msg[w:c]])
            break
            # w+c 단어 등록하고 종료 (c+1 상태)
        # 사전에 현재글자+다음글자 없으면
        if msg[w:c+1] not in dic:
            dic[msg[w:c+1]] = len(dic) + 1 # 등록
            answer.append(dic[msg[w:c]])
            w = c
    return answer