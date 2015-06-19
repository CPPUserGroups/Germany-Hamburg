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

#include "utils.hpp"

//!
//! \brief binary add operation
//!
//! Binary addition operation operation computing the sin on every element of
//! its argument. The argument type can be either an rvalue or lvalue
//! reference.
//!
//! \tparam ArgTLHS argument type left handside
//! \tparam ArgTRHS argument type right handside
template<
         typename ArgTLHS,
         typename ArgTRHS
        > 
class add_op
{
    public:
        //! argument type 
        //! reference type used to store the argument
        typedef typename get_reference<ArgTLHS>::type ref_type_lhs;
        typedef typename get_reference<ArgTRHS>::type ref_type_rhs;
        //! value type of the argument and thus of the operatoin
        typedef typename remove_all<ArgTLHS>::type::value_type value_type;
        //! the total expression tpye
        typedef add_op<ArgTLHS,ArgTRHS>                expression_type;
    private:
        //! 'reference' to the argument
        ref_type_lhs _lhs;
        ref_type_rhs _rhs;
    public:
        //! constructor
        add_op(ArgTLHS lhs,ArgTRHS rhs):
            _lhs(lhs),
            _rhs(rhs)
        { }

        //--------------------------------------------------------------------
        add_op(const expression_type &e):
            _lhs(e._lhs),
            _rhs(e._rhs)
        {}

        //--------------------------------------------------------------------
        size_t size() const 
        { 
            return std::max(_lhs.size(),_rhs.size());
        } 

        //--------------------------------------------------------------------
        value_type operator[](size_t index) const
        {
            return _lhs[index]+_rhs[index];
        }
};
