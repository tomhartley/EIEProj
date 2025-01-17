// ----------------------------------------------------------------------------
// SystemC Header for Top
//
//    HLS version: 2011a.126 Production Release
//       HLS date: Wed Aug  8 00:52:07 PDT 2012
//  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
//
//   Generated by: fyq14@EEWS104A-002
// Generated date: Tue Mar 03 15:18:43 +0000 2015
//
// ----------------------------------------------------------------------------
// 
// -------------------------------------
// scverify_top
// top module instantiating reference design,
// DUT and comparator
// -------------------------------------
// 
#ifndef INCLUDED_SCVERIFY_TOP_H
#define INCLUDED_SCVERIFY_TOP_H

#ifndef TO_QUOTED_STRING
#define TO_QUOTED_STRING(x) TO_QUOTED_STRING1(x)
#define TO_QUOTED_STRING1(x) #x
#endif
#ifndef TOP_HDL_ENTITY
#define TOP_HDL_ENTITY dot_product
#endif

// Hold time for the SCVerify testbench to account for the gate delay after downstream synthesis in pico second(s)
// Hold time value is obtained from 'top_gate_constraints.cpp', which is generated at the end of RTL synthesis
#ifdef CCS_DUT_GATE
extern double __scv_hold_time;
extern double __scv_hold_time_RSCID_1;
extern double __scv_hold_time_RSCID_2;
extern double __scv_hold_time_RSCID_3;
#else
double __scv_hold_time = 0.0; // default for non-gate simulation is zero
double __scv_hold_time_RSCID_1 = 0.0;
double __scv_hold_time_RSCID_2 = 0.0;
double __scv_hold_time_RSCID_3 = 0.0;
#endif


#include "mc_testbench.h"
#include "mc_reset.h"
#include "mc_transactors.h"
#include "mgc_ioport_trans_rsc.h"
#include "mc_monitor.h"
#include "mc_dut_wrapper.h"


class scverify_top : public sc_module
{
public:
   // Interface Ports
   
   // Data objects
   sc_event deadlock_event;
   sc_signal< sc_logic >                      deadlocked;
   sc_event reset_deactivation_event;
   sc_signal< sc_logic >                      rst;
   sc_signal< sc_logic >                      rst_n;
   bool var_trdone;
   sc_clock clk;
   sc_signal< sc_logic >                      TLS_arst_n;
   sc_signal< sc_logic >                      in_sync;
   sc_signal< sc_logic >                      out_sync;
   sc_signal< sc_logic >                      inout_sync;
   sc_signal< unsigned >                      wait_for_init;
   sc_signal< sc_logic >                      catapult_start;
   sc_signal< sc_logic >                      catapult_done;
   sc_signal< sc_logic >                      catapult_ready;
   sc_signal< sc_logic >                      TLS_en;
   sc_signal< sc_lv<8> >                      TLS_input_a_rsc_z;
   sc_signal< sc_lv<8> >                      TLS_input_b_rsc_z;
   sc_signal< sc_lv<8> >                      TLS_output_rsc_z;
   tlm::tlm_fifo< mc_wait_ctrl > TLS_in_wait_ctrl_fifo_input_a;
   tlm::tlm_fifo< ac_int<8, true > > TLS_fifo_in_input_a;
   tlm::tlm_fifo< mc_wait_ctrl > TLS_in_wait_ctrl_fifo_input_b;
   tlm::tlm_fifo< ac_int<8, true > > TLS_fifo_in_input_b;
   tlm::tlm_fifo< mc_wait_ctrl > TLS_out_wait_ctrl_fifo_output;
   tlm::tlm_fifo< ac_int<8, true > > TLS_fifo_out_output;
   
   // Named Objects
   
