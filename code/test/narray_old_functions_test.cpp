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

#include <cstdlib>
#include "narray_test_common.hpp"
#include "../include/old_operators/functions.hpp"

struct old_function_fixture
{
    array_type a;

    old_function_fixture():
        a(array_type{1.0,2.0,3.0,4.0})
    {}
};

static const double tolerance = 1.e-8;

BOOST_FIXTURE_TEST_SUITE(old_functions_test,old_function_fixture)

BOOST_AUTO_TEST_CASE(test_sin)
{
    array_type r = sin(a);
    BOOST_CHECK_EQUAL(r.size(),a.size());
    
    BOOST_CHECK_CLOSE(r[0],std::sin(1.0),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(2.0),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(3.0),tolerance);
    BOOST_CHECK_CLOSE(r[3],std::sin(4.0),tolerance);
}

BOOST_AUTO_TEST_CASE(test_exp)
{
    array_type r = exp(a);
    
    BOOST_CHECK_CLOSE(r[0],std::exp(1),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::exp(2),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::exp(3),tolerance);
    BOOST_CHECK_CLOSE(r[3],std::exp(4),tolerance);
}

BOOST_AUTO_TEST_SUITE_END()
