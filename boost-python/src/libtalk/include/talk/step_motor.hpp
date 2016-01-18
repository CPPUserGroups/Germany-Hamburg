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

#include "motor.hpp"

namespace talk{

    //!
    //! \brief step motor model 
    //!
    //! Model of a step motor (a moveable). The current model is rather simple
    //! as it does not takes acceleration into account. The time the motor 
    //! requires to reach its position is determined only by its resolution
    //! which is given in degrees/step and the velocity in steps/second. 
    //! 
    class step_motor : public motor
    {
        private:
            double _step_size;   //! degrees per step
            double _current_pos;
        public:
            step_motor();
            step_motor(double s,double cpos,double ulimit,double llimit);
            step_motor(const step_motor &m) = default;

            step_motor &operator=(const step_motor& m) = default;

            virtual double get_position() const;
            virtual void set_position(double p);

            double get_step_size() const;
            void set_step_size(double r);
    };
}

