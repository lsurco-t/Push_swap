# Push Swap

## Project Overview

Push Swap is a sorting algorithm project that uses two stacks and a limited set of operations to sort integers in ascending order with the minimum number of moves. This project aims to develop a deep understanding of algorithm optimization, data structures, and efficient problem-solving strategies.

## Features

This project implements an optimized stack sorting algorithm with several key features and techniques:

**Algorithm Design:**
- Greedy algorithm implementation for optimal move selection
- Cost analysis system for comparing operation efficiency
- Median-based partitioning using quicksort concepts
- Hybrid sorting approach based on dataset size

**Stack Operations:**
- Push operations: `pa`, `pb` (push from one stack to another)
- Swap operations: `sa`, `sb`, `ss` (swap top two elements)
- Rotate operations: `ra`, `rb`, `rr` (shift elements up)
- Reverse rotate operations: `rra`, `rrb`, `rrr` (shift elements down)

**Optimization Techniques:**
- Early termination for already sorted stacks
- Different strategies for small (≤5) vs large datasets
- Rotation direction optimization (forward vs backward)
- Memory-efficient median calculation with fallback handling

**Key Algorithms:**
- `algorithm()` - Main sorting coordination and strategy selection
- `greedy_sort()` - Cost-based optimal move selection
- `optimized_push()` - Median-based initial partitioning
- `find_best_move()` - Comprehensive cost analysis for all possible moves
- `find_median()` - Quicksort-based median calculation

For the complete implementation, check the `sources/` directory.

## How to Use

**Compile the project:**
```bash
make
```

**Run with integer arguments:**
```bash
./push_swap 3 2 5 1 4
```

## Authors

**lsurco-t**

