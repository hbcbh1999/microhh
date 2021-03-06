/*
 * MicroHH
 * Copyright (c) 2011-2017 Chiel van Heerwaarden
 * Copyright (c) 2011-2017 Thijs Heus
 * Copyright (c) 2014-2017 Bart van Stratum
 *
 * This file is part of MicroHH
 *
 * MicroHH is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * MicroHH is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with MicroHH.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DIFF_DISABLED
#define DIFF_DISABLED

#include "diff.h"

// forward declaration to speed up build time
class Model;
class Input;

class Diff_disabled : public Diff
{
    public:
        Diff_disabled(Model*, Input*);
        ~Diff_disabled();

        std::string get_name();
        unsigned long get_time_limit(unsigned long, double);
        double get_dn(double);

        // Empty functions.
        void set_values() {}
        void exec_viscosity() {}
        void exec() {}

        #ifdef USECUDA
        // GPU functions and variables
        void prepare_device() {}
        #endif
};
#endif
