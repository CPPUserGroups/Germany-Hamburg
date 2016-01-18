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


#include <talk/step_motor.hpp>

namespace talk{


    step_motor::step_motor():
        motor(),
        _step_size(0.0),
        _current_pos(0.0)
    {}

    //-------------------------------------------------------------------------
    step_motor::step_motor(double s,double cpos,double ulimit,double llimit):
        motor(ulimit,llimit),
        _step_size(s),
        _current_pos(cpos)
    {}

    //-------------------------------------------------------------------------
    double step_motor::get_position() const 
    { 
        return _current_pos; 
    }
    
    //-------------------------------------------------------------------------
    void step_motor::set_position(double p) 
    { 
        double distance = p - _current_pos;
        long int nsteps = distance/_step_size;
        
        _current_pos += nsteps*_step_size;
    }

    //-------------------------------------------------------------------------
    double step_motor::get_step_size() const 
    {
        return _step_size;
    }

    //--------------------------------------------------------------------------
    void step_motor::set_step_size(double s)
    {
        _step_size = s;
    }

//end of namespace 
}
