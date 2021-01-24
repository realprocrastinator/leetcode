# leetcode Solution
Agorithm Practice with [Dachris-1](https://github.com/Dachris-1) ;-)

(TODO: add hints to the problems)
(TODO: add solution code)

### Algorithms
#### Easy Probelms

##### Tree

[965.univalued-binary-tree](https://leetcode.com/problems/univalued-binary-tree)

[653.Two Sum IV - Input is a BST](https://leetcode.com/problems/two-sum-iv-input-is-a-bst) 

[669.Trim a Binary Search Tree](https://leetcode.com/problems/trim-a-binary-search-tree)  

[101.Symmetric Tree](https://leetcode.com/problems/symmetric-tree)

[1022.Sum of Root To Leaf Binary Numbers](https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers) 

[404.Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves)

[572.Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree)

##### List

[206.Reverse Linked List](https://leetcode.com/problems/reverse-linked-list)

[203.Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements) 

[83.Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list) 

[234.Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) 

[876.Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list)

[141.Linked List Cycle](https://leetcode.com/problems/linked-list-cycle)

[160.Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists) 

[21.Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/description/)

[237.Delete Node in a Linked List](https://leetcode.com/problems/delete-node-in-a-linked-list)

[1290.Convert Binary Number in a Linked List to Integer](https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer) 

##### Misc

[1.Two Sum](https://leetcode.com/problems/two-sum)

[7.Reverse Integer](https://leetcode.com/problems/reverse-integer)

[9.Palindrome Number](https://leetcode.com/problems/palindrome-number)

[13.Roman to Integer](https://leetcode.com/problems/roman-to-integer)

[14.Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix)

[20.valid-parentheses](https://leetcode.com/problems/valid-parentheses/description/)

[175.Combine Two Tables](https://leetcode.com/problems/combine-two-tables)

[176.Second Highest Salary](https://leetcode.com/problems/second-highest-salary)

[455.Assign Cookies](https://leetcode.com/problems/assign-cookies)

[1413.Minimum Value to Get Positive Step by Step Sum](https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum)


#### Medium Problems
[2.Add Two Numbers](https://leetcode.com/problems/add-two-numbers)

[3.Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters)

[106.Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal)
- using postorder to find the root of each subtree, find the partition in the inorder. 
- do it recursively

[380.Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1)
- key: use a lookup map to map the data with index
- remove --> mark the data as unusable
- swap the last element with the deleted one to avoid rearranging the index

[609.Find Duplicate File in System](https://leetcode.com/problems/find-duplicate-file-in-system)
- hash map
- string manipulation

[652.Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees)
- key: a smallest subtree can be viewed as three tuples (node, lchild, rchild), we can use this as a key to build the map! but be careful the different implementation of data structure in diff languages(dict in python use hash).

[729.My Calendar I](https://leetcode.com/problems/my-calendar-i)
- range && bound check

[779.K-th Symbol in Grammar](https://leetcode.com/problems/k-th-symbol-in-grammar)
- binary search and bitwise operation
- key: N-th row has 2^(N-1) bits
- first half is the ones complement of the second half

[1048.Longest String Chain](https://leetcode.com/problems/longest-string-chain)
- sort the list by len so that we can use DP!
- hashmap + O(n^2) lookup, using combinations module
- using DP to memorize the pre's longest chain, so every time we pick the next, we simply just do two things, 
  - 1. check  if the combinations of the substring is the list or not
  - 2. is yes we add the longest chain of the substring to our own

[1117. Building H2O](https://leetcode.com/problems/building-h2o)
- mutex with 2 conditional variables

[1208.Get Equal Substrings Within Budget](https://leetcode.com/problems/get-equal-substrings-within-budget)
- DP not working because we need to find the contiguous substring!
- use sliding window

[1472.Design Browser History](https://leetcode.com/problems/design-browser-history)
- two stacks
- cur and pos cursor changing


#### Hard Problems
[126.Word Ladder II](https://leetcode.com/problems/word-ladder-ii)
- Bi-direction BFS

[887.Super Egg Drop](https://leetcode.com/problems/smallest-good-base)
- key : bottom up analysis, DP, reverse thinking , given drops and eggs how many levels can I build?
- refer: 9021 week 5 the tower and marbles puzzles

[483.Smallest Good Base](https://leetcode.com/problems/smallest-good-base)
- determine the range of digits in binary rep
- determine range of base

