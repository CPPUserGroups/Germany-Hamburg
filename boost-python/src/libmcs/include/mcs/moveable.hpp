//
// (c) Copyright 2015 Eugen Wintersberger <eugen.wintersberger@gmail.com>
//
// This file is part of libmcs.
//
// libmcs is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// libmcs is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libmcs.  If not, see <http://www.gnu.org/licenses/>.
//
// ===========================================================================
#pragma once

#include <string>

namespace mcs{
    class moveable
    {
        private:
            std::string _name;
            std::string _unit;
        public:
            moveable();
            moveable(const std::string &n,const std::string &u);

            std::string name() const;
            void name(const std::string &n);
            
            std::string unit() const;
            void unit(const std::string &u);

            virtual double upper_limit() const = 0;
            virtual void upper_limit(double value) = 0;
            virtual double lower_limit() const = 0;
            virtual void lower_limit(double value) = 0;
            virtual double position() const = 0;
            virtual void position(double p) = 0;
    };

//end of namespace
}

