// 더 짧은 풀이 ( 개발과 코딩테스트가 다른 이유 : 시간 내에 더 짧고 명확하게 푸는것이 중요)
#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,t;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> t; // 여기서는 cin 버퍼에서 한 번에 값을 가져온다
        if(t < m) {
            cout << t << " ";  // 여기서는 cout 버퍼에 한 번에 담아두고 출력을 한다
        }
    }

    cout << "\n";
    return 0;
}
