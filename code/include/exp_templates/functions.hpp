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

#include <type_traits>
#include "sin_op.hpp"
#include "../earray.hpp"
#include "../scalar.hpp"
#include "utils.hpp"

namespace et{

template<
         typename ArgT,
         typename = typename std::enable_if<
             std::is_same<
             typename remove_all<ArgT>::type,double>::value
             >::type
        >
earray<sin_op<scalar<typename remove_all<ArgT>::type>>> sin(ArgT arg)
{
    typedef typename remove_all<ArgT>::type arg_type;
    typedef scalar<arg_type>                scalar_type;
    typedef sin_op<scalar_type>             operation_type;
    typedef earray<operation_type>          expression_type;

    return expression_type(operation_type(scalar_type(arg)));
}

template<
         typename ArgT,
         typename = typename
             std::enable_if<!
             std::is_same<typename remove_all<ArgT>::type,double>::value
             >::type
        >
earray<sin_op<typename remove_all<ArgT>::type>> sin(ArgT arg)
{
    typedef sin_op<ArgT>          operation_type;
    typedef earray<operation_type>  expression_type;
    return expression_type(operation_type(std::forward<ArgT>(arg)));
}

//end of namespace
}



