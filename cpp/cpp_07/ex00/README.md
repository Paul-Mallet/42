# ex00 - Function Templates

The main goal of this exercise is to introduce the functions templates within an .hpp header structure. 

**🧾 Notes** : As a remainder and deeper use, some Makefile, Unit Tests Principles were introduced too at the EOF.

## TL;DR

Here's a how to run the project checklist:

```bash
	# ./Makefile
	make #build the executable
	make clean #clean the obj/
	make fclean #clean the obj/, executable & docs/
	make test #test with catch2
	make doc #generate doc with ./Doxyfile
	make re #full clean, the build
```

## Function Templates

**💡 Tips** :
* Use **PRE-inc/decrementation operators** > POST ones in loop if not using it, because of **Object temp copies** in memory !
* sudo apt install [dependency] -y, **-y** to not have to enter Y after the download starts.

## 📕 Makefile

[French Guide on How to Efficiently Build a Makefile](https://www.labri.fr/perso/renault/working/teaching/projets/files/Makefile.pdf)

<code>make</code> :
* Research in **current** working directory, not sub ones.
* Can have 1 Makefile/directory -> Useful with meta generator (cf. CMake).

Makefile Structure :
* **Rules** : 

## 🧪 Unit Testing (in C++)

A **granular** & **single-responsability** oriented list of tests / functions or classes.

### TDD

The **Test Driven Development** Approach follows 3 simple steps known as **"Red-Green-Refactor"** :
1. **Red** : Create only 1 test that fail.
2. **Green** : Minimal code to pass the test that failed.
3. **Refactor** : Improve the minimal code (+ maintainable, readable, optimized, performant, ...)

**✅ Pros** :
* + simple problem resolution.
* + confident about our code base.
* + documentation exemples ready.
* + early bug / bad logic detections.

**❌ Cons** :
* - perfomant if mocking / phase too big.

### Google Test (gtest)

The following are to do only once, after installed the package via **apt**.
After installing gtest on WSL2, Ubuntu, Debian, I must build the project :

```bash
	cd /usr/src/googletest
	sudo cmake .
	sudo make
```

Then copy the **libraries.a** generated in **local**/lib and **headers** in **local**/include directory to reuse them directly in my C++ projects.

```bash
	sudo cp lib/*.a /usr/local/lib
	sudo cp -r googletest/include/gtest /usr/local/include
```

