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

#include <initializer_list>
#include <cstddef>

template<typename ExpT> class earray
{
    public:
        typedef earray<ExpT>              expression_type;
        typedef typename ExpT::value_type value_type;
    private:
        ExpT _expression;
    public:
        //--------------------------------------------------------------------
        //              constructors and destructors
        //--------------------------------------------------------------------
        
        //! copy constructor
        earray(const expression_type &a):
            _expression(a._expression) 
        {}

        earray(const ExpT &e):
            _expression(e) 
        {}

        //--------------------------------------------------------------------
        //              assignment operators
        //--------------------------------------------------------------------
        //! copy assignment
        expression_type &operator=(const expression_type &a)
        {
            if(this == &a) return *this;

            _expression = a._expression;
            return *this;
        }

        //--------------------------------------------------------------------
        //              other member functions
        //--------------------------------------------------------------------
        //! get size
        size_t size() const
        {
            return _expression.size();
        }

        //! get element value
        value_type operator[](size_t index) const 
        { 
            return _expression[index]; 
        }
};








