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
#include <talk/motor.hpp>
#include <talk/step_motor.hpp>

using namespace boost::python;

BOOST_PYTHON_MODULE(motors)
{
    class_<talk::motor>("Motor")
        .def(init<>())
        .def(init<double,double>())
        .add_property("upper_limit",&talk::motor::get_upper_limit,
                                    &talk::motor::set_upper_limit)
        .add_property("lower_limit",&talk::motor::get_lower_limit,
                                    &talk::motor::set_lower_limit)
        .add_property("position",&talk::motor::get_position);
                       

    class_<talk::step_motor,bases<talk::motor>>("StepMotor")
        .def(init<>())
        .def(init<double,double,double,double>())
        .add_property("step_size",&talk::step_motor::get_step_size,
                                  &talk::step_motor::set_step_size)
        .add_property("position",&talk::step_motor::get_position,
                                 &talk::step_motor::set_position);
}

