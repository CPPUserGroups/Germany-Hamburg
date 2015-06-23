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

#include "../include/exp_templates/functions.hpp"

static const double tolerance = 1.e-8;

BOOST_AUTO_TEST_SUITE(earray_sin_tests)

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_ndarray_lvalue_sin)
{
    array_type args{1,2,3,4,5}; 

    //the argument is an lvalue reference
    auto r = et::sin(args);
    BOOST_CHECK_CLOSE(r[0],std::sin(1.),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(2.),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(3.),tolerance);
    BOOST_CHECK_CLOSE(r[3],std::sin(4.),tolerance);
    BOOST_CHECK_CLOSE(r[4],std::sin(5.),tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_ndarray_rvalue_sin)
{
    //the argument is an rvalue reference?
    auto r = et::sin(array_type{1,2,3,4,5});
    BOOST_CHECK_CLOSE(r[0],std::sin(1.),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(2.),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(3.),tolerance);
    BOOST_CHECK_CLOSE(r[3],std::sin(4.),tolerance);
    BOOST_CHECK_CLOSE(r[4],std::sin(5.),tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_literal_sin)
{
    //passing the scalar argument as a literal
    auto r = et::sin(1.2);
    BOOST_CHECK_CLOSE(r[0],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(1.2),tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_sin)
{
    //passing the scalar argument as a literal
    double arg = 1.2;
    auto r = et::sin(arg);
    BOOST_CHECK_CLOSE(r[0],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(1.2),tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_rvalue_sin)
{
    //passing the scalar argument as a literal
    auto r = et::sin(double(1.2));
    BOOST_CHECK_CLOSE(r[0],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[1],std::sin(1.2),tolerance);
    BOOST_CHECK_CLOSE(r[2],std::sin(1.2),tolerance);
}



BOOST_AUTO_TEST_SUITE_END()
