// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int A;
    int B;
    int C;
    int timeToFrom[3][2];
    int timetable[100] = {0,};
    int total = 0;
    //input 주차요금 A,B,C
    scanf("%d %d %d", &A, &B, &C);
    
    //input 차량 입차, 출차 시간
    for(int i = 0 ; i < 3 ; i++)
    {
        scanf("%d %d", &timeToFrom[i][0],  &timeToFrom[i][1]);
    }
    
    // 무식하게 풀 수 있다면 무식하게 풀어보기.
    // 범위가 얼마 안되기 때문에 for문을 사용해도 괜찮다. 어차피 O(n)
    // 1. Time Table에 차가 몇대 머물렀는지 증감하여 기록
    for(int i = 0; i < 3 ; i ++)
    {
        for(int j = timeToFrom[i][0]; j < timeToFrom[i][1]; j++)
        {
            timetable[j] ++;
        }
    }
    
    //2. 주차요금 계산 
    for(int i = 0; i < 100; i++)
    {
        switch(timetable[i])
        {
        case 0 :
            break;
        case 1 :
            total += A;
            break;
        case 2 :
            total += (B*2);
            break;
        case 3 :
            total += (C*3);
            break;
        default:
            break;
        }
    }
    
    cout << total << endl;
    return 0;
}