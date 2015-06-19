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
#include "../include/narray.hpp"
#include "../include/exp_templates/functions.hpp"

typedef std::vector<double>   storage_type;
typedef narray<storage_type> array_type;

int main(int argc,char **argv)
{
    array_type a{1,2,3,4,5};

    auto r1 = et::sin(a);

    auto r2 = et::sin(array_type{1,2,3,4,5});

    const array_type &r = a;
    auto r3 = et::sin(r);

    return 0;
}
