//
// (c) Copyright 2016 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of libtalk.
//
// libtalk is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// libtalk is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libtalk.  If not, see <http://www.gnu.org/licenses/>.
//
// ===========================================================================

#include <iostream>
#include <cmath>
#include <talk/functions.hpp>
#include <talk/exceptions.hpp>

namespace talk{

    //------------------------------------------------------------------------
    double div(double a,double b)
    {
        if(std::abs(b)<1.e-9)
            throw division_by_zero();

        return a/b;
    }

    //------------------------------------------------------------------------
    double add(double a,double b)
    {
        return a+b;
    }

    //------------------------------------------------------------------------
    int add(int a,int b)
    {
        return a+b;
    }

}

