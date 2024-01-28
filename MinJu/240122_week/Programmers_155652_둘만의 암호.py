# s의 각 알파벳을 index만큼 뒤 알파벳으로 변환
# z를 넘어갈 경우 다시 a로
# skip에 있는 알파벳은 제외하고 건너뜀

def solution(s, skip, index):
    answer = ""

    alpha = "abcdefghijklmnopqrstuvwxyz"

    for i in skip:
        if i in alpha:
            alpha = alpha.replace(i, "")  # 알파벳 내 skip 문자 제거

    for i in s:
        if i in alpha:
            # 알파벳 변환 (문자 인덱스 + index)%(alpha 길이)
            tmp = alpha[(alpha.index(i) + index) % len(alpha)]
            answer += tmp
        else:
            answer += i  # s의 문자가 alpha에 없다면 그대로 추가

    return answer

