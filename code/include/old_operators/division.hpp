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

#include "../narray.hpp"

//----------------------------------------------------------------------------
template<typename StorageT>
narray<StorageT> operator/(const narray<StorageT> &lhs,
                           const narray<StorageT> &rhs)
{
    narray<StorageT> temp(lhs);
    size_t size = lhs.size();

    for(size_t index=0;index<size;++index)
        temp[index] /= rhs[index];

    return temp;
}

//----------------------------------------------------------------------------
template<typename StorageT>
narray<StorageT> operator/(const narray<StorageT> &lhs,
                           typename StorageT::value_type rhs)
{
    narray<StorageT> temp(lhs);
    size_t size = lhs.size();

    for(size_t index=0;index<size;index++)
        temp[index] /= rhs;

    return temp;
}

//----------------------------------------------------------------------------
template<typename StorageT>
narray<StorageT> operator/(typename StorageT::value_type lhs,
                           const narray<StorageT> &rhs)
{
    size_t size = rhs.size();
    narray<StorageT> temp(rhs);

    for(size_t index=0;index<size;index++)
        temp[index] = lhs/temp[index];

    return temp;
}
