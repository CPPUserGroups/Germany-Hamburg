//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of Expression Templates Talk.
//
// Expression templates talk is free software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or (at your
// option) any later version.
//
// Expression Tempaltes Talks  is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
// Public License for more details.
//
// You should have received a copy of the GNU General Public License along with
// Expression Templates Talk.  If not, see <http://www.gnu.org/licenses/>.
//
// ===========================================================================

#include "narray_test_common.hpp"

#include "../include/exp_templates/binary_operators.hpp"
#include "../include/exp_templates/functions.hpp"

static const double tolerance = 1.e-8;
using namespace et;

struct mixed_fixture
{
    array_type a;
    array_type b;
    array_type c;
    double x;
    double y;

    mixed_fixture():
        a(array_type{1,2,3,4,5}),
        b(array_type{6,7,8,9,10}),
        c(array_type{10,9,8,7,6}),
        x(12.),
        y(13.)
    {}

};

BOOST_FIXTURE_TEST_SUITE(earray_mixed_tests,mixed_fixture)

BOOST_AUTO_TEST_CASE(test_1)
{
    auto r = a+x*b-c/y;
    BOOST_CHECK_CLOSE(r[0],a[0]+x*b[0]-c[0]/y,tolerance);
    BOOST_CHECK_CLOSE(r[1],a[1]+x*b[1]-c[1]/y,tolerance);
    BOOST_CHECK_CLOSE(r[2],a[2]+x*b[2]-c[2]/y,tolerance);
    BOOST_CHECK_CLOSE(r[3],a[3]+x*b[3]-c[3]/y,tolerance);
    BOOST_CHECK_CLOSE(r[4],a[4]+x*b[4]-c[4]/y,tolerance);
}

BOOST_AUTO_TEST_CASE(test_2)
{
    auto r = sin(a)*cos(x-b)+y/c;
    BOOST_CHECK_CLOSE(r[0],std::sin(a[0])*std::cos(x-b[0])+y/c[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(a[1])*std::cos(x-b[1])+y/c[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(a[2])*std::cos(x-b[2])+y/c[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],std::sin(a[3])*std::cos(x-b[3])+y/c[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],std::sin(a[4])*std::cos(x-b[4])+y/c[4],tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
