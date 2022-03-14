#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<pair<string, int>> count_dic;
    vector<string> stop_id;
    //유저별 신고당한 횟수 정리.id_list 순서대로 muzi frodo apeach neo
    for (auto id: id_list)
    {
        count_dic.push_back(make_pair(id, 0));
    }

    //report읽어서 해당사람에 countUp
    for (auto target : report)
    {
        string id = target.substr(target.find(" ")+1);
        for (auto& member : count_dic)
        {
            if (member.first == id)  member.second++;
           
        }
        
    }

    //debug
    for (auto list : count_dic)
    {
        printf("%s : %d\n", list.first.c_str(), list.second);
    }

    //k이상 신고당한 사람.
    for (auto& list : count_dic)
    {
        if (list.second >= k) stop_id.push_back(list.first);
        list.second = 0;
    }

    //레포트 읽기
    for (auto target : report)
    {
        string reporter = target.substr(target.find(" ") + 1);//신고한 사람
        string t_user = target.substr(0,target.find(" ") -1);//고발당한 사람
        
        for (auto& member : count_dic)
        {
            if(find(stop_id.begin(), stop_id.end(), t_user) == stop_id.end()) continue;
            //해당 되ㅏㄴ다면
            member.second++;
        }

    }
    return answer;
}

int main()
{
    solution({ "muzi", "frodo", "apeach", "neo" }, { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" }, 2);
}