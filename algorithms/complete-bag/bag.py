# weight[m]: 第 i 个物品的重量为 weight[i]
# value[m]: 第 i 个物品的重量为 value[i]

# 给定一个容量为 W 的背包，对于 m 件商品，每件商品的数量无限多，
# 背包中可以重复装入同一件商品，问能装进商品的最大价值是多少

from typing import List

def bag(weight: List[int], value: List[int], W: int) -> int:
    assert len(weight) == len(value)

    dp = [0 for _ in range(W + 1)]

    for i in range(len(weight)):
        for j in range(weight[i], W + 1):
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
    return dp[W]

if __name__ == '__main__':
    weight = [1, 3, 4]
    value = [15, 20, 20]
    W = 4
    print(bag(weight, value, W)) # 结果为60