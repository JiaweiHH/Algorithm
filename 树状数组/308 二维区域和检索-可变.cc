#include <vector>
using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>> &matrix)
      : matrix_(matrix), tree(matrix.size(), matrix[0].size()) {
    for (int i = 0; i < tree.m; ++i) {
      for (int j = 0; j < tree.n; ++j) {
        tree.update(i + 1, j + 1, matrix[i][j]);
      }
    }
  }

  void update(int row, int col, int val) {
    tree.update(row + 1, col + 1, val - matrix_[row][col]);
    matrix_[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return tree.query(row1 + 1, col1 + 1, row2 + 1, col2 + 1);
  }

private:
  struct binaryIndexedTree {
    vector<vector<int>> tree;
    int m, n;
    binaryIndexedTree(int m, int n) : m(m), n(n) {
      tree.resize(m + 1, vector<int>(n + 1));
    }
    int low_bit(int x) { return x & -x; }
    int query(int r, int c) {
      int res = 0;
      for (int i = r; i > 0; i -= low_bit(i)) {
        for (int j = c; j > 0; j -= low_bit(j)) {
          res += tree[i][j];
        }
      }
      return res;
    }
    int query(int r1, int c1, int r2, int c2) {
      return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) +
             query(r1 - 1, c1 - 1);
    }
    void update(int r, int c, int val) {
      for (int i = r; i <= m; i += low_bit(i)) {
        for (int j = c; j <= n; j += low_bit(j)) {
          tree[i][j] += val;
        }
      }
    }
  };

  binaryIndexedTree tree;
  vector<vector<int>> matrix_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */