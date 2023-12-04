def solution(numbers):
    numbers = list(map(str, numbers)) # 문자열 리스트로 
    # 3과 31 중 3이 앞에 와야 큰 수가 됨 -> 33 31 비교 
    # 입력되는 수 1000 이하, 사전순 비교 -> 문자열 3번 반복 비교 -> 3자릿수까지 사전 비교 가능 333 323232
    numbers.sort(key=lambda x:x*3, reverse=True) # 더 큰 숫자 문자열이 앞에 나오게 내림차순 
    return str(int(''.join(numbers))) # int로 바꾸고 str 변환 (00 경우 0으로 반환하기 위해)
