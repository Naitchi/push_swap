*This project has been created as part of the 42 curriculum by cydupire, bclairot.*

# push_swap

## Description

This activity will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

## Start the project
```shell
# Clone the repository:
git clone
# Navigate to the project folder: 
cd push_swap
# Compile the program: 
make
# Run the program with a list of integers: 
./push_swap 3 2 1 0 "10 5 -1"
```

## Instructions

- Your program must be written in C and follow the 42 Norm.

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

- The program must:
  - parse and validate all input integers,
  - detect duplicates, invalid characters, and overflows,
  - initialize stack `a`,
  - compute the “**disorder metric**” (0 = sorted, 1 = worst case),
  - choose the most appropriate sorting strategy from at least **four different algorithms**,
  - output the final list of operations to sort the numbers.

- You must provide a `Makefile` with the rules:  
  **all**, **clean**, **fclean**, **re** (and **bonus** if applicable).

- Memory leaks, undefined behavior, and crashes (segfaults, overflows, etc.) are strictly forbidden.

## Resources

- Peer-to-peer;
- Subject PDF: [push_swap.pdf](./en.subject.pdf)
