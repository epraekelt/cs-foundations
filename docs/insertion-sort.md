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

|               | Average          | Worst            | Best |
| -------------:|:----------------:|:----------------:|:----:|
| Comparisons   | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(n) |
| Swaps         | O(n<sup>2</sup>) | O(n<sup>2</sup>) | O(1) |

#### Explanation

Insertion Sort iterates over the input data, removing an element each time and inserting it into its correct place. It finds the correct location by iteratively comparing the element to the already-placed elements.
<br>
This is traditionally achieved by moving up the input list and inserting elements behind the iterator. Each value is checked against the largest value in the sorted (sub-)list. If it's larger, the element is left in place. If it's smaller, the values are swapped and the comparison carried out again. In this way, the smaller value keeps moving down the list until it is in place.
