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

#include "moveable.hpp"

namespace mcs{

    //!
    //! \brief step motor model 
    //!
    //! Model of a step motor (a moveable). The current model is rather simple
    //! as it does not takes acceleration into account. The time the motor 
    //! requires to reach its position is determined only by its resolution
    //! which is given in degrees/step and the velocity in steps/second. 
    //! 
    //!
    //! 
    class step_motor : public moveable
    {
        private:
            double _min;
            double _max;
            double _pos;
            double _resolution;  //! degrees per step
            double _velocity;    //! steps per second (must not be integer)
        public:
            step_motor();
            step_motor(const std::string &n,const std::string &u);
            step_motor(const step_motor &m);
            step_motor(step_motor &&m);
            virtual ~step_motor();

            step_motor &operator=(const step_motor &m);
            step_motor &operator=(step_motor &&m);

            virtual double upper_limit() const;
            virtual void upper_limit(double value);
            virtual double lower_limit() const;
            virtual void lower_limit(double value);
            virtual double position() const;
            virtual void position(double p);

            long int resolution() const;
            void resolution(long int r);

            long int velocity(
    };
}

