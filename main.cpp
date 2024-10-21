#include <bits/stdc++.h>
#define sync ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define text "MAIN"
using namespace std;

void input()
{
    sync;
    freopen(text".inp", "r", stdin);
    freopen(text".out", "w", stdout);
}

int main()
{
    input();
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    int count1 = 0, count0 = 0;

    // Sử dụng một map để lưu trữ số lượng cặp
    unordered_map<int, int> countMap;

    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            count1++;
        } else {
            count0++;
        }

        // Nếu số lượng 1 và 0 bằng nhau, chúng ta có thể tạo ra một cặp
        if (count1 == count0) {
            res++;
        }

        // Lưu trữ số lượng 1 và 0 vào map
        countMap[count1 - count0]++;
    }

    // Đếm các cặp từ map
    for (const auto& pair : countMap) {
        int count = pair.second;
        // Nếu có count cách chọn, số cặp là count * (count - 1) / 2
        res += (count * (count - 1)) / 2;
    }

    cout << res;
    return 0;
}