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
//! \ingroup expression_templates
//! \brief cosine operation
//!
//! Unary operation computing the cosine on every element of its argument.
//!
//! \tparam ArgT argument type
template<typename ArgT> class cos_op
{
    public:
        //! argument type 
        typedef typename remove_all<ArgT>::type    argument_type;
        //! reference type used to store the argument
        typedef typename get_reference<ArgT>::type reference_type;
        //! value type of the argument and thus of the operatoin
        typedef typename argument_type::value_type value_type;
        //! the total expression tpye
        typedef cos_op<ArgT>                       expression_type;
    private:
        //! 'reference' to the argument
        reference_type _arg;
    public:
        //! constructor
        cos_op(ArgT arg):
            _arg(arg) 
        { }

        //--------------------------------------------------------------------
        //! constructor
        cos_op(const expression_type &e):
            _arg(e._arg) 
        {}

        //--------------------------------------------------------------------
        //! return size
        size_t size() const 
        { 
            return _arg.size(); 
        } 

        //--------------------------------------------------------------------
        //! return computation result
        value_type operator[](size_t index) const
        {
            return std::cos(_arg[index]);
        }
};
