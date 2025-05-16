#include <iostream>
using namespace std;

bool found = false;
//backtracking
void findSubset(int arr[], int n, int index, int currentSum, int target) {
    if (currentSum == target) {
        found = true;
        return;
    }
    if (index == n || currentSum > target || found) return;

    // Chọn phần tử hiện tại
    findSubset(arr, n, index + 1, currentSum + arr[index], target);

    // Bỏ qua phần tử hiện tại
    findSubset(arr, n, index + 1, currentSum, target);
}

int main() {
    int n, X;
    cin >> n >> X;

    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    findSubset(A, n, 0, 0, X);

    if (found) cout << "YES" << endl;
    else cout << "NO" << endl;

    delete[] A;
    return 0;
}
