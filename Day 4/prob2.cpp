#include <bits/stdc++.h>
long long int smallest_subarray(std::vector<long long int> &a, long long int n, long long int p,
                       long long int start_index, long long int &count) {
  long long int start = 0, end = 0, temp_count = 0;
  long long int sum = 0;
  long long int ans = INT_MAX;
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
  return start_index;
}
int main() {
  long long int n;
  long long int p;
  std::cin >> n >> p;
  std::vector<long long int> a(n, 0);
  for (long long int i = 0; i < n; i++)
    std::cin >> a[i];

  long long int sum = 0;
  sum = std::accumulate(a.begin(), a.end(), sum);
  // std::cout << "sum:= " << sum << "\n";
  long long int start_index = 0, count = 0;
  if (p >= sum) {
    count += (p / sum) * n;
    p = p - ((p/sum)*sum);
    start_index = 0;
  }
  if(p>0)
  {
    for (long long int i = 0; i < n - 1; i++)
    a.push_back(a[i]);
    long long int k = smallest_subarray(a, n, p, -1, count);
    start_index = k;
  }
  std::cout << start_index + 1 << " " << count << "\n";
}
