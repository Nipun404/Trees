
# Binary Search Tree

In computer science, a binary search tree (BST), also called an ordered or sorted binary tree, is a rooted binary tree data structure whose internal nodes each store a key greater than all the keys in the node's left subtree 
and less than those in its right subtree. 
The time complexity of operations on the binary search tree is directly proportional to the height of the tree.

Binary search trees allow binary search for fast lookup, addition, and removal of data items, and can be used to implement dynamic sets and lookup tables. Since the nodes in a BST are laid out in such a way that each comparison skips about half of the remaining tree, the lookup performance is proportional to that of binary logarithm.

The performance of a binary search tree is dependent on the order of insertion of the nodes into the tree; several variations of the binary search tree can be built with guaranteed worst-case performance. The basic operations include: traversal, insert and delete. BSTs with guaranteed worst-case complexities perform better than an unsorted array, which would require linear search time.


## Tree Traversals

Pre-order, NLR

1. Visit the current node.

2. Recursively traverse the current node's left subtree.

3. Recursively traverse the current node's right subtree.

The pre-order traversal is a topologically sorted one, because a parent node is processed before any of its child nodes is done.

Post-order, LRN

1. Recursively traverse the current node's left subtree.

2. Recursively traverse the current node's right subtree.

3. Visit the current node.

The trace of a traversal is called a sequentialisation of the tree. The traversal trace is a list of each visited node. No one sequentialisation according to pre-, in- or post-order describes the underlying tree uniquely. Given a tree with distinct elements, either pre-order or post-order paired with in-order is sufficient to describe the tree uniquely. 
However, pre-order with post-order leaves some ambiguity in the tree structure.

In-order, LNR

1. Recursively traverse the current node's left subtree.

2. Visit the current node.

3. Recursively traverse the current node's right subtree.