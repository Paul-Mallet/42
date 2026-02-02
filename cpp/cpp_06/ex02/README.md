# Ex02 - Real-type

## 📝 Resume (TL;DR)

This exercise is about returning the current type of an object (Class or Class*). Because the subject forbidden to use the <> header, we must use the **dynamic_cast** instead.

## randomizer

Combination of **time** properties and **numbers range** to properly get a random number at each runtime.

### srand()

Seed randomizer, store the seed value in the internal <cstdlib> variable seed.
Works with time_t struct and time() method to get the current time values.

**Little insights** : time(NULL) = time(&rawtime), from time_t rawtime

**Warning** : Must be called only once at the beginning of main.cpp ! (if in a method, call x100 this one will not change the seed(CPU to fast))

### rand()

Randomizer function which allows us to choose the range with : <code>% 100</code> (0 to 99).
Also can add : <code>... + 5</code>, to shift the begin range by the chosen amount.

**Little insights** : time(NULL) = time(&rawtime), from time_t rawtime

## dynamic_cast<new_type>(expression)



**Remainder** :
* exception of type bad_cast is thrown on ref type convertion failure.