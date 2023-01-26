#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    
    vector<int> sortemerge = emergency;
    sort(sortemerge.rbegin(),sortemerge.rend());
    
    for(auto emr : emergency)
    {
        int order = find(sortemerge.begin(),sortemerge.end(),emr)  - sortemerge.begin();
        answer.push_back(order+1);
    }
    return answer;
}