//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
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
#pragma once

namespace talk{

class motor 
{
    private:
        double _upper_limit; 
        double _lower_limit; 
    public:
        motor();
        motor(double llimit,double ulimit);
        motor(const motor &m) = default;
        virtual ~motor();

        motor &operator=(const motor &m) = default;

        virtual double get_position() const;
        virtual void set_position(double p);

        double get_upper_limit() const;
        void set_upper_limit(double limit);

        double get_lower_limit() const;
        void set_lower_limit(double limit);
};

//end of namespace
}

