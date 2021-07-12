# 链表

```mermaid
graph LR

h((head))
nl((NULL))

h-->Node1-->Node2

subgraph next
	Node2-->Node3-->nl
end
```



```c
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode, *List;
```

### 链表逆序遍历

```c
void traverse() {
    
}
```

# 树


```mermaid
graph TD

t((T))
r((r))
d((d))
n((N))
o((o))
e((e))

rt((8))
rt-->e
rt-->notrd

subgraph left
	e
end

subgraph right
	tr((2))
	tr-->t
	tr-->r

    no((2))
    no-->n
    no-->o

    trd((3))
    trd-->d
    trd-->tr

	notrd((5))
	notrd-->no
	notrd-->trd
end    
```

```c
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Tree;
```

### 遍历

```c
void traverse(Tree root) {
    if (root == NULL)
        return;
    do_something(root);
    traverse(root->left);
    traverse(root->right);
}
```

## 二叉树

### 构造二叉树

先序+中序

### 深度

$$
d=1+\max(depth(left),depth(right))
$$

```c
int depth(Tree root) {
    
}
```

### 对称二叉树

### 左右子树互换

## 二叉搜索树

- 所有左子树结点值**均小于**根节点
- 所有右子树结点值**均大于**根节点

### 判断是否为二叉搜索树

### 二叉搜索树后序遍历序列





