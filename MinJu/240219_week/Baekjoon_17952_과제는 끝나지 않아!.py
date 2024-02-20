# 과제는 끝나지 않아!

import sys
input = sys.stdin.readline

n = int(input()) # 학기 총 분수
answer = 0 # 과제 점수
task = []

for i in range(n):
    info = list(map(int, input().split()))
    if info[0] == 1: # 과제가 주어진 경우
        task.append(info[1:]) # 과제 정보 저장

    if task: # 과제가 남아있는 경우
        task[-1][1] -= 1 # 과제 시간 감소
        if task[-1][1] == 0: # 과제 완료 (남은 시간 0)
            answer += task[-1][0] # 과제 점수 갱신
            task.pop() # 완료된 과제 제거
print(answer)
