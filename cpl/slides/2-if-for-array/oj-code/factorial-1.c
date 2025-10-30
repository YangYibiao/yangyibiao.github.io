#include <stdio.h>

int main()
{
  long long n;
  scanf("%lld", &n);

  long long last_mod = 0;
  long long fact_mod = 1;
  for (long long i = 1; i <= n; i++) {
    fact_mod = (fact_mod * i) % 10007;
    last_mod = (last_mod + fact_mod);
  }
  last_mod %= 10007;
  printf("%lld", last_mod);
  return 0;
}
