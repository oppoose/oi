好的，我已经阅读了你当前页面的内容，下面我帮你把这一页关于 堆（Heap） 的知识点总结成一份清晰的 Markdown 笔记，方便你整理到学习文档里。

# 堆（Heap）与优先队列总结

## 1. 堆的基本概念
- 堆是一种 **完全二叉树**，常用于实现优先队列。
- 特性：
  - **小根堆**：任意父节点 ≤ 子节点，堆顶元素是最小值。
  - **大根堆**：任意父节点 ≥ 子节点，堆顶元素是最大值。
- 常见用途：快速获取最小值或最大值，复杂度 O(log n)。

---

## 2. 数组存储堆的结构
堆通常用数组存储，利用完全二叉树的性质：
- 父节点索引：`parent = i / 2`
- 左孩子索引：`left = i * 2`
- 右孩子索引：`right = i * 2 + 1`

示例（完全二叉树编号）：

    1
  /   \
 2     3
/ \   / \

4  5  6  7

数组存储：`[n1, n2, n3, n4, n5, n6, n7]`

---

## 3. 堆的基本操作

### push(x) 插入元素
1. 将元素放到堆底（数组末尾）。
2. 与父节点比较，如果更小（小根堆），则交换。
3. 不断向上调整（**sift up**），直到满足堆性质。

```c
void push(ll x) {
    int i = ++heapSize;
    heap[i] = x;
    while (i > 1 && heap[i] < heap[i / 2]) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}
```
pop() 删除堆顶元素

堆顶元素（最小值）取出。

用最后一个元素补到堆顶。

从堆顶开始向下比较，与更小的孩子交换。

不断向下调整（sift down），直到满足堆性质。
```c
ll pop() {
    ll ret = heap[1];              // 堆顶最小值
    heap[1] = heap[heapSize--];    // 用最后一个元素补位
    int i = 1;
    while (1) {
        int smallest = i;
        int l = i * 2, r = i * 2 + 1;
        if (l <= heapSize && heap[l] < heap[smallest]) smallest = l;
        if (r <= heapSize && heap[r] < heap[smallest]) smallest = r;
        if (smallest == i) break;
        swap(heap[i], heap[smallest]);
        i = smallest;
    }
    return ret;
}
```
4. 应用示例：喂猫问题

初始将所有猫的 DM 值放入小根堆。

每次取出最小 DM 值的猫，喂食后 DM 增加，再放回堆。

M 次喂食后，堆顶即为最小 DM 值。

逻辑：
```c
for (每只猫初始 DM) push(DM)
for (每次喂食) {
    x = pop();     // 取最弱的猫
    x += ai;       // 喂食后 DM 增加
    push(x);       // 放回堆
}
输出 pop() // 最小 DM
```
5. 堆的优势

每次插入/删除复杂度 O(log n)，比线性扫描 O(n) 更高效。

常用于：

优先队列

Dijkstra 最短路

A* 搜索

调度/模拟问题

6. 关键词

heap：堆

sift up：向上调整

sift down：向下调整

priority queue：优先队列

complete binary tree：完全二叉树

