/* put.c -- Convex hull of two intervals.

Copyright 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2010,
                     Spaces project, Inria Lorraine
                     and Salsa project, INRIA Rocquencourt,
                     and Arenaire project, Inria Rhone-Alpes, France
                     and Lab. ANO, USTL (Univ. of Lille),  France

This file is part of the MPFI Library.

The MPFI Library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version.

The MPFI Library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
License for more details.

You should have received a copy of the GNU Lesser General Public License
along with the MPFI Library; see the file COPYING.LIB.  If not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
MA 02110-1301, USA. */

#include "mpfi-impl.h"

/* The result is the first interval extended so */
/* that it contains the second (scalar) one.    */
/* Also called "convex hull".                   */

int
mpfi_put (mpfi_ptr a, mpfi_srcptr b)
{
  int inexact_left = 0;
  int inexact_right=0;
  int inexact=0;

  if ( MPFI_NAN_P (b) ) {
    mpfr_set_nan (&(a->left));
    mpfr_set_nan (&(a->right));
    MPFR_RET_NAN;
  }
  if ( MPFI_NAN_P (a) )
    MPFR_RET_NAN;

  if ( mpfr_cmp (&(a->left), &(b->left)) > 0 ) {
    inexact_left = mpfr_set (&(a->left), &(b->left), MPFI_RNDD);
  }
  if (mpfr_cmp (&(a->right), &(b->right)) < 0) {
    inexact_right = mpfr_set (&(a->right), &(b->right), MPFI_RNDU);
  }
  if (inexact_left)
    inexact += 1;
  if (inexact_right)
    inexact += 2;

  return inexact;
}
