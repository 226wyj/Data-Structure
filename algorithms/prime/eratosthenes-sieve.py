from typing import List


# 埃氏筛, 对于给定的 n，找出所有小于等于 n 的质数
def sieve(n: int) -> List[int]:
    # T: O(nlog(logn))
    # S: O(n)
    is_prime = [True] * (n + 1)
    is_prime[0], is_prime[1] = False, False

    for i in range(2, int(n ** 0.5) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
    
    return [x for x in range(2, n + 1) if is_prime[x]]


if __name__ == '__main__':
    prime_within_20 = sieve(20)
    print(prime_within_20)
    assert prime_within_20 == [2, 3, 5, 7, 11, 13, 17, 19]