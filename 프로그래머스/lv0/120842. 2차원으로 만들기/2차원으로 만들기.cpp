#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    vector<vector<int>> answer;
    
    //num_list에서 n개씩 벡터를 묶어, answer에 push_back 한다.
    for (vector<int>::iterator iter = num_list.begin(); iter != num_list.end() ; iter += n)
	{
		vector<int> vec(iter, iter + n);
        answer.push_back(vec);
	}
    return answer;
}