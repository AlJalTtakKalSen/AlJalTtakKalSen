# 로또의 최고 순위와 최저 순위

# 6개 번호 모두 맞으면 1등 65432 2개 맞으면 5등 그 이외는 낮첨
# 알아볼 수 없는 번호 0 -> 최고, 최저 순위
def solution(lottos, win_nums):
    answer = []
    rank = [6, 6, 5, 4, 3, 2, 1] # 가능한 순위
    num = lottos.count(0)
    cnt = 0
    for i in win_nums:
        if i in lottos:
            cnt += 1
    # 최고 순위는 모르는 숫자도 모두 맞춘 것
    answer.append(rank[num+cnt])
    # 최저 순위는 모르는 숫자는 모두 못찾운 것
    answer.append(rank[cnt])
    return answer