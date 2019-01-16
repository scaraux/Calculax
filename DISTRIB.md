# Distributing the Program

The goal is to distribute the source code to the user, and provide scripts that generate a platform-independant Makefile.

## How to distribute

### 1. Create a configure.ac file:

This file gives information on how we want the `configure` script to be generated. Place the following content in it:

```
AC_INIT([calculax], [0.1], [gottingoscar@gmail.com])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
````

In other words:

1) Give information about the program
2) We want to use Automake to generate a Makefile
3) We must look for a C compiler
4) A Makefile will be generated
5) Output the files

### 2. Create a Makefile.am file

This file contains the smallest required "Makefile instructions" in order to generate the `Makefile.in`, that later will produce the final `Makefile` on the user's system. Place the following content in it:

AUTOMAKE_OPTIONS = foreign subdir-objects
bin_PROGRAMS = prog
prog_LDADD = -lncurses
prog_SOURCES = src/source.c \
               src/header.h \

In other words:

1) We set options. `subdir-object` indicated that sources
are located in a sub-directory. In my case, `/src`.
2) We provide the name of the executable. `bin_` tells that this will be a binary, rather than a library for example.
3) Linking libraries, with `LDADD` and the program name prefix i.e. `prog`
4) Pass the sources and headers

### 3. Generate the configure script

Run the following commands:

```
$ aclocal
$ autoconf
$ automake -a -c
```

### 4. Distribute

You can now share the directory to users. Don't forget to remove the `autom4te.cache` directory.

### 5. Installing the project (on user's system)

The user will run the following commands:

```
$ ./configure
$ make
$ sudo make install
```

He can now run you program since it has been installed to /bin.