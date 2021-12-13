#include <utility>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/// @brief 将一个有序的链表转换为高度平衡的二叉搜索树

/// @brief 每次取链表的中间节点作为树根，递归构造左右子树即可
class Solution {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    TreeNode *root = toBtree(head);
    return root;
  }
  TreeNode *toBtree(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    // 获取链表中间节点
    auto res = findMid(head);
    ListNode *prev = res.first;
    ListNode *mid = res.second;
    ListNode *next = mid->next;
    // 断开前后半部链表
    if (prev)
      prev->next = nullptr;
    mid->next = nullptr;
    TreeNode *left = prev ? toBtree(head) : nullptr;
    TreeNode *right = toBtree(next);
    TreeNode *root = new TreeNode(mid->val);
    root->left = left;
    root->right = right;
    return root;
  }
  pair<ListNode *, ListNode *> findMid(ListNode *head) {
    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    return make_pair(prev, slow);
  }
};

/// @brief 同样的思路，只不过现在套用二分搜索的框架
class Solution_1 {
public:
  // 左闭右开
  ListNode *getMedian(ListNode *left, ListNode *right) {
    ListNode *fast = left;
    ListNode *slow = left;
    while (fast != right && fast->next != right) {
      fast = fast->next;
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }

  TreeNode *buildTree(ListNode *left, ListNode *right) {
    if (left == right) {
      return nullptr;
    }
    ListNode *mid = getMedian(left, right);
    TreeNode *root = new TreeNode(mid->val);
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
  }

  TreeNode *sortedListToBST(ListNode *head) { return buildTree(head, nullptr); }
};

/// @brief 分治 + 中序遍历
/// 这是由于构造出来的二叉搜索树中序遍历的结果就是链表本身
/// 上面的分治方法的时间复杂度为 O(nlogn)，这里的时间复杂度是 O(n)
class Solution_2 {
public:
  TreeNode *sortedListToBST(ListNode *head) {
    int len = getLength(head);
    return buildTree(head, 0, len - 1);
  }
  int getLength(ListNode *head) {
    int len = 0;
    for (; head != nullptr; head = head->next, ++len)
      ;
    return len;
  }
  // 中序遍历构造，每次构造完左子树，需要将 head 指针指向 next，因为 next 就是以 head 为根的树的右子树
  // 而当其中一次递归返回上层的时候，相当于在上层的 head 为根的树的左子树构造完成了
  // 由于 head 每次都是指向 next，所以返回上层的时候，head 刚好指向了该层的根结点
  TreeNode *buildTree(ListNode *&head, int left, int right) {
    if (left > right)
      return nullptr;
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode();
    // 该调用第一次结束的时候，返回的是 nullptr
    root->left = buildTree(head, left, mid - 1);
    // 设置根节点的值
    root->val = head->val;
    // head 指向右子树
    head = head->next;
    root->right = buildTree(head, mid + 1, right);
    return root;
  }
};