#include <bits/stdc++.h>
using namespace std;

// Iterative binary search on sorted ascending vector.
// Returns index of target, or -1 if not found.
int binarySearchIter(const vector<int>& a, int target) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2; // avoids overflow
        if (a[mid] == target) return mid;
        if (a[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int target; cin >> target;

    // ensure 'a' is sorted; if input guaranteed sorted, you can skip this
    sort(a.begin(), a.end());

    int idx = binarySearchIter(a, target);
    if (idx == -1) cout << "Not found\n";
    else cout << "Found at index: " << idx << "\n";
    return 0;
}