   // Module instance pointers
   ccs_DUT_wrapper *dot_product_INST;
   mc_programmable_reset *arst_n_driver;
   mgc_in_wire_trans_rsc< 5,8 > *input_a_rsc_INST;
   mgc_in_wire_trans_rsc< 5,8 > *input_b_rsc_INST;
   mgc_out_stdreg_trans_rsc< 1,8 > *output_rsc_INST;
   mc_input_transactor<ac_int<8, true >,8,true> *input_a_transactor;
   mc_input_transactor<ac_int<8, true >,8,true> *input_b_transactor;
   mc_output_transactor<ac_int<8, true >,8,true> *output_transactor;
   testbench *testbench_INST;
   
   // Declare processes (SC_METHOD and SC_THREAD)
   void deadlock_notify();
   void deadlock_watch();
   void generate_sync();
   void generate_reset();
   
   // Constructor
   SC_HAS_PROCESS(scverify_top);
   scverify_top(
      const sc_module_name& name
   )
      : deadlocked("deadlocked")
      , rst("rst")
      , rst_n("rst_n")
      , var_trdone(false)
      , clk("clk",20.000000,SC_NS,0.5,0.000000,SC_NS,false)
      , TLS_arst_n("TLS_arst_n")
      , in_sync("in_sync")
      , out_sync("out_sync")
      , inout_sync("inout_sync")
      , wait_for_init("wait_for_init")
      , catapult_start("catapult_start")
      , catapult_done("catapult_done")
      , catapult_ready("catapult_ready")
      , TLS_en("TLS_en")
      , TLS_input_a_rsc_z("TLS_input_a_rsc_z")
      , TLS_input_b_rsc_z("TLS_input_b_rsc_z")
      , TLS_output_rsc_z("TLS_output_rsc_z")
      , TLS_in_wait_ctrl_fifo_input_a("TLS_in_wait_ctrl_fifo_input_a",-1)
      , TLS_fifo_in_input_a("TLS_fifo_in_input_a",-1)
      , TLS_in_wait_ctrl_fifo_input_b("TLS_in_wait_ctrl_fifo_input_b",-1)
      , TLS_fifo_in_input_b("TLS_fifo_in_input_b",-1)
      , TLS_out_wait_ctrl_fifo_output("TLS_out_wait_ctrl_fifo_output",-1)
      , TLS_fifo_out_output("TLS_fifo_out_output",-1)
   {
      // Instantiate other modules
      dot_product_INST = new ccs_DUT_wrapper(
         "rtl",
         TO_QUOTED_STRING(TOP_HDL_ENTITY)
      );
      dot_product_INST->clk(clk);
      dot_product_INST->en(TLS_en);
      dot_product_INST->arst_n(TLS_arst_n);
      dot_product_INST->input_a_rsc_z(TLS_input_a_rsc_z);
      dot_product_INST->input_b_rsc_z(TLS_input_b_rsc_z);
      dot_product_INST->output_rsc_z(TLS_output_rsc_z);
      
      arst_n_driver = new mc_programmable_reset(
         "arst_n_driver",
         40.0,
         1
      );
      arst_n_driver->reset_out(TLS_arst_n);
      
      input_a_rsc_INST = new mgc_in_wire_trans_rsc< 5,8 > (
         "input_a_rsc",
         true
      );
      input_a_rsc_INST->z(TLS_input_a_rsc_z);
      input_a_rsc_INST->clk(clk);
      input_a_rsc_INST->add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_1 )));
      
      input_b_rsc_INST = new mgc_in_wire_trans_rsc< 5,8 > (
         "input_b_rsc",
         true
      );
      input_b_rsc_INST->z(TLS_input_b_rsc_z);
      input_b_rsc_INST->clk(clk);
      input_b_rsc_INST->add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_2 )));
      
      output_rsc_INST = new mgc_out_stdreg_trans_rsc< 1,8 > (
         "output_rsc",
         true
      );
      output_rsc_INST->z(TLS_output_rsc_z);
      output_rsc_INST->clk(clk);
      output_rsc_INST->add_attribute(*(new sc_attribute<double>("CLK_SKEW_DELAY", __scv_hold_time_RSCID_3 )));
      
      input_a_transactor = new mc_input_transactor<ac_int<8, true >,8,true> (
         "transactor_input_a",
         0,
         8,
         0,
         false
      );
      input_a_transactor->in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_input_a);
      input_a_transactor->in_fifo(TLS_fifo_in_input_a);
      input_a_transactor->add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT )));
      input_a_transactor->bind_clk(clk,true);
      input_a_transactor->register_block(input_a_rsc_INST,input_a_rsc_INST->basename(),in_sync,0,4,1);
      
      input_b_transactor = new mc_input_transactor<ac_int<8, true >,8,true> (
         "transactor_input_b",
         0,
         8,
         0,
         false
      );
      input_b_transactor->in_wait_ctrl_fifo(TLS_in_wait_ctrl_fifo_input_b);
      input_b_transactor->in_fifo(TLS_fifo_in_input_b);
      input_b_transactor->add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT )));
      input_b_transactor->bind_clk(clk,true);
      input_b_transactor->register_block(input_b_rsc_INST,input_b_rsc_INST->basename(),in_sync,0,4,1);
      
      output_transactor = new mc_output_transactor<ac_int<8, true >,8,true> (
         "transactor_output",
         0,
         8,
         0
      );
      output_transactor->out_wait_ctrl_fifo(TLS_out_wait_ctrl_fifo_output);
      output_transactor->out_fifo(TLS_fifo_out_output);
      output_transactor->add_attribute(*(new sc_attribute<int>("MC_TRANSACTOR_EVENT", MC_TRANSACTOR_UNDERFLOW | MC_TRANSACTOR_WAIT )));
      output_transactor->bind_clk(clk,true);
      output_transactor->register_block(output_rsc_INST,output_rsc_INST->basename(),out_sync,0,0,1);
      
      testbench_INST = new testbench(
         "user_tb"
      );
      testbench_INST->clk(clk);
      testbench_INST->ccs_input_a(TLS_fifo_in_input_a);
      testbench_INST->ccs_wait_ctrl_input_a(TLS_in_wait_ctrl_fifo_input_a);
      testbench_INST->ccs_input_b(TLS_fifo_in_input_b);
      testbench_INST->ccs_wait_ctrl_input_b(TLS_in_wait_ctrl_fifo_input_b);
      testbench_INST->ccs_output(TLS_fifo_out_output);
      testbench_INST->ccs_wait_ctrl_output(TLS_out_wait_ctrl_fifo_output);
      
      
      // Register processes
      SC_METHOD(deadlock_notify);
      sensitive << deadlock_event;
      dont_initialize();
      SC_METHOD(deadlock_watch);
      sensitive  << clk;
      dont_initialize();
      SC_METHOD(generate_sync);
      sensitive << clk << rst;
      dont_initialize();
      SC_METHOD(generate_reset);
      sensitive << reset_deactivation_event;
      // Other constructor statements
      // set seed for random number generator used by wait_ctrl
      mt19937_init_genrand(19650218UL);
      install_observe_foreign_signals();
   }
   
   ~scverify_top()
   {
      delete dot_product_INST;
      dot_product_INST = 0;
      delete arst_n_driver;
      arst_n_driver = 0;
      delete input_a_rsc_INST;
      input_a_rsc_INST = 0;
      delete input_b_rsc_INST;
      input_b_rsc_INST = 0;
      delete output_rsc_INST;
      output_rsc_INST = 0;
      delete input_a_transactor;
      input_a_transactor = 0;
      delete input_b_transactor;
      input_b_transactor = 0;
      delete output_transactor;
      output_transactor = 0;
      delete testbench_INST;
      testbench_INST = 0;
   }
   
   // C++ class functions
   public:
      void setup_debug() ;
   public:
      void install_observe_foreign_signals() ;
   public:
      void debug(const char *varname, int flags, int count) ;
};
#endif
