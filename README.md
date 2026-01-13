*This project has been created as part of the 42 curriculum by cydupire, bclairot.*

# push_swap

## Description

This program computes the lowest number of operations needed to sort data on a stack. It works with a limited set of operations and chooses the most appropriate solution between various types of algorithms for optimized data sorting.

***Constraints:***  
Two stacks are used: **stack a** (initial input) and **stack b** (auxiliary).  
Only the predefined operations are allowed:
  - **Push:** 
    - `pa`: Push the top element of the stack b onto the stack a
    - `pb`: Push the top element of the stack a onto the stack b
  - **Swap:** 
    - `sa`: Swap the first two elements of the stack a
    - `sb`: Swap the first two elements of the stack b
    - `ss`: Perform sa and sb simultaneously
  - **Rotate:** 
    - `ra`: Rotate the stack a upwards (first element becomes the last)
    - `rb`: Rotate the stack b upwards
    - `rr`: Perform ra and rb simultaneously
  - **Reverse rotate:** 
    - `rra`: Rotate the stack a downwards (last element becomes the first)
    - `rrb`: Rotate the stack b downwards 
    - `rrr`: Perform rra and rrb simultaneously  

***The program:***  
- parses and validates all input integers  
- detects duplicates, invalid characters, and overflows  
- initializes the stack `a`  
- computes the "**disorder metric**" (0 = sorted, 1 = worst case)  
- chooses the most appropriate sorting strategy from **four different algorithms**  
- outputs the final list of operations needed to sort the numbers.  

## Instructions

```shell
# Clone the repository:
git clone
# Navigate to the project folder: 
cd push_swap
# Compile the program: 
make
# Run the program with a list of integers and optionnal flags: 
./push_swap --simple 3 2 1 0 "10 5 -1"
```
Available flags:  
`--simple` to run the O(n^2) algorithm  
`--medium` to run  the O(n√n) algorithm  
`--complex` to run  the O(n log n) algorithm  
`--adaptive` to run a strategy adapted to the measured disorder (default behavior if no flag is given)  
`--bench` to activate the benchmark mode, printing additionnal information about the program's output



## Algorithms

### Insertion sort

- Overview  
Insertion sort is a simple algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list.  
This algorithm was adapted by insering the value into its correct position in the stack b, then pushing back all the sorted values into the stack a.
  
- Complexity  
  - O(n2) for the average case.
  - The use of the push_swap operations adds some complexity as the program pushes back and forth between the stacks. The bigger the stack, the more the complexity scales up.

- Strengths 
  - Easy to implement
  - Stable sorting
  - Efficient for small stacks or when the disorder is small

- Weaknesses  
  - Inefficient for large stacks


### Bucket/range sort:

- Overview  
  Bucket sort divides the range of values into several buckets, distributes elements into these buckets, then performs a simple sort inside each bucket and concatenates the results.   
  In our push_swap, this algorithm is adapted by grouping values by index, pushing groups to stack b and inserting the values back into the stack a in the correct order using minimal rotations.

- Complexity  
  - Average: O(n + k + m^2) depending on bucket distribution (k = number of buckets, m = average bucket size).    
  - Moves count in push_swap depends on how many rotations are required per element.

- Strengths (why we include it)  
  - Flexible: bucket granularity is tuned by input size.  
  - Good hybrid: combining coarse bucketing with local insertion yields low moves for partially ordered or clustered data.  

- Weaknesses  
   - Requires extra logic to manage bucket boundaries and efficient reinsertion strategy.  
  - Not as predictable as radix for uniformly distributed values.

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
  - For very small n, constant overhead gives longer sequences than specialized small-sort strategies.  
  - Requires bit-wise passes; performance sensitive to whether you compress values to ranks.  
  - Less effective if implementation doesn't compress values first (more passes needed).

## Resources
- Subject of the projet [push_swap.pdf](./en.subject.pdf)
- Peer-to-peer (special thanks to ...)
- Extensive [guide about sorting algorithms](https://www.geeksforgeeks.org/dsa/introduction-to-sorting-algorithm/)
- Blog article about sorting algorithms with [detailled explanations of the simple algorithms](https://medium.com/jl-codes/understanding-sorting-algorithms-af6222995c8) (bubble, selection, insertion)
- Youtube video about [common sorting algorithms](https://www.youtube.com/watch?v=AAwYzYkjNTg)


- AI has been used on this project to help refactor the code (when it was too long or did not comply with the norm) and to populate some sections of the Readme which have been revised later on.

## Project organisation

*cydupire* was in charge of the scripts regarding operations as well as the simple and complex algorithms.  
*bclairot* set up the projet and worked on the parsing, initialisation, error management, bench and complex algorithm.
Both participated in the redaction of the Makefile and the README.