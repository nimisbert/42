# 42

## Summary 

Answers to the questions of my universe and anything...  
Well, my global aim is to create an unified dynamic system modeling program in Haskell.  
There are also other topics, like cryptography and electronics hardware, that I may develop along the way to this so called unified dynamic systems modeler.

## Folders 

| folder       | description            |
|:------------:|:-----------------------|
| [HW](./HW)   | Hardware development   |
| [SW](./SW)   | Software development   |

## Books

- ![50%](https://progress-bar.dev/50) Loudon Kyle, _Mastering algorithm with C_, __O'REILLY__, April 2002 
- ![100%](https://progress-bar.dev/100) Mecklenburg Robert, _Managing Projects with GNU Make_, __O'REILLY__, November 2004
- ![50%](https://progress-bar.dev/50) Lipovača Miran, _Learn You a Haskell for Great Good!_, __No Starch Press__, 2011
- ![100%](https://progress-bar.dev/100) B. Mark, _64-bit assembly programming for Linux_, __Sharanych Media__, 2020
- ![02%](https://progress-bar.dev/02) P. Horowitz & W. Hill, _The Art of Electronics_, __Cambridge University Press__, 2015
- ![08%](https://progress-bar.dev/08) S. Dusausay, _L'Electronique par la simulation_, 2023
- ![00%](https://progress-bar.dev/00) Jon B. Hagen, _Radio Frequency Electronics_, __Cambridge University Press__, 2009

## Projects

- ![80%](https://progress-bar.dev/80) Cryptography Algorithms in C
- ![02%](https://progress-bar.dev/02) Biologic dynamic systems modeler in Haskell
- ![00%](https://progress-bar.dev/00) Electronic circuits modeler in C
- ![00%](https://progress-bar.dev/00) Unified systems modeler in Haskell

## Roadmap

```mermaid
flowchart TB
classDef blue fill:#2374f7,stroke:#000,stroke-width:2px,color:#fff
classDef orange fill:#fc822b,stroke:#000,stroke-width:2px,color:#fff

B1(The art of electronics):::blue 
B2(Electronique par la simulation):::blue
B3(Radio frequency electronics):::blue
B4(Mastering algorithm with C):::blue
B5(CGP Math):::blue
B6(Learn you a Haskell for great good!):::blue

O1(LTspice reference simulations):::orange
O2(C based circuits modeler):::orange
O3(Biologic dynamic systems modeler):::orange
O4(Unified dynamic system modeler in Haskell):::orange
O5(Cryptography in C):::orange

B1 ---> B2 & O1
B2 ---> B3 & O1
B3 ---> O1
O1 ---> O2
B3 ---> O2
B4 ---> O2
B5 ---> O3
B6 ---> O3
O3 ---> O4
O2 ---> O4
B4 ---> O5
```