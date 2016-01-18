//
// (c) Copyright <YEAR> Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of <PROJECT>.
//
// <PROJECT> is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// <PROJECT> is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with <PROJECT>.  If not, see <http://www.gnu.org/licenses/>.
// 
// ===========================================================================
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Testing base class moveable

#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <talk/motor.hpp>

using namespace talk;

BOOST_AUTO_TEST_SUITE(motor_test)

    BOOST_AUTO_TEST_CASE(default_construction)
    {
        motor m;
        BOOST_CHECK_CLOSE_FRACTION(m.get_upper_limit(),0.0,1.e-12);
        BOOST_CHECK_CLOSE_FRACTION(m.get_lower_limit(),0.0,1.e-12);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(standard_construction)
    {
        motor m(-4.3,50.23);
        BOOST_CHECK_CLOSE_FRACTION(m.get_upper_limit(),50.23,1.e-12);
        BOOST_CHECK_CLOSE_FRACTION(m.get_lower_limit(),-4.3,1.e-12);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_construction)
    {
        motor m1(-39.2,23.1);
        motor m2(m1);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_upper_limit(),
                                   m1.get_upper_limit(),1.e-12);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_lower_limit(),
                                   m1.get_lower_limit(),1.e-12);
    }
    
    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_assignment)
    {
        motor m1(-90,90);
        motor m2;

        m2 = m1;
        BOOST_CHECK_CLOSE_FRACTION(m2.get_upper_limit(),
                                   m1.get_upper_limit(),1.e-12);
        BOOST_CHECK_CLOSE_FRACTION(m2.get_lower_limit(),
                                   m1.get_lower_limit(),1.e-12);
    }
    
    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(set_upper_limit)
    {
        motor m;
        m.set_upper_limit(100.2);
        BOOST_CHECK_CLOSE_FRACTION(m.get_upper_limit(),100.2,1.e-12);
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(set_lower_limit)
    {
        motor m;
        m.set_lower_limit(100.2);
        BOOST_CHECK_CLOSE_FRACTION(m.get_lower_limit(),100.2,1.e-12);
    }


BOOST_AUTO_TEST_SUITE_END()
