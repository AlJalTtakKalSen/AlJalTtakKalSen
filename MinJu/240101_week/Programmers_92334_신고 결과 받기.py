# 신고 결과 받기

# 불량 이용자를 신고하고 처리 결과를 메일 발송하는 시스템
# 한 번에 한 명 신고, 횟수 제한 X (서로 다른 유저)
# k번 이상 신고 시 정지 -> 신고한 유저들에게 메일 발송 (한꺼번에)

# id_list: 유저 아이디 목록 배열
# report: "이용자id 신고id" 문자열 배열

# 각 유저가 받은 결과 메일 수 순서대로 담은 배열 구하기


def solution(id_list, report, k):
    answer = [0] * len(id_list)

    # 신고당한 횟수 저장
    report_cnt = {x:0 for x in id_list}
    for i in set(report): # 한 사람이 같은 유저 여러 번 신고 시 한 번만 처리
        report_cnt[i.split()[1]] += 1
    for i in set(report):
        if report_cnt[i.split()[1]] >= k: #신고횟수 k번 이상인 원소가 있다면
            answer[id_list.index(i.split()[0])] += 1 # 메일 수 갱신

    return answer