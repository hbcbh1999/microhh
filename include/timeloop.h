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

#ifndef TIMELOOP
#define TIMELOOP

#include <sys/time.h>
#include <string>

class Input;
class Master;
class Model;
class Grid;
class Fields;

class Timeloop
{
    public:
        Timeloop(Model*, Input*);
        ~Timeloop();

        void step_time();
        void step_post_proc_time();
        void set_time_step();
        void set_time_step_limit();
        void set_time_step_limit(unsigned long);
        double get_sub_time_step();

        void exec();

        double check();

        void save(int);
        void load(int);

        // Query functions for main loop
        bool in_substep();
        bool is_stats_step();
        bool do_check();
        bool do_save();
        bool is_finished();

        // Accessors for other classes
        double get_time()   { return time;    }
        double get_dt()     { return dt;      }
        double get_ifactor(){ return ifactor; }
        unsigned long get_itime() { return itime; }
        unsigned long get_idt()   { return idt;   }
        int get_iotime()    { return iotime;    }
        int get_iteration() { return iteration; }

    private:
        Master* master;
        Model*  model;
        Grid*   grid;
        Fields* fields;

        timeval start;
        timeval end;

        int rkorder;

        int outputiter;

        void rk3(double*, double*, double);
        void rk4(double*, double*, double);

        double rk3subdt(double);
        double rk4subdt(double);

        // Variables
        bool loop;

        int substep;
        bool adaptivestep;

        double time;
        double dt;
        double dtmax;
        double endtime;
        double postproctime;
        double savetime;
        double starttime;

        int iteration;
        int iotime;
        int iotimeprec;

        unsigned long itime;
        unsigned long istarttime;
        unsigned long iendtime;
        unsigned long idt;
        unsigned long idtmax;
        unsigned long ipostproctime;
        unsigned long isavetime;
        unsigned long idtlim;
        unsigned long iiotimeprec;

        double ifactor;
};
#endif
