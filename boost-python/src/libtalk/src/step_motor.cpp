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


#include <mcs/step_motor.hpp>
#include <mcs/exceptions.hpp>

namespace mcs{


    step_motor::step_motor():
        moveable(),
        _min(0.0),
        _max(0.0),
        _pos(0.0),
        _resolution(0.0),
        _velocity(0.0)
    {}

    //-------------------------------------------------------------------------
    step_motor::step_motor(const std::string &n,const std::string &u):
        moveable(n,u),
        _min(0.0),
        _max(0.0),
        _pos(0.0),
        _resolution(0.0),
        _velocity(0.0)
    {}

    //-------------------------------------------------------------------------
    step_motor::step_motor(const step_motor &m):
        moveable(m),
        _min(m._min),
        _max(m._max),
        _pos(m._pos),
        _resolution(m._resolution),
        _velocity(m._velocity)
    {}

    //-------------------------------------------------------------------------
    step_motor::step_motor(step_motor &&m):
        moveable(std::move(m)),
        _min(std::move(m._min)),
        _max(std::move(m._max)),
        _pos(std::move(m._pos)),
        _resolution(std::move(m._resolution)),
        _velocity(std::move(m._velocity))
    {}

    step_motor::~step_motor()
    { }

    //-------------------------------------------------------------------------
    step_motor &step_motor::operator=(const step_motor &m)
    {
        if(this == &m) return *this;

        moveable::operator=(m);
        _min = m._min;
        _max = m._max;
        _pos = m._pos;
        _resolution = m._resolution;
        _velocity = m._velocity;

        return *this;
    }

    //------------------------------------------------------------------------
    step_motor &step_motor::operator=(step_motor &&m)
    {
        if(this == &m) return *this;

        moveable::operator=(std::move(m));
        _min = std::move(m._min);
        _max = std::move(m._max);
        _pos = std::move(m._pos);
        _resolution = std::move(m._resolution);
        _velocity = std::move(m._velocity);

        return *this;
    }

    //-------------------------------------------------------------------------
    double step_motor::upper_limit() const { return _max; }

    //-------------------------------------------------------------------------
    void step_motor::upper_limit(double value) { _max = value; }
    
    //-------------------------------------------------------------------------
    double step_motor::lower_limit() const { return _min; } 

    //-------------------------------------------------------------------------
    void step_motor::lower_limit(double value) { _min = value; } 
    
    //-------------------------------------------------------------------------
    double step_motor::position() const { return _pos; } 
    
    //-------------------------------------------------------------------------
    void step_motor::position(double p) 
    { 
        if(p < lower_limit()) throw limit_exceeded();

        if(p > upper_limit()) throw limit_exceeded(); 


        double distance = _pos - p;
        size_t nsteps = (distance - distance%_resolution)/_resolutionlj

        _pos = p; 
    }

//end of namespace 
}
