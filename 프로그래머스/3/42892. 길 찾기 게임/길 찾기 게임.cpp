#include <string>
#include <vector>
#include <algorithm>
#include<map>
#include <iostream>
using namespace std;

map<int, int> indexX;

void treefront(vector<vector<int>>& nodeinfo, vector<int>& answer) {
    if (nodeinfo.size()<=1) {
        answer.push_back(indexX[nodeinfo[0][0]]);
        return;
    }
    else {
        int maxi = 0;
        int root = 0;
        vector<vector<int>> front;
        vector<vector<int>> back;
        for (int i = 0;i < nodeinfo.size();i++) {
            if (maxi < nodeinfo[i][1]) {
                maxi = nodeinfo[i][1];
                root = i;
            }
        }
        cout << root;
        for (int i = 0; i < nodeinfo.size();i++) {
            if (nodeinfo[i][0] < nodeinfo[root][0]) {
                front.push_back(nodeinfo[i]);
            }
            else if(i!=root){
                back.push_back(nodeinfo[i]);
            }
        }
        answer.push_back(indexX[nodeinfo[root][0]]);
        if (front.size()!=0) {
            treefront(front, answer);
        }

        if (back.size()!=0) {
            treefront(back, answer);
        }
    }
}

void treeback(vector<vector<int>>& nodeinfo, vector<int>& answer) {
    if (nodeinfo.size() <= 1) {
        answer.push_back(indexX[nodeinfo[0][0]]);
        return;
    }
    else {
        int maxi = 0;
        int root = 0;
        vector<vector<int>> front;
        vector<vector<int>> back;
        for (int i = 0;i < nodeinfo.size();i++) {
            if (maxi < nodeinfo[i][1]) {
                maxi = nodeinfo[i][1];
                root = i;
            }
        }
        cout << root;
        for (int i = 0; i < nodeinfo.size();i++) {
            if (nodeinfo[i][0] < nodeinfo[root][0]) {
                front.push_back(nodeinfo[i]);
            }
            else if (i != root) {
                back.push_back(nodeinfo[i]);
            }
        }
        if (front.size() != 0) {
            treeback(front, answer);
        }

        if (back.size() != 0) {
            treeback(back, answer);
        }
        answer.push_back(indexX[nodeinfo[root][0]]);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    vector<vector<int>> answer;
    vector<int> answerfront;
    vector<int> answerback;

    for (int i = 0;i < nodeinfo.size();i++) {
        indexX[nodeinfo[i][0]] = (i+1);
    }
  
    treefront(nodeinfo, answerfront);
    treeback(nodeinfo, answerback);
  /*
    for (int i = 0; i < answerfront.size();i++) {
        cout << answerfront[i] << ",";
    }
    cout << endl;
    for (int i = 0; i < answerback.size();i++) {
        cout << answerback[i] << ",";
    } */

    answer.push_back(answerfront);
    answer.push_back(answerback);

    return answer;
}