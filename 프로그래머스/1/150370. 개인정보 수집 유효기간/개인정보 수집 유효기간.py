def solution(today, terms, privacies):
    answer = []

    # 약관별 유효기간 딕셔너리화
    d_terms = {}
    for term in terms:
        typ, num = term.split(" ")
        d_terms[typ] = int(num)

    for i, privacy in enumerate(privacies):
        date, typ = privacy.split(" ")
        y, m, d = map(int, date.split("."))

        # 기간 더하기
        m += d_terms[typ]

        # 월 수가 12 이상이면 연도로 넘김
        y += (m - 1) // 12
        m = (m - 1) % 12 + 1  # 1~12 범위 유지

        # 날짜 문자열로 포맷
        exp_date = f"{y:04d}.{m:02d}.{d:02d}"

        # today가 만료일보다 크거나 같으면 폐기 대상
        if today >= exp_date:
            answer.append(i + 1)  # 인덱스는 1-based로 반환

    return answer
