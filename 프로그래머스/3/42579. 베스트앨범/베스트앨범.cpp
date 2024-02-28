#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compareSum(pair<int, string>& a, pair<int, string>& b) {
    return a.first > b.first;
}

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genreCate;
    vector<pair<int, string>> sum;
    vector<vector<pair<int, int>>> index;
    int len = genres.size();
    int count = 0;
    for (int i = 0; i <len;i++) {
        if (genreCate.find(genres[i]) != genreCate.end()) {
            sum[genreCate[genres[i]]].first+=plays[i];
            index[genreCate[genres[i]]].push_back(make_pair(plays[i],i));
        }
        else {
            genreCate.insert({ genres[i],count});
            sum.push_back(make_pair(plays[i],genres[i]));
            index.push_back(vector<pair<int, int>>()); // 벡터 크기를 늘립니다.
            index[count].push_back(make_pair(plays[i], i));
            count++;
        }
    }
    sort(sum.begin(), sum.end(), compareSum);
    for (int i = 0; i < index.size();i++) {
        sort(index[i].begin(), index[i].end(), compare);
    }
    for (int i = 0; i < sum.size();i++) {
        if (index[genreCate[sum[i].second]].size()>= 2) {
            for (int j = 0; j < 2; j++) {
                answer.push_back(index[genreCate[sum[i].second]][j].second);
            }
        }
        else {
            answer.push_back(index[genreCate[sum[i].second]][0].second);

        }
    }
    return answer;
}

