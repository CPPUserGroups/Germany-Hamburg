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

#include <talk/motor.hpp>


namespace talk{

    motor::motor():
        _upper_limit(0.0),
        _lower_limit(0.0)
    {}

    //-------------------------------------------------------------------------
    motor::motor(double llimit,double ulimit):
        _upper_limit(ulimit),
        _lower_limit(llimit)
    {}

    //-------------------------------------------------------------------------
    motor::~motor()
    {}

    //-------------------------------------------------------------------------
    double motor::get_position() const
    {
        return 0.0;
    }

    //-------------------------------------------------------------------------
    void motor::set_position(double) 
    { }

    //-------------------------------------------------------------------------
    double motor::get_upper_limit() const
    {
        return _upper_limit;
    }

    //-------------------------------------------------------------------------
    void motor::set_upper_limit(double limit)
    {
        _upper_limit = limit;
    }

    //-------------------------------------------------------------------------
    double motor::get_lower_limit() const
    {
        return _lower_limit;
    }

    //-------------------------------------------------------------------------
    void motor::set_lower_limit(double limit)
    {
        _lower_limit = limit;
    }
}

