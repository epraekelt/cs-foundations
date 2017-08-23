### Insertion Sort

An iterative sorting algorithm that incrementally places each element in its correct location.

#### Pseudocode

```
i ← 1
while i < length(A)
  j ← i
  while j > 0 and A[j] < A[j-1]
    swap A[j] and A[j-1]
    j ← j - 1
  end while
  i ← i + 1
end while
```

#### Performance

Average-Case: O(n<sup>2</sup>) comparisons and swaps
Worst-Case:   O(n<sup>2</sup>) comparisons and swaps
Best-Case:    O(n) comparisons and O(1) swaps
