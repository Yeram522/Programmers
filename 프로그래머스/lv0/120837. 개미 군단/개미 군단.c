#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int hp) {
    int answer = 0;
    int rHp = hp;
    if(hp >= 5)
    {
        rHp = hp % 5;
        answer += ( hp / 5 );
        hp = rHp; 
    }
    if(hp >= 3)
    {
        rHp = hp % 3;
        answer += ( hp / 3 );
        hp = rHp; 
    }
    answer += hp;
    return answer;
}