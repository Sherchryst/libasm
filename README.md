# Libasm
L’objectif de ce projet est de devnir familier avec le langage assembleur.
__Libasm__ est un _projet individuel de l'école 42_ où nous devons recoder quelque fonction de la libc en langage d'assembleur.

The goal of this project is to become familiar with assembly language.
__Libasm__ is an _individual project at 42_ where we have to recode some function of the libc in assembly language.

## What is assembly ?
Le langage assembleur, souvent appellé asm, est un langage de bas niveau pour ordinateur - ou autre machine programmable - qui possède une très forte correspondance
entre le langage et l’architecture de la machine.

Assembly language, often referred to as asm, is a low-level language for a computer - or other programmable machine - which has a very strong correspondence
between language and machine architecture.

### Prerequisites

To run this project on your computer check to have [nasm](https://en.wikipedia.org/wiki/Netwide_Assembler).

The __makefile__ compiles the .s (assembler file) with _nasm -f elf64_, if you use an OS other than Ubuntu 20.04.2 LTS 64 bits, you will have to change the compilation of NAFLAGS in the makefile.

```
For Windows NASMFLAGS: -f win64
For Linux NASMFLAGS: -f elf64
For Mac OS NASMFLAGS: -f macho64
```

### Running the tests

To __test the project__ write the following commands in your terminal:

1. ```make bonus```
2. ```./test.sh```

- __make bonus__: _compile assembly files in .o and create a library named libasm.a_
- __./test.sh__: _compile main.c with the libasm.a library_ & _launches tests to compare libasm to libc_

