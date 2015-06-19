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
#include <cassert>
#include "earray.hpp"

template<typename StorageT> class narray
{
    public:
        typedef narray<StorageT> array_type;
        typedef typename StorageT::value_type value_type;
    private:
        StorageT _storage;
    public:
        //--------------------------------------------------------------------
        //              constructors and destructors
        //--------------------------------------------------------------------
        //! default constructor
        narray():_storage() {}

        //! constructor
        narray(size_t n):_storage(n) {}
        
        //! copy constructor
        narray(const array_type &a):_storage(a._storage) {}

        //! move constructor
        narray(array_type &&a):
            _storage(std::move(a._storage))
        {}

        //! initializer list constructor
        narray(const std::initializer_list<value_type> &ilist):
            _storage(ilist)
        {}

        //! construct from an earray
        template<typename ArgT>
        narray(const earray<ArgT> &expression):
            _storage(expression.size())
        {
            size_t s = _storage.size();
            for(size_t index=0;index<s;++index)
                _storage[index] = expression[index];
        }

        //--------------------------------------------------------------------
        // conversion operator
        //--------------------------------------------------------------------
        operator earray<array_type> () const
        {
            return earray<array_type>(*this);
        }

        //--------------------------------------------------------------------
        //              assignment operators
        //--------------------------------------------------------------------
        //! copy assignment
        array_type &operator=(const array_type &a)
        {
            if(this == &a) return *this;

            _storage = a._storage;
            return *this;
        }

        //! move assignment
        array_type &operator=(array_type &&a)
        {
            if(this == &a) return *this;

            std::swap(_storage,a._storage);
            return *this;
        }
        
        //! assignment from an earray
        template<typename ArgT> 
        array_type &operator=(const earray<ArgT> &expression) 
        {
            assert(size() == expression.size());

            size_t s = size();
            for(size_t index = 0;index<s;++index)
                (*this)[index] = expression[index];

            return *this;
        }
        
        //--------------------------------------------------------------------
        //              other member functions
        //--------------------------------------------------------------------
        //! get size
        size_t size() const
        {
            return _storage.size();
        }

        //! get reference to element
        value_type &operator[](size_t index) { return _storage[index]; }

        //! get element value
        value_type operator[](size_t index) const { return _storage[index]; }
};








