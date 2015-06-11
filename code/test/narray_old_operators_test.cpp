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
#include "../include/old_operators/operators.hpp"

struct old_operators_fixture
{
    array_type a;
    array_type b;
    double     c;

    old_operators_fixture():
        a(array_type{1.,2.,3.,4.}),
        b(array_type{5.,6.,7.,8.}),
        c(9.)
    {}
};

static const double tolerance = 1.e-8;

BOOST_FIXTURE_TEST_SUITE(old_operators_tests,old_operators_fixture)

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_add_array_array)
{
    array_type r = a+b;
    BOOST_CHECK_CLOSE(r[0],1.+5.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2.+6.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3.+7.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4.+8.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_add_scalar_array)
{
    array_type r = c+a;
    BOOST_CHECK_CLOSE(r[0],9.+1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9.+2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9.+3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9.+4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_add_array_scalar)
{
    array_type r = a+c;
    BOOST_CHECK_CLOSE(r[0],9.+1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9.+2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9.+3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9.+4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_mult_array_array)
{
    array_type r = a*b;
    BOOST_CHECK_CLOSE(r[0],1.*5.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2.*6.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3.*7.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4.*8.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_mult_scalar_array)
{
    array_type r = c*a;
    BOOST_CHECK_CLOSE(r[0],9.*1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9.*2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9.*3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9.*4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_mult_array_scalar)
{
    array_type r = a*c;
    BOOST_CHECK_CLOSE(r[0],9.*1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9.*2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9.*3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9.*4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_sub_array_array)
{
    array_type r = a-b;
    BOOST_CHECK_CLOSE(r[0],1.-5.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2.-6.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3.-7.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4.-8.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_sub_scalar_array)
{
    array_type r = c-a;
    BOOST_CHECK_CLOSE(r[0],9.-1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9.-2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9.-3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9.-4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_sub_array_scalar)
{
    array_type r = a-c;
    BOOST_CHECK_CLOSE(r[0],1.-9.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2.-9.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3.-9.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4.-9.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_div_array_array)
{
    array_type r = a/b;
    BOOST_CHECK_CLOSE(r[0],1./5.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2./6.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3./7.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4./8.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_div_scalar_array)
{
    array_type r = c/a;
    BOOST_CHECK_CLOSE(r[0],9./1.,tolerance);
    BOOST_CHECK_CLOSE(r[1],9./2.,tolerance);
    BOOST_CHECK_CLOSE(r[2],9./3.,tolerance);
    BOOST_CHECK_CLOSE(r[3],9./4.,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_div_array_scalar)
{
    array_type r = a/c;
    BOOST_CHECK_CLOSE(r[0],1./9.,tolerance);
    BOOST_CHECK_CLOSE(r[1],2./9.,tolerance);
    BOOST_CHECK_CLOSE(r[2],3./9.,tolerance);
    BOOST_CHECK_CLOSE(r[3],4./9.,tolerance);
}
BOOST_AUTO_TEST_SUITE_END()
