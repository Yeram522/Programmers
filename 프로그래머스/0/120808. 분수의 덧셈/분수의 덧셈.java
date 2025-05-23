class Solution {
    public static int gcd(int a, int b) {
            if (b == 0) return a;
            return gcd(b, a % b);
    }
    
    public int[] solution(int numer1, int denom1, int numer2, int denom2) {
        int[] answer = new int[2];
        int a = numer1*denom2 + numer2 * denom1;//분자
        int b = denom1*denom2; // 분모
            
        
        int gcd = gcd(a,b);
        
        answer[0] = (int)a/gcd;
        answer[1] = (int)b/gcd;
        
        
        return answer;
    }
}