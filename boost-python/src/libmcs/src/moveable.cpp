//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of libmcs.
//
// libmcs is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// libmcs is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libmcs.  If not, see <http://www.gnu.org/licenses/>.
//
// ===========================================================================

#include <mcs/moveable.hpp>


namespace mcs{

     
    moveable::moveable():
        _name(),
        _unit()
    {}

    //------------------------------------------------------------------------
    moveable::moveable(const std::string &n,const std::string &u):
        _name(n),
        _unit(u)
    {}

    //------------------------------------------------------------------------
    std::string moveable::name() const
    {
        return _name;
    }
    
    //------------------------------------------------------------------------
    void moveable::name(const std::string &n)
    {
        _name = n;
    }

    //------------------------------------------------------------------------
    std::string moveable::unit() const
    {
        return _unit;
    }
    
    //------------------------------------------------------------------------
    void moveable::unit(const std::string &u)
    {
        _unit = u;
    }


}

