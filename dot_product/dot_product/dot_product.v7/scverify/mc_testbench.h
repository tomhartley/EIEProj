// ----------------------------------------------------------------------------
// SystemC Testbench Header
//
//    HLS version: 2011a.126 Production Release
//       HLS date: Wed Aug  8 00:52:07 PDT 2012
//  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
//
//   Generated by: fyq14@EEWS104A-002
// Generated date: Tue Mar 03 15:18:43 +0000 2015
//
// ----------------------------------------------------------------------------
#ifdef CCS_SCVERIFY

// 
// -------------------------------------
// testbench
// User supplied testbench
// -------------------------------------
// 
#ifndef INCLUDED_TESTBENCH_H
#define INCLUDED_TESTBENCH_H

extern void mc_testbench_input_a_skip(bool v);
extern void mc_testbench_input_b_skip(bool v);
extern void mc_testbench_output_skip(bool v);

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include "//icnas3.cc.ic.ac.uk/fyq14/student_files_2015/student_files_2015/prj1/dot_product_source/dot_product.h"
#include <systemc.h>
#include <tlm.h>
#include <ac_int.h>
#include <mc_container_types.h>
#include <mc_typeconv.h>
#include <mc_transactors.h>
#include <mc_comparator.h>
#include <mc_end_of_testbench.h>
#include <vector>


class testbench : public sc_module
{
public:
   // Interface Ports
   sc_in< bool > clk;
   sc_port< tlm::tlm_fifo_put_if< ac_int<8, true > > > ccs_input_a;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_input_a;
   sc_port< tlm::tlm_fifo_put_if< ac_int<8, true > > > ccs_input_b;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_input_b;
   sc_port< tlm::tlm_fifo_get_if< ac_int<8, true > > > ccs_output;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_output;
   
   // Data objects
   bool testbench_ended;
   int main_exit_code;
   bool atleast_one_active_input;
   sc_time last_event_time;
   sc_time last_event_time2;
   sc_signal< bool >                          cpp_testbench_active;
   sc_event testbench_end_event;
   int argc;
   const char* const *argv;
   bool _checked_results;
   bool _failed;
   static testbench* that;
   static std::vector<mc_end_of_testbench*> _end_of_tb_objs;
   int main();
   static bool input_a_ignore;
   static bool input_a_skip;
   static int input_a_array_comp_first;
   static int input_a_array_comp_last;
   bool _capture_input_a;
   static int input_a_wait_cycles;
   static mc_wait_ctrl input_a_wait_ctrl;
   int input_a_capture_count;
   int input_a_iteration_count;
   static bool input_b_ignore;
   static bool input_b_skip;
   static int input_b_array_comp_first;
   static int input_b_array_comp_last;
   bool _capture_input_b;
   static int input_b_wait_cycles;
   static mc_wait_ctrl input_b_wait_ctrl;
   int input_b_capture_count;
   int input_b_iteration_count;
   static bool output_ignore;
   static bool output_skip;
   static int output_array_comp_first;
   static int output_array_comp_last;
   static bool output_use_mask;
   static ac_int<8, true > output_output_mask;
   tlm::tlm_fifo< mc_golden_info< ac_int<8, true >, ac_int<8, true > > > output_golden;
   bool _capture_output;
   static int output_wait_cycles;
   static mc_wait_ctrl output_wait_ctrl;
   int output_capture_count;
   int output_iteration_count;
   int wait_cnt;
   
   // Named Objects
   
   // Module instance pointers
   mc_comparator< ac_int<8, true > , ac_int<8, true > > *output_comp;
   
   // Declare processes (SC_METHOD and SC_THREAD)
   void wait_for_end();
   void run();
   
   // Constructor
   SC_HAS_PROCESS(testbench);
   testbench(
      const sc_module_name& name
   )
      : clk("clk")
      , ccs_input_a("ccs_input_a")
      , ccs_wait_ctrl_input_a("ccs_wait_ctrl_input_a")
      , ccs_input_b("ccs_input_b")
      , ccs_wait_ctrl_input_b("ccs_wait_ctrl_input_b")
      , ccs_output("ccs_output")
      , ccs_wait_ctrl_output("ccs_wait_ctrl_output")
      , cpp_testbench_active("cpp_testbench_active")
      , output_golden("output_golden",-1)
   {
      // Instantiate other modules
      output_comp = new mc_comparator< ac_int<8, true > , ac_int<8, true > > (
         "output_comp",
         0,
         1
      );
      output_comp->data_in(ccs_output);
      output_comp->data_golden(output_golden);
      
      
      // Register processes
      SC_METHOD(wait_for_end);
      sensitive << clk.pos() << testbench_end_event;
      SC_THREAD(run);
      // Other constructor statements
      set_stack_size(64000000);
      argc = sc_argc();
      argv = sc_argv();
      _checked_results = false;
      that = this;
      testbench_ended = false;
      main_exit_code = 0;
      atleast_one_active_input = true;
      _capture_input_a = true;
      _capture_input_b = true;
      _capture_output = true;
      wait_cnt = 0;
   }
   
   ~testbench()
   {
      delete output_comp;
      output_comp = 0;
   }
   
   // C++ class functions
   public:
      void mc_testbench_process_wait_ctrl(const sc_string &var,int &var_wait_cycles,mc_wait_ctrl &var_wait_ctrl,tlm::tlm_fifo_put_if< mc_wait_ctrl > *ccs_wait_ctrl_fifo_if,const int var_capture_count,const int var_stopat) ;
   public:
      static void register_end_of_testbench_obj(mc_end_of_testbench* obj) ;
   public:
      void capture_input_a( ac_int<8, true > *input_a) ;
   public:
      void capture_input_b( ac_int<8, true > *input_b) ;
   public:
      void capture_output( ac_int<8, true > *output) ;
   protected:
      void wait_on_input_required() ;
   public:
      static void capture_IN( ac_int<8, true > *input_a,  ac_int<8, true > *input_b,  ac_int<8, true > *output) ;
   public:
      static void capture_OUT( ac_int<8, true > *input_a,  ac_int<8, true > *input_b,  ac_int<8, true > *output) ;
   public:
      static void exec_dot_product( ac_int<8, true > *input_a,  ac_int<8, true > *input_b,  ac_int<8, true > *output) ;
   protected:
      void end_of_simulation() ;
   public:
      void check_results() ;
   public:
      bool failed() ;
};
#endif
#endif