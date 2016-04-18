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

#include <talk/device.hpp>


namespace talk{

    //------------------------------------------------------------------------
    device::device(sensor *s):
        _sensor(s)
    { }

    //------------------------------------------------------------------------
    double device::get_value() const
    {
        return _sensor->get_value();
    }

    //------------------------------------------------------------------------
    void device::set_value(double v)
    {
        _sensor->set_value(v);
    }

    device create_device(sensor *s)
    {
        return device(s);
    }
}
