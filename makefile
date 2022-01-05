di:			dice/di.c
	gcc -o di dice/di.c

e2t:		tut/e2t.c tut/isVowel.c
	gcc -o eng2tut tut/e2t.c tut/isVowel.c

t2e:		tut/t2e.c tut/isVowel.c
	gcc -o tut2eng tut/t2e.c tut/isVowel.c

multiBank:	multiBank.c
	gcc -o multiBank multiBank.c

bank:		bank.c
	gcc -o bank bank.c

total:		total.c
	gcc -o total total.c
	
lightspeed:	lightspeed.c
	gcc -o lightspeed lightspeed.c

hello:		hello.c
	gcc -o hello hello.c

clean:
	rm hello total bank multiBank tut2eng eng2tut di lightspeed
