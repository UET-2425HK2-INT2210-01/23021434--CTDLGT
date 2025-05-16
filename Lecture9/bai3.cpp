#include <iostream>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;

    int* weight = new int[n];
    int* value = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    int* dp = new int[X + 1];
    for (int i = 0; i <= X; i++) dp[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = X; j >= weight[i]; j--) {
            int take = dp[j - weight[i]] + value[i];
            if (take > dp[j]) dp[j] = take;
        }
    }

    cout << dp[X] << endl;

    delete[] weight;
    delete[] value;
    delete[] dp;
    return 0;
}
