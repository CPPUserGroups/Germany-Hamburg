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

#include "../scalar.hpp"

//!
//! \ingroup exp_temp_utilities
//! \brief remove reference and const-nes
//! 
//! Removes reference and constnes from a given template parameter.
//!
template<typename T>
using remove_all = std::remove_reference<
                   typename std::remove_const<T>::type  
                   >;

//----------------------------------------------------------------------------
//!
//! \ingroup exp_temp_utilities
//! \brief get the reference type for an argument
//! 
template<typename T>
using get_reference = std::conditional<std::is_lvalue_reference<T>::value,
                                       const typename remove_all<T>::type &,
                                       typename remove_all<T>::type>;

//----------------------------------------------------------------------------
//! 
//! \ingroup exp_temp_utilities
//! \brief determine scalar type
//! 
//! This template indicates whether or not an argument type referes to a
//! scalar type. Currently only double values are considered scalars. 
//! This might be changed in future to include other types (using MPL).
//! 
//! \tparam ArgT argument type
//! 
template<typename ArgT>
using is_scalar = std::is_same<typename remove_all<ArgT>::type,double>;

//----------------------------------------------------------------------------
//!
//! \ingroup exp_temp_utilites
//! \brief return scalar type for an argument
//! 
//! If ArgT refers to a scalar type an instance of the scalar template is 
//! returned. Otherwise the original type is returned.
//! 
//! \tparam ArgT argument type
//! 
template<typename ArgT>
using get_scalar = std::conditional<is_scalar<ArgT>::value,
                                    scalar<typename remove_all<ArgT>::type>,
                                    ArgT>;
