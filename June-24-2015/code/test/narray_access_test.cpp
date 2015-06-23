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

struct access_fixture
{
    array_type a;

    access_fixture():
        a(array_type{1,2,3,4})
    {}
};

static const double tolerance = 1.e-8;

BOOST_FIXTURE_TEST_SUITE(access_test,access_fixture)

BOOST_AUTO_TEST_CASE(test_rw_access)
{
    BOOST_CHECK_CLOSE(a[0],1,tolerance);
    BOOST_CHECK_CLOSE(a[1],2,tolerance);
    BOOST_CHECK_CLOSE(a[2],3,tolerance);
    BOOST_CHECK_CLOSE(a[3],4,tolerance);
}

BOOST_AUTO_TEST_CASE(test_const_access)
{
    const array_type &ca=a;

    BOOST_CHECK_CLOSE(a[0],1,tolerance);
    BOOST_CHECK_CLOSE(a[1],2,tolerance);
    BOOST_CHECK_CLOSE(a[2],3,tolerance);
    BOOST_CHECK_CLOSE(a[3],4,tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
