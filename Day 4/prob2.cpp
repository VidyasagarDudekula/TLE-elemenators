#include <bits/stdc++.h>
void smallest_subarray(std::vector<long long int> &a, int n, long long int p,
                       int &start_index, int &count) {
  int start = 0, end = 0, temp_count = 0;
  long long int sum = 0;
  int ans = INT_MAX;
  while (end < a.size()) {
    sum += a[end];
    while (sum >= p && start <= end) {
      if (end - start + 1 < ans) {
        start_index = start % n;
        temp_count = end - start + 1;
        ans = end - start + 1;
      }
      sum -= a[start];
      start++;
    }
    end++;
  }
  count += temp_count;
}
int main() {
  int n;
  long long int p;
  std::cin >> n >> p;
  std::vector<long long int> a(n, 0);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  long long int sum = 0;
  sum = std::accumulate(a.begin(), a.end(), sum);
  // std::cout << "sum:= " << sum << "\n";
  int start_index = -1, count = 0;
  if (p >= sum) {
    count += (p / sum) * n;
    p = p % sum;
  }
  for (int i = 0; i < n - 1; i++)
    a.push_back(a[i]);
  smallest_subarray(a, n, p, start_index, count);
  std::cout << start_index + 1 << " " << count << "\n";
}
