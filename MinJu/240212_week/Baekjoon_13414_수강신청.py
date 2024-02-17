# 수강신청

import sys
input = sys.stdin.readline

k, l = map(int, input().split()) # 수강 가능 인원, 대기 목록 길이

# 신청자 대기목록 딕셔너리 저장 {학번: 순서}
dic = {}
for i in range(l):
    dic[input().strip()] = i

# 대기 순서에 따라 정렬 후 수강 가능 인원만큼 순서대로 출력
for i in sorted(dic, key=lambda x: dic[x])[:k]:
    print(i)
