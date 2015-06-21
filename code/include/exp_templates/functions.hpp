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

#include <iostream>
#include <type_traits>
#include "sin_op.hpp"
#include "cos_op.hpp"
#include "../earray.hpp"
#include "utils.hpp"
#include <boost/current_function.hpp>

namespace et{

    //!
    //! \ingroup expression_templates
    //! \brief compute sine function
    //! 
    //! Function template returns an expression array for computing the 
    //! sine function on each of its arguments.
    //!
    //! \tparam ArgT argument type
    //! \param arg xvalue reference to the argument
    //! \return expression array to compute the sine function
    //! 
    template<typename ArgT>
    earray<sin_op<typename get_scalar<ArgT>::type>> sin(ArgT &&arg)
    {
        //std::cerr<<BOOST_CURRENT_FUNCTION<<std::endl;
        typedef typename get_scalar<ArgT>::type scalar_type;
        typedef sin_op<scalar_type> operation_type;
        typedef earray<operation_type> expression_type;

        return expression_type(operation_type(scalar_type(arg)));
    }

    //------------------------------------------------------------------------
    //! 
    //! \ingroup expression_templates
    //! \brief compute cosine function
    //! 
    //! Function template to return an expression array computing the 
    //! cosine function on each of its arguments.
    //! 
    //! \tparam ArgT argument type
    //! \param arg xvalue reference to the argument
    //! \return expression array to compute the cosine function
    //! 
    template<typename ArgT>
    earray<cos_op<typename get_scalar<ArgT>::type>> cos(ArgT &&arg)
    {
        //std::cerr<<BOOST_CURRENT_FUNCTION<<std::endl;
        typedef typename get_scalar<ArgT>::type scalar_type;
        typedef cos_op<scalar_type> operation_type;
        typedef earray<operation_type> expression_type;

        return expression_type(operation_type(scalar_type(arg)));
    }
//end of namespace
}



