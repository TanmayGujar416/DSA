# 📚 DSA Practice Repository

![Status](https://img.shields.io/badge/Status-Active-brightgreen)

This repository documents my journey of learning Data Structures and Algorithms in C++. It contains solutions organized by topic, primarily following the Striver A2Z DSA roadmap and LeetCode problems, serving as both a practice log and a quick reference for common algorithms and patterns.

## 📂 Repository Structure

```
Directory structure:
└── tanmaygujar416-dsa/
    ├── README.md
    ├── Array/
    │   ├── 121.best-time-to-buy-and-sell-stock.cpp
    │   ├── 125.valid-palindrome.cpp
    │   ├── 3LargestElement.cpp
    │   ├── add1tothelastelement.cpp
    │   ├── BuyAndSell.cpp
    │   ├── ReversalOfAnArray.cpp
    │   └── Two sum/
    │       ├── PairSumEqualsTarget.cpp
    │       └── twoPointerAproach.cpp
    ├── Binery Search/
    │   ├── 1011.capacity-to-ship-packages-within-d-days.cpp
    │   ├── 1283.find-the-smallest-divisor-given-a-threshold.cpp
    │   ├── 1482.minimum-number-of-days-to-make-m-bouquets.cpp
    │   ├── 153.find-minimum-in-rotated-sorted-array.cpp
    │   ├── 1539.kth-missing-positive-number.cpp
    │   ├── 1552.magnetic-force-between-two-balls.cpp
    │   ├── 162.find-peak-element.cpp
    │   ├── 33.search-in-rotated-sorted-array.cpp
    │   ├── 34.find-first-and-last-position-of-element-in-sorted-array.cpp
    │   ├── 35.search-insert-position.cpp
    │   ├── 410.split-array-largest-sum.cpp
    │   ├── 540.single-element-in-a-sorted-array.cpp
    │   ├── 69.sqrt-x.cpp
    │   ├── 704.binary-search.cpp
    │   ├── 81.search-in-rotated-sorted-array-ii.cpp
    │   ├── 875.koko-eating-bananas.cpp
    │   ├── code.cpp
    │   └── findKRotation.cpp
    ├── DP/
    │   ├── 120.triangle.cpp
    │   ├── 1289.minimum-falling-path-sum-ii.cpp
    │   ├── 198.house-robber.cpp
    │   ├── 213.house-robber-ii.cpp
    │   ├── 62.unique-paths.cpp
    │   ├── 63.unique-paths-ii.cpp
    │   ├── 64.minimum-path-sum.cpp
    │   ├── 70.climbing-stairs.cpp
    │   ├── 740.delete-and-earn.cpp
    │   ├── 746.min-cost-climbing-stairs.cpp
    │   ├── 931.minimum-falling-path-sum.cpp
    │   ├── Maximum-Sum-of-Non-Adjacent-Elements.cpp
    │   └── Ninja-Training.cpp
    ├── Graph/
    │   ├── 102.binary-tree-level-order-traversal.cpp
    │   ├── 104.maximum-depth-of-binary-tree.cpp
    │   ├── 200.number-of-islands.cpp
    │   ├── 236.lowest-common-ancestor-of-a-binary-tree.cpp
    │   ├── 547.number-of-provinces.cpp
    │   ├── 733.flood-fill.cpp
    │   ├── AdjacencyList.cpp
    │   └── AdjacencyMatrix.cpp
    ├── LinkedList/
    │   ├── Add1toLL.cpp
    │   ├── Add2Numbers.cpp
    │   ├── ArrayToLLANDTreversal.cpp
    │   ├── cloneLinkedListWithRandompointers.cpp
    │   ├── deleteTheMiddleNode.cpp
    │   ├── deletion.cpp
    │   ├── DetectALoop.cpp
    │   ├── findIntractionInY.cpp
    │   ├── FlatteningLL.cpp
    │   ├── insertion.cpp
    │   ├── isPalindrome.cpp
    │   ├── LengthOfLoop.cpp
    │   ├── LL.cpp
    │   ├── MiddleOffLL.cpp
    │   ├── OddEvenLL.cpp
    │   ├── RemoveNthNodeFromLast.cpp
    │   ├── reverseLL.cpp
    │   ├── ReverseNodeinKGroup.cpp
    │   ├── sort012.cpp
    │   ├── sortALL.cpp
    │   ├── tempCodeRunnerFile.cpp
    │   ├── DoublyLinkedList/
    │   │   ├── DLL.cpp
    │   │   ├── insertionDLL.cpp
    │   │   ├── reverseDLL.cpp
    │   │   └── tempCodeRunnerFile.cpp
    │   └── Leetcode/
    │       ├── 160.intersection-of-two-linked-lists.cpp
    │       ├── 19.remove-nth-node-from-end-of-list.cpp
    │       ├── 2.add-two-numbers.cpp
    │       ├── 203.remove-linked-list-elements.cpp
    │       ├── 206.reverse-linked-list.cpp
    │       ├── 234.palindrome-linked-list.cpp
    │       ├── 237.delete-node-in-a-linked-list.cpp
    │       └── 876.middle-of-the-linked-list.cpp
    ├── Recursion/
    │   ├── 39.combination-sum.cpp
    │   ├── 40.combination-sum-ii.cpp
    │   ├── 46.permutations.cpp
    │   ├── 47.permutations-ii.cpp
    │   ├── 509.fibonacci-number.cpp
    │   ├── 77.combinations.cpp
    │   ├── 78.subsets.cpp
    │   ├── 90.subsets-ii.cpp
    │   ├── fibonacci.cpp
    │   ├── Printsubsequence.cpp
    │   └── SubsequenceWithSumK.cpp
    ├── Sorting Algorithms/
    │   ├── Bubble Sort/
    │   │   └── code.cpp
    │   ├── Insertion Sort/
    │   │   └── code.cpp
    │   └── Selection Sort/
    │       ├── code.c
    │       └── code.cpp
    ├── Stack And Queue/
    │   ├── Queue/
    │   │   ├── 232.implement-queue-using-stacks.cpp
    │   │   ├── QueueImplementationUsingArray.cpp
    │   │   └── QueueImplementationWithLinkedList.cpp
    │   └── Stack/
    │       ├── 155.min-stack.cpp
    │       ├── 20.valid-parentheses.cpp
    │       ├── 225.implement-stack-using-queues.cpp
    │       ├── 496.next-greater-element-i.cpp
    │       ├── 503.next-greater-element-ii.cpp
    │       ├── infixToPostfix.cpp
    │       ├── infixToPrefix.cpp
    │       ├── nextGreaterElement.cpp
    │       ├── nextGreaterElement2.cpp
    │       ├── previousSmallerElement.cpp
    │       ├── stackImplementationUsingArray.cpp
    │       └── StackImplementWithLinkedList.cpp
    ├── string/
    │   └── aoti.cpp
    └── Trees/
        ├── 1.cpp
        ├── levelOrderTraversal.cpp
        └── PreorderTraversalWithStack.cpp

```

Each folder contains standalone `.cpp` solutions. Files prefixed with a number (e.g. `70.climbing-stairs.cpp`) correspond directly to that problem on [LeetCode](https://leetcode.com/); files without a number are custom practice problems or utility implementations.

## 📊 Progress

| Topic               | Status | Problems |
| ------------------- | :----: | -------: |
| Arrays              |   ✅   |        8 |
| Binary Search       |   ✅   |       16 |
| Dynamic Programming |   ✅   |       11 |
| Linked List         |   ✅   |       25 |
| Recursion           |   ✅   |       10 |
| Sorting Algorithms  |   🚧   |        3 |
| Strings             |   🚧   |        1 |
| Trees               |   🚧   |        0 |
| Graphs              |   🚧   |        0 |

- **Language:** C++
- **Problems Solved:** 70+
- **Topics Covered:** 7
- **Platforms:** LeetCode, Coding Ninjas, Striver A2Z

## 📚 Learning Resources

- [Striver A2Z DSA Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/)
- [LeetCode](https://leetcode.com/)
- [Take U Forward](https://takeuforward.org/)

## 🔜 Upcoming Topics

- Stack
- Queue
- Trees
- Binary Search Tree
- Heap
- Graph
- Trie

## 🚀 Getting Started

To compile and run any file:

```bash
g++ -o solution path/to/file.cpp
./solution
```

## 🤝 Contributing

This is a personal learning repo, but suggestions, corrections, or more optimized approaches are welcome via issues or pull requests.
