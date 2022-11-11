# Notes about Makefiles

## Intro :
target : prerequisite1 prerequisite2 <br>
&emsp; commands <br>
<u> i.e. : </u><br>
foo.o : foo.c foo.h <br>
&emsp; gcc -c foo.c

## Automatic variables :
- $@ : filename of the target
- $< : filename of the first prerequisite
- $? : filename of all prerequisites newer than the target
- $^ : filename of all prerequisites

## Variable and macros :