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

#include "add_op.hpp"
#include "sub_op.hpp"
#include "utils.hpp"

namespace et
{
    //------------------------------------------------------------------------
    template<
             typename ArgTLHS,
             typename ArgTRHS
            >
    earray<add_op<typename get_scalar<ArgTLHS>::type,
                  typename get_scalar<ArgTRHS>::type>>
    operator+(ArgTLHS &&lhs,ArgTRHS &&rhs)
    {
        typedef typename get_scalar<ArgTLHS>::type lhs_type;
        typedef typename get_scalar<ArgTRHS>::type rhs_type;

        typedef add_op<lhs_type,rhs_type> operation_type;
        typedef earray<operation_type> expression_type;

        return expression_type(operation_type(lhs_type(lhs),rhs_type(rhs)));
    }
    
    //------------------------------------------------------------------------
    template<
             typename ArgTLHS,
             typename ArgTRHS
            >
    earray<sub_op<typename get_scalar<ArgTLHS>::type,
                  typename get_scalar<ArgTRHS>::type>>
    operator-(ArgTLHS &&lhs,ArgTRHS &&rhs)
    {
        typedef typename get_scalar<ArgTLHS>::type lhs_type;
        typedef typename get_scalar<ArgTRHS>::type rhs_type;

        typedef sub_op<lhs_type,rhs_type> operation_type;
        typedef earray<operation_type> expression_type;

        return expression_type(operation_type(lhs_type(lhs),rhs_type(rhs)));
    }
}


