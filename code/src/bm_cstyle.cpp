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

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <chrono>
#include "../include/narray.hpp"

typedef std::vector<double>   storage_type;
typedef narray<storage_type> array_type;

typedef std::chrono::high_resolution_clock clock_type;

void compute_result(const array_type &args,array_type &result)
{
    size_t nelements = args.size();

    for(size_t index=0;index<nelements;++index)
        result[index] = std::sin(args[index]);
}

int main(int argc,char **argv)
{ 
    size_t nruns = 1;
    size_t nelements = 1024;

    if(argc>=2) nelements = std::atoi(argv[1]);

    if(argc>=3) nruns = std::atoi(argv[2]);

    //allocate memory
    array_type arg(nelements),result(nelements);

    //generate input data
    auto start_time = clock_type::now();
    for(size_t run=0;run<nruns;++run)
    {
        compute_result(arg,result);
    }
    auto stop_time = clock_type::now();
    auto delta = stop_time-start_time;
    auto elapsed_time =
        std::chrono::duration_cast<std::chrono::milliseconds>(delta);
    std::cout<<"Number of runs: "<<nruns<<std::endl;
    std::cout<<"Array size:     "<<nelements<<std::endl;
    std::cout<<"Elapsed time:   "<<elapsed_time.count()/nruns<<std::endl;

    return 0;
}
