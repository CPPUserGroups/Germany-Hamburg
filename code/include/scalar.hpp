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

template<typename T> class scalar
{
    public:
        typedef T value_type;
        typedef scalar<value_type> scalar_type;
    private:
        T _value;
    public:
        //--------------------------------------------------------------------
        //              constructors and destructors
        //--------------------------------------------------------------------
        scalar(T value):_value(value) {}

        //--------------------------------------------------------------------
        scalar(const scalar_type &s):_value(s._value) {}

        //--------------------------------------------------------------------
        scalar(scalar_type &&s):_value(s._value) {}

        //--------------------------------------------------------------------
        //              conversion operator
        //--------------------------------------------------------------------
        operator T() const
        {
            return _value;
        }
        
        //--------------------------------------------------------------------
        //              assignment operators
        //--------------------------------------------------------------------
        //! copy assignment
        scalar_type &operator=(const scalar_type &a)
        {
            if(this == &a) return *this;

            _value = a._value;
            return *this;
        }

        //--------------------------------------------------------------------
        //              other member functions
        //--------------------------------------------------------------------
        //! get size
        size_t size() const 
        { 
            return 1; 
        }

        //--------------------------------------------------------------------
        //! get element value
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
        value_type operator[](size_t index) const 
        { 
            return _value; 
        }
#pragma GCC diagnostic pop
};








