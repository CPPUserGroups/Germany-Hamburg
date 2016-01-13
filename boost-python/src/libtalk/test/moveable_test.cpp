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
#include <mcs/moveable.hpp>

using namespace mcs;

BOOST_AUTO_TEST_SUITE(named_object_test)

    BOOST_AUTO_TEST_CASE(default_construction)
    {
        moveable o;
        BOOST_CHECK(o.name().empty());
        BOOST_CHECK(o.unit().empty());
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(standard_construction)
    {
        moveable o("motor","m");
        BOOST_CHECK_EQUAL(o.name(),"motor");
        BOOST_CHECK_EQUAL(o.unit(),"m");
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_construction)
    {
        moveable o("motor","m");
        moveable o2(o);
        BOOST_CHECK_EQUAL(o2.name(),"motor");
        BOOST_CHECK_EQUAL(o2.unit(),"m");
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(move_construction)
    {
        moveable o("motor","m");
        moveable o2(std::move(o));
        BOOST_CHECK_EQUAL(o2.name(),"motor");
        BOOST_CHECK_EQUAL(o2.unit(),"m");
        BOOST_CHECK(o.name().empty());
        BOOST_CHECK(o.unit().empty());
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(copy_assignment)
    {
        moveable o("motor","m");
        moveable o2;

        o2 = o;

        BOOST_CHECK_EQUAL(o2.name(),"motor");
        BOOST_CHECK_EQUAL(o2.unit(),"m");
        BOOST_CHECK_EQUAL(o.name(),"motor");
        BOOST_CHECK_EQUAL(o.unit(),"m");
    }

    //------------------------------------------------------------------------
    BOOST_AUTO_TEST_CASE(move_assignment)
    {
        moveable o("motor","m");
        moveable o2;

        o2 = std::move(o);

        BOOST_CHECK_EQUAL(o2.name(),"motor");
        BOOST_CHECK_EQUAL(o2.unit(),"m");
        BOOST_CHECK(o.name().empty());
        BOOST_CHECK(o.unit().empty());

    }

BOOST_AUTO_TEST_SUITE_END()
