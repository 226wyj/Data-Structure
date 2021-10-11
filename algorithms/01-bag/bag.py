# weight[m]: 第 i 个物品的重量为 weight[i]
# value[m]: 第 i 个物品的重量为 value[i]

# 给定一个容量为 W 的背包，对于 m 件商品，要求每件商品
# 最多只能被装一次，问能装进商品的最大价值是多少

from typing import List

def bag(weight: List[int], value: List[int], W: int) -> int:
    assert len(weight) == len(value)

    item_num = len(weight)
    # dp[i][j] 代表在背包剩余容量为 j 的情况下装前 i 件物品能获得的最大价值
    dp = [[0 for _ in range(W + 1)] for _ in range(item_num)]
    
    # 初始化
    # 当背包容量为 0 时，无法装入物品，因此最大价值为 0
    for i in range(item_num):
        dp[i][0] = 0
    
    # 存放编号为0的物品时，容量为 j 的物品所能获得的最大价值
    # 这里一定要倒序初始化，否则会出现重复装入的情况，与题意不符
    j = W
    while weight[0] <= j:
        dp[0][j] = dp[0][j - 1] + value[0]
        j -= weight[0]
    
    # dynamic programming
    # 对于每件商品，首先需要比较其重量与背包剩余重量
    # 如果商品可以装入背包，那么有两个选择：装和不装
    # 如果装入背包，则可以获得的价值为dp[i - 1][j - weight[i]] + value[i]
    # 不装，则获得的价值与 i - 1 时一样，为dp[i - 1][j]
    # 需要取二者中较大的一个作为结果
    # 如果商品无法装入背包，则只有一个选择，就是与 i - 1 时一样，为dp[i - 1][j]
    for i in range(1, item_num):
        for j in range(W + 1):
            if weight[i] <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
            else:
                dp[i][j] = dp[i - 1][j]
    print(dp)
    return dp[-1][-1]

if __name__ == "__main__":
    weight = [1, 3, 4]
    value = [15, 20, 20]
    W = 4

    # dp 矩阵：
    # [
    #   [0, 15, 15, 15, 15],
    #   [0, 15, 15, 20, 35],
    #   [0, 15, 15, 20, 35]
    # ]
    print(bag(weight, value, W)) # 结果为35