# 📟 Calculax - Questions

### What C libraries are needed for Mac? For Linux?

In order to provide interaction through the Terminal, I am using the `ncurses` library. This library was developed in 1993 and allows to build _GUI-like_ applications running under terminal emulators.

`ncurses` can be installed through `apt-get` and `homebrew` package managers, respectively for Linux and Mac systems.


### How to control the set of words that may be completed with [TAB]?

All variables are stored in memory in using a **Linked List**. However this data structure is not optimal for auto-completion of variable names.

We are also using the **Trie** data structure, which is a big tree that allows for search matching terms within a set. Every node represents a character. Each branch represents a possible word. Nodes have multiple branches (as many as there are letters in the alphabet).

Searching in the **Trie** structure can be achieved in `O(M)` time, with `M` being the maximal length of a string.

<p align="center">
    <img src="Trie.png" width="300" alt="Trie Data Structure"/>
</p>

-  When the user adds a new variable, we add it to the **Linked List**, and insert the variable name to the **Trie**.

- When the user hits the `TAB` key for auto-completion, the last word of the complete input string is retrieved. We then search for matchings within the **tree** recursively, and store the results in a **Linked List**.

### How to create a robust script for automatically installing the program on a Mac or Linux machine?

When developping the program, I was using my own `Makefile`, by manually tweaking the flags and sources in it. But it is doubtful that this `Makefile` will run on any other Linux/Mac system.

**i.e.** in order to install and distribute the program to Linux and Mac systems, we have to build a script that will be **able to detect the compiler, and the libraries.**

A common approach for this problem is to use the `autoconf` and `automake`. Please refer to the DISTRIB.md
explanations for more details.

### In which directory is it appropriate to install the executable?

On Linux environments, programs are usually installed within the `/bin` directory.

After compiling the sources, we can either manually create a **symbolic link** to the binary in `/bin` using the `ln` command, or run the `make install` command from the generated `Makefile`..

In the `Makefile.am` file, we use the `bin` keyword to explicitely tell the futurely generated install scripts to place the binary into the `/bin` folder.