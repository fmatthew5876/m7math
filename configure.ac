#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT([m7math], [0.1], [fmatthew5876@gmail.com])

AC_CONFIG_MACRO_DIR([m4])

# Use C++
AC_LANG([C++])

AC_CONFIG_SRCDIR([include/m7math/types.hh])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11 -Wall no-define foreign subdir-objects])

AC_CANONICAL_HOST
AC_CANONICAL_BUILD

#Build arguments
AC_ARG_ENABLE([debug], [AS_HELP_STRING([--enable-debug], [enable debug build (default is no)])], [M7_BUILD=$enableval], [M7_BUILD=no])
AS_IF([test "x$M7_BUILD" = "xyes"], 
      [CPPFLAGS="-DM7_DEBUG $CPPFLAGS"; CXXFLAGS="-g -O0 -pipe"],
      [CPPFLAGS="-DNDEBUG"; CXXFLAGS="-O2 -pipe"])

#Global compilation/linker flags
CXXFLAGS="--std=c++0x -Wall -fno-exceptions -fno-rtti $CXXFLAGS"

#Check endianness
AC_C_BIGENDIAN(
                [M7_BYTE_ORDER=M7_BIG_ENDIAN], 
                [M7_BYTE_ORDER=M7_LITTLE_ENDIAN], 
                [M7_BYTE_ORDER=0], 
                [M7_BYTE_ORDER=M7_LITTLE_ENDIAN])
AC_SUBST([M7_BYTE_ORDER])

#Check for features
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL
AC_PROG_RANLIB

# Checks for libraries.
PKG_PROG_PKG_CONFIG

AC_CONFIG_FILES([m7math.pc
                 Makefile
                 include/Makefile
                 include/m7math/Makefile
		 include/m7math/_internal/Makefile
                 ])

AC_SUBST(M7_DEBUG)


AC_OUTPUT
