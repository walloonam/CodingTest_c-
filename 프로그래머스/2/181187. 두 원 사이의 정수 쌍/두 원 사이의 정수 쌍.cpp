#include <string>
#include <vector>
#include <iostream>
using namespace std;
long j1;
long j2;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r2_r = (long long)r2 * r2; // 오버플로우 방지를 위해 형변환
    long long r1_r = (long long)r1 * r1; // 오버플로우 방지를 위해 형변환
    j1=r1;
    j2=r2;
    long long r2_an=0;
    long long r1_an=0;
    for (long i = 1; i < r2; i++) {
        long j;
        for (j = j2; j * j + i * i > r2_r; j--) {
        }
        j2=j;
        r2_an += j;
    }

    for (long i = 1; i < r1; i++) {
        long j;
        for (j = j1; j * j + i * i >= r1_r; j--) {
        }
        j1=j;
        r1_an += j;
    }
    answer=(r2_an-r1_an +r2-r1+1)*4;
    
    // cout<<answer<<endl; // 기존에 출력하던 부분 주석 처리
    return answer;
}
