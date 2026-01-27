# ex02 - Array

...

## Program Commands

```bash
	# using GNU Makefile builder
	make
	# doxygen documentation (html)
	make doc
	# catch2 test tools (v.1.12.0)
	make test
	# gdb debugger
	make debug
	# remove .o files
	make clean
	# remove doc/ and exec file
	make fclean
	# recompile the project
	make re
```

**Insights** :
* L'ajout de throw() à la fin de la méthode what() est une spécificité de la norme C++98 que l'on appelle une spécification d'exception.
* Non-emission compiler promise + Base Class (std::exception) signature to fit too (must not be less strict than Base one).
* Avoid trigger std::terminate by inf looping on new throw exception inside what()
* Il n'a pas besoin de prévoir de "plan de secours" (stack unwinding)

**Insights** :
* new [n](), () force auto init to 0 for scalar (simple) types, if must not init values inn same logic
* NULL, delete [] on NULL array do nothing, best approach

**Insights** :
* Compiler adds a Cookie / overhead number when using new [], just before memory array in RAM.
* delete [] will read it to know how many deletion are needed.

## Const-Correctness

Overloading both const and non-const versions of the subscript operator ([]) ensures that elements can be accessed in a **read-only** manner when the object is const, preventing **unintended modifications** to const data types.

Implementing both versions of the subscript operator is a best practice in C++ to maintain clarity and adhere to const-correctness principles, enhancing code safety and predictability.

## Resources

(Operator[], Subscript - geeksforgeeks.com)[https://www.geeksforgeeks.org/cpp/overloading-subscript-or-array-index-operator-in-c/]
(The C++ Programming Language - Bjarne Stroustrup, 3rd Edition)[http://www.staroceans.org/e-book/The_C__Programming_Language__Stroustrup_.pdf]
(Unit Testing - Catch2 v1.12.0)[https://catch2-temp.readthedocs.io/en/latest/test-cases-and-sections.html]
(How works makefile - GNU Makefile)[https://www.labri.fr/perso/renault/working/teaching/projets/files/Makefile.pdf]
(How works doxygen under the hood - Doxygen v1.9.8)[https://www.doxygen.nl/manual/starting.html#xml_out]