# leetcode Solution
(TODO: add links to the problems)

### SQL

\175. Combine Two Tables

### Algorithms

\1. Two Sum

\2. Add Two Numbers

\3. Longest Substring Without Repeating Characters

\14. 

\625. Find Duplicate Subtrees

- key: a smallest subtree can be viewed as three tuples (node, lchild, rchild), we can use this as a key to build the map! but be careful the different implementation of data structure in diff languages(dict in python use hash).

\380. Insert Delete GetRandom O(1)

- key: use a lookup map to map the data with index
- remove --> mark the data as unusable
- swap the last element with the deleted one to avoid rearranging the index

\\887. Super Egg Drop 200411

- key : bottom up analysis, DP, reverse thinking ,given drops and eggs how many levels can I build?
- refer: 9021 week 5 the tower and marbles puzzles

\1208. Get Equal Substrings Within Budget

- DP not working because we need to find the contiguous substring!
- use sliding window

\1048. Longest String Chain

- sort the list by len so that we can use DP!

- hashmap + O(n^2) lookup, using combinations module
- using DP to memorize the pre's longest chain, so every time we pick the next, we simply just do two things, 
  - 1. check  if the combinations of the substring is the list or not
    2. is yes we add the longest chain of the substring to our own

\779. K-th Symbol in Grammar

- binary search and bitwise operation
- key: N-th row has 2^(N-1) bits
- first half is the ones complement of the second half

\483. Smallest Good Base

- determine the range of digits in binary rep

- determine range of base

\609. Find Duplicate File in System

- hash map
- string manipulation

\1117. Building H2O

- mutex with 2 conditional variables

\1472. Design Browser History

- two stacks
- cur and pos cursor changing

\729. [ My Calendar I](https://leetcode.com/problems/my-calendar-i)  

- range && bound check

\106. Construct Binary Tree from Inorder and Postorder Traversal

- using postorder to find the root of each subtree, find the partition in the inorder. 
- do it recursively