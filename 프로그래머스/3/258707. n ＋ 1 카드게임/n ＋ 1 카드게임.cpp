#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool findCard(vector<int>& cards, int sum)
{
    for(int i = 0; i < cards.size(); i++)
    {
        for(int j = i + 1; j < cards.size(); j++)
        {
            if(cards[i] + cards[j] == sum)
            {
                // 뒤에 인덱스부터 지워야 한다.
                // 앞에서부터 지우면 뒤에 인덱스를 지울 때 잘못된 메모리에 접근하게 된다.
                cards.erase(cards.begin() + j);
                cards.erase(cards.begin() + i);
                return true;
            }
        }
    }
    
    return false;   
}

bool addOneCardFromCandidates(vector<int>& myCards, vector<int>& candidates, int sum)
{
     for(int i = 0; i < myCards.size(); i++)
    {
        for(int j = 0; j < candidates.size(); j++)
        {
            if(myCards[i] + candidates[j] == sum)
            {
                myCards.erase(myCards.begin() + i);
                candidates.erase(candidates.begin() + j);
                return true;
            }
        }
    }
    
    return false;   
}

int solution(int coin, vector<int> cards) {

    vector<int> myCards = vector(cards.begin(), cards.begin() + cards.size()/3);
    vector<int> candidates;
    int candidateIdx = cards.size()/3;
    
    // 1라운드는 가고 시작
    int round = 1;
    int sum = cards.size() + 1;
   
    while(myCards.size() > 0)
    {
        // 후보군에 넣어주는 작업
        if(candidateIdx < cards.size())
        {
          candidates.push_back(cards[candidateIdx]);
          candidates.push_back(cards[candidateIdx + 1]);
          candidateIdx += 2;   
        }
        
        // 내가 갖고 있는 카드로 낼 수 있는 지 확인한다.
        if(findCard(myCards, sum))
        {
            round++;
            continue;
        }
        
        // 후보군에서 하나와 내 카드로 낼 수 있는 지 확인한다.
        if(coin > 0 && addOneCardFromCandidates(myCards, candidates, sum))
        {
            round++;
            coin--;
            continue;
        }
        
        // 후보군 카드들로 낼 수 있는지 확인한다.
        if(coin > 1 && findCard(candidates, sum))
        {
            round++;
            coin -= 2;
            continue;
        }
        
        // 세가지 방법으로 다 안되면 더 이상 진행 불가능하다.
        break;
    }
    
    return round;
}
