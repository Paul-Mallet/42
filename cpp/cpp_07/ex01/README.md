# ex01 - Iter

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

## Type Inference & Deduction

L'inférence de type est la capacité qu’à un compilateur à déduire le type d’une expression sans que celui-ci ne soit explicitement écrit dans le code source.

...

Qualifiers removed by the compiler if not (*) or (&) given as param, it's called const-correctness.
T& or T*, final argument becomes const type& or const type*, so MUST pass same const type as arguments.

**Insight** : gdb <ptype>, show type deduction on instanciated template function.

## Resources

(Template Type deduction)[https://zestedesavoir.com/tutoriels/474/la-deduction-de-type-en-c/#1-14254_les-regles-de-deduction-des-templates]
(The C++ Programming Language - Bjarne Stroustrup, 3rd Edition)[http://www.staroceans.org/e-book/The_C__Programming_Language__Stroustrup_.pdf]
(Overloads and templates - cplusplus.com)[https://cplusplus.com/doc/tutorial/functions2/]
(Unit Testing - Catch2 v1.12.0)[https://catch2-temp.readthedocs.io/en/latest/test-cases-and-sections.html]
(How works doxygen under the hood - Doxygen v1.9.8)[https://www.doxygen.nl/manual/starting.html#xml_out]