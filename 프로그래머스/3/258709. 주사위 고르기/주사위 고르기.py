from itertools import combinations, product
from bisect import bisect_left

def solution(dice):
    n = len(dice)
    half = n // 2

    best_win_count = -1
    best_combination = None

    # 특정 주사위 조합으로 만들 수 있는 모든 합 구하기
    def make_sums(indices):
        result = []

        # indices에 해당하는 주사위들의 모든 면 조합 생성
        for faces in product(*[dice[i] for i in indices]):
            result.append(sum(faces))

        return result

    # A가 고를 수 있는 모든 주사위 조합 확인
    for a_indices in combinations(range(n), half):
        a_set = set(a_indices)

        # B는 A가 고르지 않은 나머지 주사위
        b_indices = []
        for i in range(n):
            if i not in a_set:
                b_indices.append(i)

        # A와 B가 만들 수 있는 모든 합
        a_sums = make_sums(a_indices)
        b_sums = make_sums(b_indices)

        # B의 합을 정렬해두면 이분 탐색 가능
        b_sums.sort()

        win_count = 0

        # A의 각 합마다, 그보다 작은 B의 합 개수를 센다
        for a_sum in a_sums:
            win_count += bisect_left(b_sums, a_sum)

        # 승리 횟수가 가장 큰 조합 갱신
        if win_count > best_win_count:
            best_win_count = win_count
            best_combination = a_indices

    # 문제의 주사위 번호는 1번부터 시작하므로 +1
    answer = []
    for i in best_combination:
        answer.append(i + 1)

    return answer