*This project has been created as part of the 42 curriculum by <cydupire>, <bclairot>.*

# push_swap

## Description

This activity will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

## Instructions

- Your program must be written in C and follow the 42 Norm.
- You must use two stacks: **stack a** (initial input) and **stack b** (auxiliary).
- Only the predefined operations are allowed:
  - **Swap:** `sa`, `sb`, `ss`
  - **Push:** `pa`, `pb`
  - **Rotate:** `ra`, `rb`, `rr`
  - **Reverse rotate:** `rra`, `rrb`, `rrr`
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

La il faut mettre les trucs qu'on regarde pour 
