# Cryptography in C

Exploration of the topic of cryptography in C.

## Notations 

Based on Michel Dubois' [thesis](https://hal.science/tel-01799562v1).

- S = { P, C, K, E, D } a cryptography system
- P = the Set of all cleartext
- C = the Set of all ciphertext
- K = the Set of all keys
- E = the Set of all cipher functions 
- D = the Set of all decipher functions 
- A = alphabet

## Sources 

* [Polybius Square, Michel Dubois (2017)](https://hal.science/tel-01799562v1)
* [Scytale](https://fr.wikipedia.org/wiki/Scytale)
* [AES FIPS 197, N.I.S.T. (2001)](https://csrc.nist.gov/publications/detail/fips/197/final)
* [Galois Field Multiplication, Dr. Lawlor](https://www.cs.uaf.edu/2015/spring/cs463/lecture/03_23_AES.html)
## Content 

| Algorithm        | Date   | Done   | File                                     |
|:-----------------|-------:|:------:|:----------------------------------------:|
| Scytale          | - 404  | yes    | [scytale.c](./src/scytale.c)             |
| Polybius Square  | - 150  | yes    | [polybius.c](./src/polybius.c)           |
| Caesar           | - 128  | yes    | [caesar_main.c](./examples/caesar_main.c)|
| RSA              |  1978  | no     ||
| AES              |  2001  | no     ||

## ToDo 

Multiplication and Exponentiation with AES_gf256Mul (Russian Peasant Algorithm) and AES_gf256Pow are quite meh... 
For $GF(2^m)$ multiplication is $o(m)$ and exponentiation is $o(m^2)$.