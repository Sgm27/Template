#include <iostream>
#include <vector>

using namespace std;

pair<int, int> findMaxSubmatrix(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    vector<vector<int>> prefixSum(n, vector<int>(n, 0));

    // Tính toán prefix sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prefixSum[i][j] = matrix[i][j];
            if (i > 0) {
                prefixSum[i][j] += prefixSum[i - 1][j];
            }
            if (j > 0) {
                prefixSum[i][j] += prefixSum[i][j - 1];
            }
            if (i > 0 && j > 0) {
                prefixSum[i][j] -= prefixSum[i - 1][j - 1];
            }
        }
    }

    int maxSum = 0;
    pair<int, int> maxSubmatrix;

    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= n - k; j++) {
            int submatrixSum = prefixSum[i + k - 1][j + k - 1];
            if (i > 0) {
                submatrixSum -= prefixSum[i - 1][j + k - 1];
            }
            if (j > 0) {
                submatrixSum -= prefixSum[i + k - 1][j - 1];
            }
            if (i > 0 && j > 0) {
                submatrixSum += prefixSum[i - 1][j - 1];
            }

            if (submatrixSum > maxSum) {
                maxSum = submatrixSum;
                maxSubmatrix = make_pair(i, j);
            }
        }
    }

    return maxSubmatrix;
}

int main() {
    vector<vector<int>> matrix = {{1, 200, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    int k = 2;

    pair<int, int> result = findMaxSubmatrix(matrix, k);
    cout << "Max submatrix starts at row " << result.first << ", column " << result.second << endl;

    return 0;
}
