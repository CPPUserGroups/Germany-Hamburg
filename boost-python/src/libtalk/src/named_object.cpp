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

#include <mcs/named_object.hpp>

namespace mcs{

    named_object::named_object():
        _name(),
        _unit()
    {}

    //------------------------------------------------------------------------
    named_object::named_object(const std::string &n,const std::string &u):
        _name(n),
        _unit(u)
    { }

    //------------------------------------------------------------------------
    named_object::named_object(const named_object &o):
        _name(o._name),
        _unit(o._unit)
    {}

    //------------------------------------------------------------------------
    named_object::named_object(named_object &&o):
        _name(std::move(o._name)),
        _unit(std::move(o._unit))
    {}

    //------------------------------------------------------------------------
    named_object::~named_object()
    {}

    //------------------------------------------------------------------------
    named_object &named_object::operator=(const named_object &o)
    {
        if(&o == this) return *this;

        _name = o._name;
        _unit = o._unit;
        return *this;
    }

    //------------------------------------------------------------------------
    named_object &named_object::operator=(named_object &&o)
    {
        if(&o == this) return *this;

        _name = std::move(o._name);
        _unit = std::move(o._unit);
        return *this;
    }

    //------------------------------------------------------------------------
    std::string named_object::name() const
    {
        return _name;
    }

    //------------------------------------------------------------------------
    void named_object::name(const std::string &n)
    {
        _name = n;
    }

    //------------------------------------------------------------------------
    std::string named_object::unit() const
    {
        return _unit;
    }

    //------------------------------------------------------------------------
    void named_object::unit(const std::string &u)
    {
        _unit = u;
    }

}
