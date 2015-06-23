//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of Expression Templates Talk.
//
// Expression templates talk is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or (at your
// option) any later version.
//
// Expression Tempaltes Talks  is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Expression Templates Talk.  If not, see <http://www.gnu.org/licenses/>.
//
// ===========================================================================
#pragma once

#include <cstdlib>
#include <cmath>
#include "../narray.hpp"

//----------------------------------------------------------------------------
//! 
//! \ingroup old_style_operators 
//! \brief sin function
//! 
//! Overload of the sin() function for instances of narray
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = \sin\left(\mathbf{a}_i\right)
\f]
*/ 
//! 
//! \tparam StorageT storage type for the narray
//! \param lhs reference to the LHS array
//! \param rhs reference to the RHS array
//! \return narray instance with the result
//!
template<typename StorageT>
narray<StorageT> sin(const narray<StorageT> &arg)
{
    size_t size = arg.size();
    narray<StorageT> temp(size);

    for(size_t index=0;index<size;++index) temp[index] = std::sin(arg[index]);

    return temp;
}

//----------------------------------------------------------------------------
//! 
//! \ingroup old_style_operators 
//! \brief cos function
//! 
//! Overload of the cos() function for instances of narray
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = \cos\left(\mathbf{a}_i\right)
\f]
*/ 
//! 
//! \tparam StorageT storage type for the narray
//! \param lhs reference to the LHS array
//! \param rhs reference to the RHS array
//! \return narray instance with the result
//!
template<typename StorageT>
narray<StorageT> cos(const narray<StorageT> &arg)
{
    size_t size = arg.size();
    narray<StorageT> temp(size);

    for(size_t index=0;index<size;++index) temp[index] = std::cos(arg[index]);

    return temp;
}
//----------------------------------------------------------------------------
//! 
//! \ingroup old_style_operators 
//! \brief exp function
//! 
//! Overload of the exp() function for instances of narray
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = \exp\left(\mathbf{a}_i\right)
\f]
*/ 
//! 
//! \tparam StorageT storage type for the narray
//! \param lhs reference to the LHS array
//! \param rhs reference to the RHS array
//! \return narray instance with the result
//!
template<typename StorageT>
narray<StorageT> exp(const narray<StorageT> &arg)
{
    size_t size = arg.size();
    narray<StorageT> temp(size);

    for(size_t index=0;index<size;++index) temp[index] = std::exp(arg[index]);

    return temp;
}
