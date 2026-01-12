*This project has been created as part of the 42 curriculum by cydupire, bclairot.*

# push_swap

## Description

This program computes the lowest number of actions needed to sort data on a stack. It works with a limited set of operations and chooses the most appropriate solution between various types of algorithms for optimized data sorting.

- You must use two stacks: **stack a** (initial input) and **stack b** (auxiliary).

- Only the predefined operations are allowed:
  - **Swap:** 
    - `sa`: Swap the first two elements of stack a
    - `sb`: Swap the first two elements of stack b
    - `ss`: Perform sa and sb simultaneously
  - **Push:** 
    - `pa`: Push the top element of stack b onto stack a
    - `pb`: Push the top element of stack a onto stack b
  - **Rotate:** 
    - `ra`: Rotate stack a upwards (first element becomes the last)
    - `rb`: Rotate stack b upwards (first element becomes the last)
    - `rr`: Perform ra and rb simultaneously
  - **Reverse rotate:** 
    - `rra`: Rotate stack a downwards (last element becomes the first)
    - `rrb`: Rotate stack b downwards (last element becomes the first)
    - `rrr`: Perform rra and rrb simultaneously

- The program:
  - parses and validates all input integers
  - detects duplicates, invalid characters, and overflows
  - initializes stack `a`
  - computes the “**disorder metric**” (0 = sorted, 1 = worst case)
  - chooses the most appropriate sorting strategy from at least **four different algorithms**
  - outputs the final list of operations needed to sort the numbers.

## Instructions

```shell
# Clone the repository:
git clone
# Navigate to the project folder: 
cd push_swap
# Compile the program: 
make
#Flags available:
#--simple: for the O(n^2) algorithm
#--medium: for the O(n√n)) algorithm
#--complex: for the O(n log n) algorithm
#--adaptive: for a strategy adapted to the measured disorder (default behavior if no flag is given)
#--bench: activate the benchmark mode, printing additionnal information about the program's output
# Run the program with a list of integers and the flags of your choice: 
./push_swap 3 2 1 0 "10 5 -1"
```

## Resources

- Peer-to-peer;
- youtube videos:
    -[Explaining EVERY Sorting Algorithm (part 1)](https://www.youtube.com/watch?v=AAwYzYkjNTg)
- Subject PDF: [push_swap.pdf](./en.subject.pdf)
- AI has been used on this project to help to refactor when the code was too long for the norm and to generate a first version of the readme who was modifie by hand later on.

## Algorithms

### Bubble sort

- Overview  
  Bubble sort repeatedly compares adjacent elements and swaps them if they are out of order. In the push_swap context it is the simplest strategy to produce correct, short solutions for very small or almost-sorted inputs.

- Complexity  
  - Best: O(n) when already sorted (with early-exit optimization)  
  - Average / Worst: O(n^2) comparisons and swaps  
  - Moves in push_swap terms depend on how adjacent traversal is implemented (rotations + swaps), but for small n the total operations remain low.

- Strengths (why we include it)  
  - Excellent for tiny lists (n ≤ 10) — it yields very short, easy-to-prove sequences.  
  - Very efficient on nearly-sorted data (disorder metric close to 0) because of early-exit.  
  - Trivial to implement and to reason about; useful as a fallback strategy in a hybrid sorter.

- Weaknesses  
  - Not suitable for large, random inputs due to quadratic behavior.  
  - Direct bubble on large n will produce many rotations/swaps and is suboptimal compared with radix, insertion, or bucket strategies.

### Bucket insertion sort:

- Overview  
  Bucket insertion sort divides the range of values into several buckets, distributes elements into these buckets, then performs insertion sort (or another simple sort) inside each bucket and concatenates the results. In push_swap this can be adapted by grouping values (by index or value ranges), pushing groups to stack b, inserting them back into a in the correct order using minimal rotations and pushes.

- Complexity  
  - Average: O(n + k + m^2) depending on bucket distribution (k = number of buckets, m = average bucket size).  
  - Worst: O(n^2) if buckets are uneven (all elements land in one bucket).  
  - Moves count in push_swap depends on chosen grouping and how many rotations/pushes are required per element.

- Strengths (why we include it)  
  - Flexible: bucket granularity can be tuned by input size or disorder metric.  
  - Good hybrid: combining coarse bucketing with local insertion yields low moves for partially ordered or clustered data.  
  - Scales better than naive quadratic methods when buckets keep sizes small (useful for medium n).

- Weaknesses  
  - Sensitive to bucket choice — poor splitting increases moves dramatically.  
  - Requires extra logic to manage bucket boundaries and efficient reinsertion strategy.  
  - Not as predictable as radix for uniformly distributed integers.

### Radix sort:

- Overview  
  Radix sort processes numbers by digits (or bits) from least significant to most, distributing elements into buckets per digit. In push_swap the binary (bitwise) radix is common: for each bit position, push elements with 0 in that bit to stack b and rotate/preserve those with 1, then push b back — repeat for all bits.

- Complexity  
  - Time: O(n * d) where d is number of digits/bits (for 32-bit ints d ≤ 32).  
  - Moves: O(n * d) pushes/rotates, which is linear in n for fixed word size.

- Strengths (why we include it)  
  - Predictable, fast for large n — near-linear move count.  
  - Simple to implement with index compression (use ranks so d = ceil(log2(n))).  
  - Works well on random large datasets and often yields competitive move counts in push_swap.

- Weaknesses  
  - For very small n, constant overhead gives longer sequences than specialized small-sort routines.  
  - Requires bit-wise passes; performance sensitive to whether you compress values to ranks.  
  - Less effective if implementation doesn't compress values first (more passes needed).
