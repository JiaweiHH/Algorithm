class MountainArray {
public:
  int get(int index);
  int length();
};

class Solution {
public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int len = mountainArr.length();
    int l = 0, r = len - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int val_1 = mountainArr.get(mid);
      if (mid + 1 < len && mountainArr.get(mid + 1) > val_1)
        l = mid + 1;
      else
        r = mid - 1;
    }
    int index = l;
    int idx =
        binary_search(mountainArr, 0, index, target, [](int x) { return x; });
    if (idx != -1)
      return idx;
    idx = binary_search(mountainArr, index + 1, len - 1, target,
                        [](int x) { return -x; });
    return idx;
  }

  int binary_search(MountainArray &mountainArr, int l, int r, int target,
                    int lambda(int)) {
    target = lambda(target);
    while (l <= r) {
      int mid = (l + r) / 2;
      int val = lambda(mountainArr.get(mid));
      if (val < target)
        l = mid + 1;
      else if (val > target)
        r = mid - 1;
      else
        return mid;
    }
    return -1;
  }
};