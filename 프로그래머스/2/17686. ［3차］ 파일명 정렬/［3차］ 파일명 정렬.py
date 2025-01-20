import re
def solution(files):
    answer = []
    # 정규식에 맞춰 숫자를 기준으로 나열
    tmp = [ re.split(r"([0-9]+)", s) for s in files ]
    # print(tmp)
    # img12.png -> img, 12, .png 이런식으로

    # 문제에 맞게 정렬
    sort = sorted(tmp, key = lambda x: (x[0].lower(), int(x[1])))

    # 문자열로 바꿔서 출력
    answer = ["".join(s) for s in sort]

    return answer