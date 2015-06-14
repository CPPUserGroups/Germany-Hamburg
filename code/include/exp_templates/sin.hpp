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
#pragma once

template<typename ArgT> class sin
{
    public:
        typedef ArgT argument_type
        typedef typename argument_type::value_type value_type;
        typedef sin<agument_type> expression_type;
    private:
        const argument_type &_arg;
    public:
        sin(const argument_type &arg):_arg(arg) {}

        sin(const expression_type &e):_arg(e._arg) {}


        size_t size() const { return _arg.size(); } 

        value_type operator[](size_t index) const
        {
            return std::sin(_arg[index]);
        }
};
