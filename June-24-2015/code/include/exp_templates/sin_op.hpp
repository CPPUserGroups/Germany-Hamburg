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
//! \ingroup expression_template
//! \brief sin operation
//!
//! Unary operation computing the sin on every element of its argument.
//! The argument type can be either an rvalue or lvalue reference.
//!
//! \tparam ArgT argument type
template<typename ArgT> class sin_op
{
    public:
        //! argument type 
        typedef typename remove_all<ArgT>::type    argument_type;
        //! reference type used to store the argument
        typedef typename get_reference<ArgT>::type reference_type;
        //! value type of the argument and thus of the operatoin
        typedef typename argument_type::value_type value_type;
        //! the total expression tpye
        typedef sin_op<ArgT>                       expression_type;
    private:
        //! 'reference' to the argument
        reference_type _arg;
    public:
        //! constructor
        sin_op(ArgT arg):
            _arg(arg) 
        { }

        //--------------------------------------------------------------------
        sin_op(const expression_type &e):
            _arg(e._arg) 
        {}

        //--------------------------------------------------------------------
        size_t size() const 
        { 
            return _arg.size(); 
        } 

        //--------------------------------------------------------------------
        value_type operator[](size_t index) const
        {
            return std::sin(_arg[index]);
        }
};
