//
// (c) Copyright 2016 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of libtalk.
//
// libtalk is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// libtalk is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libtalk.  If not, see <http://www.gnu.org/licenses/>.
// 
// ===========================================================================
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Testing device

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <talk/device.hpp>

using namespace talk;

BOOST_AUTO_TEST_SUITE(device_test)

    BOOST_AUTO_TEST_CASE(test_constructor)
    {
        device d(new sensor(1.43));
        BOOST_CHECK_CLOSE_FRACTION(d.get_value(),1.43,1.e-10);
    }

    BOOST_AUTO_TEST_CASE(test_set_value)
    {
       // sensor s;
        //s.set_value(4.32);
        //BOOST_CHECK_CLOSE_FRACTION(s.get_value(),4.32,1.e-10);
    }

BOOST_AUTO_TEST_SUITE_END()
