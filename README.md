*This activity has been created as part of the 42 curriculum by schoisi & abaptist*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (`a` and `b`) and a restricted set of operations, while minimizing the total number of operations used.

The project explores algorithmic complexity in a concrete way: sorting is easy, but sorting *efficiently* with limited tools is another challenge entirely. The program must select the most appropriate sorting strategy based on the input size and its disorder level.

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` binary. Available Makefile rules: `all`, `clean`, `fclean`, `re`.

### Execution

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <list of integers>
```

**Strategy flags (optional):**

| Flag | Algorithm | Complexity |
|------|-----------|------------|
| `--simple` | Insertion/Selection/Bubble sort adaptation | O(n²) |
| `--medium` | Chunk-based / bucket sort adaptation | O(n√n) |
| `--complex` | Radix / Merge / Quick sort adaptation | O(n log n) |
| `--adaptive` | Adaptive strategy based on disorder metric | depends on disorder |

If no flag is given, `--adaptive` is used by default.

**Benchmark mode:**

```bash
./push_swap --bench [--adaptive] <list of integers>
```

Outputs (to `stderr`) the disorder percentage, strategy used, total operation count, and per-operation breakdown.

### Usage Examples

```bash
# Basic sort
$> ./push_swap 2 1 3 6 5 8

# Count operations on 5 numbers
$> ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Force O(n²) strategy
$> ./push_swap --simple 5 4 3 2 1

# Verify with checker
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# Large input benchmark
$> shuf -i 0-9999 -n 500 > args.txt; ./push_swap --bench $(cat args.txt) 2>&1
```

### Error Handling

The program prints `Error` to `stderr` when:
- An argument is not a valid integer
- An integer is outside the `INT` range
- Duplicate values are provided

## Algorithms

Four sorting strategies are implemented. The program measures the **disorder** of the input stack before sorting — a value between `0` (already sorted) and `1` (fully reversed) — and uses it to select the best strategy automatically in adaptive mode.

### Disorder Metric

```
disorder = number of inverted pairs / total pairs
```

Computed in O(n²) before any move is made.

---

### 1. Simple Algorithm — O(n²)

**Strategy:** Insertion sort adaptation.

For each element in stack `a`, we find its correct position and rotate the stack to insert it in order. When the input is small or nearly sorted, this approach is simple and effective.

**Justification:** For small inputs (n ≤ ~10), the constant overhead of more complex algorithms is not worth it. Insertion sort naturally benefits from low disorder.

---

### 2. Medium Algorithm — O(n√n)

**Strategy:** Chunk-based sorting.

The range of values is divided into √n chunks. Elements are pushed to stack `b` chunk by chunk (from largest to smallest), then pushed back to stack `a` in sorted order. Rotations within each chunk keep the operation count bounded.

**Justification:** This is the sweet spot for medium-sized inputs (n ~ 100–500). It avoids the high constant of O(n log n) methods while being significantly faster than O(n²) for random inputs.

---

### 3. Complex Algorithm — O(n log n)

**Strategy:** Radix sort (LSD) adaptation using binary representation.

Numbers are normalized to positive indices, then sorted bit by bit from the least significant bit. For each bit, elements are pushed to `b` (bit = 0) or kept in `a` (bit = 1), then pushed back. This requires O(log n) passes of O(n) operations each.

**Justification:** For large inputs (n = 500+), this is the most predictable and scalable approach. It is not sensitive to the initial disorder of the input.

---

### 4. Adaptive Algorithm (Custom Design)

The adaptive strategy measures disorder first and delegates to the appropriate method:

| Disorder | Method Used | Complexity |
|----------|-------------|------------|
| `< 0.2` (low) | Few targeted rotations / insertion of misplaced elements | O(n) |
| `0.2 ≤ d < 0.5` (medium) | Chunk-based sort | O(n√n) |
| `≥ 0.5` (high) | Radix sort (LSD) | O(n log n) |

**Threshold rationale:**
- Below 0.2, most pairs are already in order. Only a handful of elements need repositioning, achievable with linear scan and targeted swaps/rotations.
- Between 0.2 and 0.5, partial disorder calls for a chunked approach that exploits existing local order.
- Above 0.5, the stack is too disordered to exploit structure; a bit-by-bit radix approach is the safest.

**Space complexity:** All strategies operate in O(1) auxiliary space beyond the two stacks (no additional arrays allocated for the sort itself).

---

## Performance Targets

| Input size | Pass | Good | Excellent |
|------------|------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Contributors

| Login | Contributions |
|-------|--------------|
| schoisi | Stack data structures, simple & adaptive algorithms, Makefile, error handling, benchmark mode |
| *(partner login)* | Medium & complex algorithms, disorder metric, testing & checker integration |

## Resources

### Documentation & References

- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting) — interactive visualization of classic sorts
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) — complexity reference
- [Radix Sort – Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Chunk-based push_swap approach](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a) — community article on the chunk strategy
- [42 Docs / Norm](https://github.com/42School/norminette) — norminette tool

### AI Usage

Claude (Anthropic) was used during this project for the following tasks:

- **README generation**: drafting the structure and content of this file based on the subject requirements.
- **Algorithm explanation**: helping clarify the rationale and complexity bounds of each strategy before implementation.
- **Debugging assistance**: asking targeted questions about edge cases (e.g., single-element stacks, already-sorted inputs).

All AI-generated content was reviewed, understood, and validated by both team members before being included in the project. No code was copied from AI output without full comprehension.
