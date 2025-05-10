import re
def solution(new_id):
    answer = ''
    
    # 1단계
    new_id = new_id.lower() # 소문자로 치환하는 string 내장 함수
    
    # 2단계
    for word in new_id:
        if word.islower() or word.isdigit() or word == '-' or word == '.' or word == '_':
            answer += word
        
    # 3단계
    answer = re.sub(r'\.+', '.', answer)
    
    # 4단계
    answer = answer.strip('.')
        
    # 5단계
    if answer == "":
        answer = "a"
        
    # 6단계
    if len(answer) >= 16:
        answer = answer[:15]
        answer = answer.rstrip(".")
            
    # 7단계
    while len(answer) <= 2:
        answer += answer[-1]
            
    
    return answer