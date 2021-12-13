#include <map>
#include <vector>

using namespace std;

// 给出两个数组，输出它们的交集

// 使用 map 保存第一个数组中出现的元素和它的次数之间的映射
// 然后遍历 nums2 判断是否存在这个元素，如果存在就保存到 res 中
// 时间复杂度 O(m + n)，空间复杂度 O(min(m, n))
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    map<int, int> m;
    for (const auto &v : nums1)
      m[v]++;
    for (const auto &v : nums2) {
      if (m.count(v)) {
        res.push_back(v);
        if (--m[v] == 0)
          m.erase(v);
      }
    }
    return res;
  }
};

// 如果数组本身就有序，可以使用双指针
class Solution_1 {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int index1 = 0, index2 = 0;
    while (index1 != nums1.size() && index2 != nums2.size()) {
      if (nums1[index1] < nums2[index2])
        index1++;
      else if (nums1[index1] > nums2[index2])
        index2++;
      else {
        res.push_back(nums1[index1]);
        index1++;
        index2++;
      }
    }
    return res;
  }
};

// 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
// 第一种更好，因为第二种涉及到排序时间复杂度时 O(mlogm)，而第一种只需要遍历一次 nums2，时间复杂度 O(m)

// 如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
// 内存很小的话，只能选择空间复杂度最小的算法，即第二种方法