# ex00 - BitcoinExchange

...

## How to run ?

Create/import a **data.csv** or **data/data.csv** file with the following structure :

```text
date,exchange_rate
2009-01-02,0
2009-01-05,0
2009-01-08,0
...
[not > 4bn lines will be accepted]
```

**Important** : The file must not contain extra noises (chars, leading 0, etc.), because no parser have been implemented for the exercise.

Then create an **input.txt** file with the following structure :
```text
date | value
2009-11-21 | 1
2010-08-20 | 11
...
[not > 4bn lines will be accepted]
```


```bash
	make
	make doc
	make test
	make debug
	make clean
	make fclean
	make re
```

## Sources

[]()