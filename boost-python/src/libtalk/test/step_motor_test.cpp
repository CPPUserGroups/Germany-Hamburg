//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of <PROJECT>.
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
#define BOOST_TEST_MODULE Testing class step_motor

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <talk/step_motor.hpp>

using namespace talk;

BOOST_AUTO_TEST_SUITE(step_motor_test)

    BOOST_AUTO_TEST_CASE(default_construction)
    {
        step_motor m;
        BOOST_CHECK_CLOSE_FRACTION(m.get_step_size(),0.0,1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m.get_position(),0.0,1.e-8);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(standard_construction)
    {
        step_motor m(0.001,12.3,-40.0,50.0);
        BOOST_CHECK_CLOSE_FRACTION(m.get_step_size(),0.001,1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m.get_position(),12.3,1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m.get_upper_limit(),50.0,1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m.get_lower_limit(),-40.0,1.e-8);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_construction)
    {
        step_motor m1(0.001,12.3,-40.0,50.0);
        step_motor m2(m1);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_step_size(),
                                   m1.get_step_size(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_position(),
                                   m1.get_position(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_upper_limit(),
                                   m1.get_upper_limit(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_lower_limit(),
                                   m1.get_lower_limit(),1.e-8);
    }


    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_assignment)
    {
        step_motor m1(0.001,12.3,-40.0,50.0);
        step_motor m2;

        m2 = m1;
        BOOST_CHECK_CLOSE_FRACTION(m2.get_step_size(),
                                   m1.get_step_size(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_position(),
                                   m1.get_position(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_upper_limit(),
                                   m1.get_upper_limit(),1.e-8);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_lower_limit(),
                                   m1.get_lower_limit(),1.e-8);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(test_set_step_size)
    {
        step_motor m;
        m.set_step_size(0.0023);
        BOOST_CHECK_CLOSE_FRACTION(m.get_step_size(),0.0023,1.e-8);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(test_set_position)
    {
        step_motor s(0.002,12.234,-40.,40.);

        s.set_position(25.23);
        BOOST_CHECK_CLOSE_FRACTION(s.get_position(),25.23,1.e-8);
    }

BOOST_AUTO_TEST_SUITE_END()
