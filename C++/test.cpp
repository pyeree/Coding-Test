#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] < m) {
            cout << arr[i] << " ";
        }
    }

    cout << "\n";
    return 0;
}
