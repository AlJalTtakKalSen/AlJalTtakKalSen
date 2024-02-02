# 후보 추천하기

n = int(input())
recommend = int(input())
students = list(map(int, input().split()))

pictures = []
result = []

for i in range(recommend):
    if students[i] in pictures: # 추천 학생이 사진틀에 존재하면
        for j in range(len(pictures)):
            if students[i] == pictures[j]:
                result[j] += 1 # 추천 수 증가
    else: # 추천 학생이 사진틀에 존재하지 않으면
        if len(pictures) >= n: # 사진틀이 꽉 찼다면
            for j in range(n):
                if result[j] == min(result): # 가장 작은 추천수 제거
                    del pictures[j]
                    del result[j]
                    break
        pictures.append(students[i]) # 사진틀에 새로운 학생 추가
        result.append(1)
pictures.sort()
print(*pictures)