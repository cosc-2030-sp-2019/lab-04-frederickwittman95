# cosc-2030-lab04-binarytrees\

Frederick Wittman

Dr. Hill

COSC 2030-01

11 March 2019

### Problem: Distinguish between binary search, binary trees, and binary search trees.

***Solution*** 

Binary search is a search algorithm over a numerically ordered list.  The middle value (or values) of the whole list are compared with the value we would like to find.  If there is no match, we check if the value in question is greater or less than the middle value(s).  Since the list is ordered, this comparison tells us which half of the list to check next.  The list is subdivided in this manner until a match is found or it is determined that the value in question is not in the list (because all the locations where it could possibly be have been checked).

A binary tree is an abstract data type.  It consists of values, numerical or otherwise.  The base of a binary tree is the root value, which can connect (i.e. by a line on paper, or by a pointer in C++) to up to two other values (0, 1, or 2).  The "child" values can connect to up to two other values, and so on.  

Binary search trees are binary trees, where, beginning with the root, the left child of each node is smaller than the parent node, and the right child is greater than the parent node.  Because of this pattern of organization, search over binary search trees is analogous to binary search over a list, and is O(log n).  If the values of the tree are randomly distributed, search is O(n).
