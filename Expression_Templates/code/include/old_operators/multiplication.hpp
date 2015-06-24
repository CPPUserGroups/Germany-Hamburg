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

#include "../narray.hpp"

//----------------------------------------------------------------------------
//! 
//! \ingroup old_style_operators 
//! \brief multiplication operator 
//! 
//! This version of the multiplication operator is used for situations where 
//! the LHS and the RHS of the operator are instances of narray.  The 
//! operator computes
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = \mathbf{a}_i\times\mathbf{b}_i
\f]
*/ 
//! 
//! \tparam StorageT storage type for the narray
//! \param lhs reference to the LHS array
//! \param rhs reference to the RHS array
//! \return narray instance with the result
//!
template<typename StorageT>
narray<StorageT> operator*(const narray<StorageT> &lhs,
                           const narray<StorageT> &rhs)
{
    narray<StorageT> temp(lhs);
    size_t size = lhs.size();

    for(size_t index=0;index<size;++index)
        temp[index] *= rhs[index];

    return temp;
}

//----------------------------------------------------------------------------
//! 
//! \ingroup old_style_operators
//! \brief multiplication operator
//! 
//! Overload of the multiplication operator where the LHS of the * operation is an 
//! instance of narray and the RHS is a scalar. The operator computes
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = s\times\mathbf{b}_i
\f]
*/
//!
//! \tparam StorageT storage type of the narray instance
//! \param lhs reference to the array on the LHS
//! \param rhs scalar value on the RHS of the operator
//! \return narray instance with the result
//!
template<typename StorageT>
narray<StorageT> operator*(const narray<StorageT> &lhs,
                           typename StorageT::value_type rhs)
{
    narray<StorageT> temp(lhs);
    size_t size = lhs.size();

    for(size_t index=0;index<size;index++)
        temp[index] *= rhs;

    return temp;
}

//----------------------------------------------------------------------------
//!
//! \ingroup old_style_operators
//! \brief multiplication operator
//! 
//! Overload of the multiplication operator where the LHS of the * operation is 
//! a scalar value and the RHS an instance of narray. The operator computes
/*!
\f[
  \forall i\in\{0\dots N-1\}:  \mathbf{r}_i = \mathbf{a}_i\times s
\f]
*/ 
//! 
//! \tparam StorageT storage type of the narray instance
//! \param lhs scalar value on the LHS of the operator
//! \param rhs reference to the narray instance on the RHS of the operator
//! \return narray instance with the result of the operation
//!
template<typename StorageT>
narray<StorageT> operator*(typename StorageT::value_type lhs,
                           const narray<StorageT> &rhs)
{
    return rhs*lhs;
}
