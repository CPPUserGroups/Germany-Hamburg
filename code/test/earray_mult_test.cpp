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

static const double tolerance = 1.e-8;
using namespace et;

struct mult_fixture
{
    array_type arhs;
    array_type alhs;
    array_type agen;
    double srhs;
    double slhs;

    mult_fixture():
        arhs(array_type{1,2,3,4,5}),
        alhs(array_type{6,7,8,9,10}),
        agen(array_type{10,9,8,7,6}),
        srhs(12.),
        slhs(13.)
    {}

    array_type generate()
    {
        return agen;
    }
};

BOOST_FIXTURE_TEST_SUITE(earray_mult_tests,mult_fixture)

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_array_array_lvalue_array)
{
    //the argument is an lvalue reference
    auto r = alhs*arhs;
    BOOST_CHECK_CLOSE(r[0],alhs[0]*arhs[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],alhs[1]*arhs[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],alhs[2]*arhs[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],alhs[3]*arhs[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],alhs[4]*arhs[4],tolerance);

}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_rvalue_array_lvalue_array)
{
    //LHS is temporary and RHS is lvalue reference
    auto r = generate()*arhs;
    BOOST_CHECK_CLOSE(r[0],agen[0]*arhs[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],agen[1]*arhs[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],agen[2]*arhs[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],agen[3]*arhs[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],agen[4]*arhs[4],tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_array_rvalue_array)
{
    //LHS is lvalue reference and RHS is temporary
    auto r = alhs * generate();
    BOOST_CHECK_CLOSE(r[0],alhs[0]*agen[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],alhs[1]*agen[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],alhs[2]*agen[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],alhs[3]*agen[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],alhs[4]*agen[4],tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_rvalue_array_rvalue_array)
{
    //both arguments are temporaries
    auto r = generate() * generate();
    BOOST_CHECK_CLOSE(r[0],agen[0]*agen[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],agen[1]*agen[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],agen[2]*agen[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],agen[3]*agen[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],agen[4]*agen[4],tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_scalar_lvalue_array)
{
    //the argument is an rvalue reference?
    auto r = slhs * arhs;
    BOOST_CHECK_CLOSE(r[0],slhs*arhs[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],slhs*arhs[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],slhs*arhs[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],slhs*arhs[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],slhs*arhs[4],tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_array_lvalue_scalar)
{
    auto r = alhs * srhs;
    BOOST_CHECK_CLOSE(r[0],alhs[0]*srhs,tolerance);
    BOOST_CHECK_CLOSE(r[1],alhs[1]*srhs,tolerance);
    BOOST_CHECK_CLOSE(r[2],alhs[2]*srhs,tolerance);
    BOOST_CHECK_CLOSE(r[3],alhs[3]*srhs,tolerance);
    BOOST_CHECK_CLOSE(r[4],alhs[4]*srhs,tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_rvalue_scalar_lvalue_array)
{
    auto r = 1.2 * arhs;
    BOOST_CHECK_CLOSE(r[0],1.2*arhs[0],tolerance);
    BOOST_CHECK_CLOSE(r[1],1.2*arhs[1],tolerance);
    BOOST_CHECK_CLOSE(r[2],1.2*arhs[2],tolerance);
    BOOST_CHECK_CLOSE(r[3],1.2*arhs[3],tolerance);
    BOOST_CHECK_CLOSE(r[4],1.2*arhs[4],tolerance);
}

//----------------------------------------------------------------------------
BOOST_AUTO_TEST_CASE(test_lvalue_array_rvalue_scalar)
{
    auto r = alhs * 1.4;
    BOOST_CHECK_CLOSE(r[0],alhs[0]*1.4,tolerance);
    BOOST_CHECK_CLOSE(r[1],alhs[1]*1.4,tolerance);
    BOOST_CHECK_CLOSE(r[2],alhs[2]*1.4,tolerance);
    BOOST_CHECK_CLOSE(r[3],alhs[3]*1.4,tolerance);
    BOOST_CHECK_CLOSE(r[4],alhs[4]*1.4,tolerance);
}


BOOST_AUTO_TEST_SUITE_END()
