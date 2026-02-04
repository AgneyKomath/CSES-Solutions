# Answer can't be precise enough on C++ 😢
from fractions import Fraction

n = int(input())
a = list(map(int, input().split()))

res = Fraction(0, 1)

for i in range(n):
    curr = Fraction(0, 1)
    for j in range(1, a[i] + 1):
        for k in range(i + 1, n):
            if a[k] < j:
                curr += Fraction(1, 1)
            else:
                curr += Fraction(j - 1, a[k])
    res += Fraction(curr, a[i]);

res = float(round(res, 6))
print(f"{res:06f}")