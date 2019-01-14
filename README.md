# Calculax

<p align="center">
    <img src="https://media.giphy.com/media/UvOaWabxo1enu/giphy.gif" width="300" alt="Header"/>
</p>

Calculax is a simple C program acting as a interpreter

## Prerequisites

Calculax has been made in C, and uses the [ncurses](https://www.gnu.org/software/ncurses/ncurses.html) library.

## Install

```
$ ./configure
$ make
$ make install
```

## Usage


```
> 42 + 42
> 84
```

```
> life = 42
> success!

> life + 12
> 43
```

Use `TAB` key for auto-completion of variable names

```
> li+[TAB]
```
becomes
```
> life
```

Use the keyboard arrow UP and DOWN to navigate through history