# 붕대 감기

# t초 동안 감으면서 체력 x 회복 + t초 연속 감기 성공하면 y만큼 추가 회복
# 기술 중 공격 당하면 기술 취소, 공격 당하는 중 체력 회복 X
# 기술 취소/종료 시 바로 붕대 감기 사용 + 연속 성공 시간 0
# 체력 0 이하 되면 캐릭터 죽음
#bandage [시전 시간, 초당 회복량, 추가 회복량]
#health: 최대 체력
#attacks: [[공격 시간, 피해량], [...]]
# 모든 공격이 끝난 직후 남은 체력 구하기

def solution(bandage, health, attacks):

    # dic_attacks = {공격 시간: 피해량} 딕셔너리 저장
    dic_attacks = {}
    for attack in attacks:
        dic_attacks[attack[0]] = attack[1]

    max_health = health
    max_time = attacks[-1][0] # 마지막 공격 시간으로 저장

    t = 0 # 시간 카운트 t초
    continue_t = 0 # 연속 성공 시간 카운트

    while t <= max_time:
        if t in dic_attacks: # 해당 시간에 공격이 존재한다면
            health -= dic_attacks[t] # 최대 체력에서 해당 시간에 피해량 빼기
            continue_t = 0 # 연속 성공 시간 0으로 초기화 (공격 당하는 중 체력 회복 X)
            if health <= 0: # 체력 0 이하이면 캐릭터 죽음
                return -1
        else: # 공격이 없으면 붕대 감기 가능
            continue_t += 1
            if continue_t < bandage[0]: # 연속 성공 시간이 시전 시간보다 작으면
                health += bandage[1] # 초당 회복량만큼 회복
                if health > max_health: # 최대 체력 보정
                    health = max_health
            else:
                health = health + bandage[1] + bandage[2]
                if health > max_health:
                    health = max_health
                continue_t = 0 # 초기화
        t += 1
    return health

