# 개인정보 수집 유효기간

def solution(today, terms, privacies):
    answer = []
    ty, tm, td = map(int, today.split("."))  # 오늘 연도/월/일

    # {약관 종류:유효기간 일수} 딕셔너리 저장
    terms_dic = {}
    for i in terms:
        a, b = i.split(" ")
        terms_dic[a] = int(b) * 28

    for index, val in enumerate(privacies, start=1):  # 인덱스 1부터 시작
        a, b, c = val.split(".")  # 수집일자 연도/월/일+약관종류
        d, t = c.split(" ")  # 일/약관종류
        tmp = (ty - int(a)) * 12 * 28 + (tm - int(b)) * 28 + (td - int(d))  # 현재날짜로부터 약관일자 사이 날짜 계산
        print(tmp)
        if 0 <= tmp < terms_dic[t]:  # 기간이 지나지 않았으면 무시
            continue
        else:  # 지났으면 파기해야하므로 해당 인덱스 answer에 추가
            answer.append(index)
    return answer