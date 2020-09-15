    #include < bits / stdc++.h > 
    #define ll long long# define N 1000000
    using namespace std;
    vector < ll > primes;
    int lp1[N + 1];
    void seive() {
      for (ll i = 2; i * i <= N; i++) {
        if (lp1[i] == 0) {
          for (ll j = i * i; j <= N; j += i) {
            if (lp1[j] == 0)
              lp1[j] = i;
          }
        }
      }
      for (int i = 2; i <= N; i++) {
        if (lp1[i] == 0) {
          primes.push_back(i);
        }
      }
    }
    ll a[100005], b[100005];
    int main() {
      int t;
      cin >> t;
      seive();
      while (t--) {
        ll l, r, k, c = 0;
        cin >> l >> r >> k;
        if (r <= N) {
          for (int i = l; i <= r; i++) {
            int tmp = i, etf = i;
            while (tmp != 1) {
              int p = (lp1[tmp] == 0) ? tmp : lp1[tmp];
              while (tmp % p == 0)
                tmp /= p;
              etf -= etf / p;
            }
            if (etf % k == 0) c++;
          }
        } else {
          for (ll i = l; i <= r; i++) {
            a[i - l] = i;
            b[i - l] = i;
          }
          for (int j = 0; j < (int) primes.size(); j++) {
            ll least = (l / primes[j]) * primes[j];
            if (least < l) least += primes[j];
            for (ll i = least; i <= r; i += primes[j]) {
              a[i - l] /= primes[j];
              a[i - l] *= (primes[j] - 1);
              while (b[i - l] % primes[j] == 0)
                b[i - l] /= primes[j];
            }
          }
          for (ll i = l; i <= r; i++) {
            if (a[i - l] == i) {
              if ((a[i - l] - 1) % k == 0) {
                c++;
                continue;
              }
            } else if (b[i - l] != 1) {
              a[i - l] /= b[i - l];
              a[i - l] *= (b[i - l] - 1);
            }
            if (a[i - l] % k == 0) c++;
          }
        }
        cout << fixed << setprecision(6) << (c / (r - l + 1.0)) << "\n";
      }
    }