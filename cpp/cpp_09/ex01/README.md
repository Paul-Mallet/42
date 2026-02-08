# ex01 - Reverse Polish Notation

The Reverse Polish Notation (RPN) is a postfix notation in opposition to infix one in commun mathematics calculations.
Infix notation needs for order of operations and parentheses, which is less convenient to handle.
It's one of the best way for a computer to calculate operands with operators, its left-to-right order allows to apply the LIFO principle.
Hand-held calculators such as Texas Instrument, even stack-oriented programming languages are built on this principle too.

## How to run ?

```bash
	make
	make doc
	make test
	make debug
	make clean
	make fclean
	make re
```

## std::stack

The **std::stack** container adapter was the perfect match for this exercise.

WHY ?
* Last In First Out principle.
* Limited methods to avoid logic misconceptions (top(), pop() & push()).
* Only the 2 last pushed elements to calculate with the current operator are needed.
* RPN already handle the order and priority in its logic, no need to access in the middle data.
* Stack wrap std::deque, it offers dynamic resize in memory.

## Sources

[Concept & WHY? - Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
[std::stack - cplusplus.com](https://cplusplus.com/reference/stack/stack/)
[Standard Containers - The C++ Programming Language, 3rd edition](http://www.staroceans.org/e-book/The_C__Programming_Language__Stroustrup_.pdf)