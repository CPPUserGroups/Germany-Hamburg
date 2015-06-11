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

#include <vector>
#include <boost/test/unit_test.hpp>
#include "../include/narray.hpp"

typedef std::vector<double> storage_type;
typedef narray<storage_type> array_type;

BOOST_AUTO_TEST_SUITE(narray_test)

BOOST_AUTO_TEST_CASE(test_default_construction)
{
    array_type a;
    BOOST_CHECK_EQUAL(a.size(),0);
}

BOOST_AUTO_TEST_CASE(test_size_construction)
{
    array_type a(100);
    BOOST_CHECK_EQUAL(a.size(),100);
}

BOOST_AUTO_TEST_SUITE_END()
