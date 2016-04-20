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
#include <boost/python/stl_iterator.hpp>
#include <string>
#include <talk/sensor.hpp>
#include <talk/device.hpp>
#include <talk/state.hpp>

using namespace boost::python;


dict create_sensors(list names)
{
    using iterator_type = stl_input_iterator<std::string>;
    dict sensors;

    iterator_type names_begin(names);
    iterator_type names_end;

    for(;names_begin!=names_end;++names_begin)
    {
        sensors[*names_begin] = talk::sensor(0.0);
    }

    return sensors;
}

BOOST_PYTHON_MODULE(sensor)
{
    object class_sensor = class_<talk::sensor>("Sensor")
        .def(init<double>())
        .def("get_value",&talk::sensor::get_value)
        .def("set_value",&talk::sensor::set_value)
        .add_property("value",&talk::sensor::get_value,
                          &talk::sensor::set_value); 

    object s2 = class_sensor(2.3);


    class_<talk::device>("Device",no_init)
        .def("get_value",&talk::device::get_value)
        .def("set_value",&talk::device::set_value)
        .add_property("value",&talk::device::get_value,
                          &talk::device::set_value); 

    /*
    def("create_device",talk::create_device,
                        return_internal_reference<1>());
                       */

    def("create_sensors",create_sensors);

    enum_<talk::system_state>("system_state")
        .value("ONLINE",talk::system_state::ONLINE)
        .value("OFFLINE",talk::system_state::OFFLINE);
}

