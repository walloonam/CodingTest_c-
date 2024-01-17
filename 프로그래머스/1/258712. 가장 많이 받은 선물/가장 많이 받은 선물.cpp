#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    map<string, int> giftCount; // 각 친구의 선물 지수를 저장하는 맵
    map<pair<string, string>, int> giftshape;
    map<string, int> result;

    for (const string& fromfriends : friends) {
        result[fromfriends] = 0;
        giftCount[fromfriends] = 0;
        for (const string& tofriends : friends) {
            if (fromfriends != tofriends)
                giftshape[{fromfriends, tofriends}] = 0;
        }
    }

    for (const string& gift : gifts) {
        // 띄어쓰기를 기준으로 나누기
        size_t pos = gift.find(' ');
        string firstPart = gift.substr(0, pos);
        string secondPart = gift.substr(pos + 1);

        // 나눈 부분 출력
        // 각 친구의 선물 지수 갱신
        giftshape[{firstPart, secondPart}] ++;
        giftshape[{secondPart, firstPart}]--;


        giftCount[firstPart]++;
        giftCount[secondPart]--;
    }




    for (const auto& entry : giftshape) {
        if (entry.second > 0) {
            result[entry.first.first]++;
        }
        else if (entry.second == 0) {
            if (giftCount[entry.first.first]>giftCount[entry.first.second]) {
                result[entry.first.first]++;
            }
        }
    }



    vector<pair<string, int>> result2(result.begin(), result.end());
    sort(result2.begin(), result2.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
        });

    return result2.begin()->second;
}