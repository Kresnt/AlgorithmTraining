# LeetCode 第 183 场周赛

5376. 非递增顺序的最小子序列

降序排列后，往 `vector<int>ans` 中添加元素，直到其和超过所有元素和的一半。

![](./5376.minimum-subsequence-in-non-increasing-order.ac.cpp)

5377. 将二进制表示减到 1 的步骤数

注意有500位，暴力模拟即可。

![](./5377.number-of-steps-to-reduce-a-number-in-binary-representation-to-one.ac.cpp)

5195. 最长快乐字符串

优先加剩余数目多的，能加则加，不能则选次多的，直到不能再加。

![](./5195.longest-happy-string.ac.cpp)

5379. 石子游戏 III
`dp[i]` 表示从 i 开始先手的最优情况，`dp[i].first` 是先手的值，`dp[i].second` 是后手的值。
**从后往前以先手最佳策略推**。
当前选手的最佳结果等于所有可能取法中(取1、2 还是 3 个)的最佳结果，假定取的是 i 到 j ，那么就依赖 d[j+1] 的状态（先后手交换）。

![](./5379.stone-game-iii.ac.cpp)