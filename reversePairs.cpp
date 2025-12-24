class Solution {
public:
    void merge(vector<int>& a, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (a[left] <= a[right]) {
                temp.push_back(a[left++]);
            } else {
                temp.push_back(a[right++]);
            }
        }
        while (left <= mid) temp.push_back(a[left++]);
        while (right <= high) temp.push_back(a[right++]);

        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }
    }

    int countPairs(vector<int>& a, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)a[i] > 2LL * a[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& a, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;
        int cnt = 0;

        cnt += mergeSort(a, low, mid);
        cnt += mergeSort(a, mid + 1, high);
        cnt += countPairs(a, low, mid, high);
        merge(a, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
