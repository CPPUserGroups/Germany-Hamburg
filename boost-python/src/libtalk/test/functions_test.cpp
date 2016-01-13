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
#define BOOST_TEST_MODULE Testing functions

#include <boost/test/unit_test.hpp>
#include <talk/functions.hpp>
#include <talk/exceptions.hpp>

using namespace talk;

#define NUMPREC 1.e-16

BOOST_AUTO_TEST_SUITE(functions_test)

    BOOST_AUTO_TEST_CASE(test_div)
    {
        BOOST_CHECK_CLOSE_FRACTION(2.0,div(4.0,2.0),NUMPREC);
        BOOST_CHECK_CLOSE_FRACTION(-4.0,div(-16.0,4.0),NUMPREC);
        BOOST_CHECK_CLOSE_FRACTION(-8.0,div(24.0,-3.0),NUMPREC);

        BOOST_CHECK_THROW(div(3.0,0.0),division_by_zero);
    }

    BOOST_AUTO_TEST_CASE(test_integer_add)
    {
        BOOST_CHECK_EQUAL(4,add(2,2));
        BOOST_CHECK_EQUAL(-5,add(5,-10));
        BOOST_CHECK_EQUAL(4,add(-6,10));
    }

    BOOST_AUTO_TEST_CASE(test_double_add)
    {
        BOOST_CHECK_CLOSE_FRACTION(4.0,add(2.0,2.0),NUMPREC);
        BOOST_CHECK_CLOSE_FRACTION(-5.0,add(5.0,-10.0),NUMPREC);
        BOOST_CHECK_CLOSE_FRACTION(4.0,add(-6.0,10.0),NUMPREC);
    }

BOOST_AUTO_TEST_SUITE_END()
