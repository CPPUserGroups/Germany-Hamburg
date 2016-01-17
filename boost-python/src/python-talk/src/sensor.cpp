//
// (c) Copyright 2016 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of python-talk.
//
// python-talk is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// python-talk is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with python-talk.  If not, see <http://www.gnu.org/licenses/>.
// ===========================================================================

#include <boost/python.hpp>
#include <talk/sensor.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(sensor)
{
    class_<talk::sensor>("Sensor")
        .def(init<>())
        .def(init<double>())
        .def("get_value",&talk::sensor::get_value)
        .def("set_value",&talk::sensor::set_value)
        .add_property("value",&talk::sensor::get_value,
                          &talk::sensor::set_value); 
}

