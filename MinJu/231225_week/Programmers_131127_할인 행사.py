# 할인은 하루에 한 개
# 10개 품목 모두 할인가로 구입 가능한 회원 등록 날짜 총 일수
# 회원은 10일간 유지

# 시작 번호부터 10일 간 할인 품목을 조회하여
# 원하는 품목 구입 가능하면 해당 품목 값 -1

def solution(want, number, discount):
    answer = 0
    arr = []

    # 구매할는 물품 목록 개수까지 포함
    for i in range(len(want)):
        for j in range(number[i]):
            arr.append(want[i])
    arr.sort()

    for i in range(len(discount) - 9):
        ten_discount = discount[i: i + 10] # 할인 품목 시작 지점부터 10개 끊어서
        ten_discount.sort() # 정렬
        if arr == ten_discount: # 사려는 품목과 같으면 모두 할인이 되므로 조건 충족
            answer += 1
    return answer