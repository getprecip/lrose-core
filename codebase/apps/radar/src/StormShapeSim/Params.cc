/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
/* ** Copyright UCAR                                                         */
/* ** University Corporation for Atmospheric Research (UCAR)                 */
/* ** National Center for Atmospheric Research (NCAR)                        */
/* ** Boulder, Colorado, USA                                                 */
/* ** BSD licence applies - redistribution and use in source and binary      */
/* ** forms, with or without modification, are permitted provided that       */
/* ** the following conditions are met:                                      */
/* ** 1) If the software is modified to produce derivative works,            */
/* ** such modified software should be clearly marked, so as not             */
/* ** to confuse it with the version available from UCAR.                    */
/* ** 2) Redistributions of source code must retain the above copyright      */
/* ** notice, this list of conditions and the following disclaimer.          */
/* ** 3) Redistributions in binary form must reproduce the above copyright   */
/* ** notice, this list of conditions and the following disclaimer in the    */
/* ** documentation and/or other materials provided with the distribution.   */
/* ** 4) Neither the name of UCAR nor the names of its contributors,         */
/* ** if any, may be used to endorse or promote products derived from        */
/* ** this software without specific prior written permission.               */
/* ** DISCLAIMER: THIS SOFTWARE IS PROVIDED 'AS IS' AND WITHOUT ANY EXPRESS  */
/* ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      */
/* ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    */
/* *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* */
////////////////////////////////////////////
// Params.cc
//
// TDRP C++ code file for class 'Params'.
//
// Code for program StormShapeSim
//
// This file has been automatically
// generated by TDRP, do not modify.
//
/////////////////////////////////////////////

/**
 *
 * @file Params.cc
 *
 * @class Params
 *
 * This class is automatically generated by the Table
 * Driven Runtime Parameters (TDRP) system
 *
 * @note Source is automatically generated from
 *       paramdef file at compile time, do not modify
 *       since modifications will be overwritten.
 *
 *
 * @author Automatically generated
 *
 */
#include "Params.hh"
#include <cstring>

  ////////////////////////////////////////////
  // Default constructor
  //

  Params::Params()

  {

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // initialize table

    _init();

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Copy constructor
  //

  Params::Params(const Params& source)

  {

    // sync the source object

    source.sync();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // class name

    _className = "Params";

    // copy table

    tdrpCopyTable((TDRPtable *) source._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = false;

  }

  ////////////////////////////////////////////
  // Destructor
  //

  Params::~Params()

  {

    // free up

    freeAll();

  }

  ////////////////////////////////////////////
  // Assignment
  //

  void Params::operator=(const Params& other)

  {

    // sync the other object

    other.sync();

    // free up any existing memory

    freeAll();

    // zero out table

    memset(_table, 0, sizeof(_table));

    // zero out members

    memset(&_start_, 0, &_end_ - &_start_);

    // copy table

    tdrpCopyTable((TDRPtable *) other._table, _table);

    // set members

    tdrpTable2User(_table, &_start_);

    _exitDeferred = other._exitDeferred;

  }

  ////////////////////////////////////////////
  // loadFromArgs()
  //
  // Loads up TDRP using the command line args.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   char **params_path_p:
  //     If this is non-NULL, it is set to point to the path
  //     of the params file used.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromArgs(int argc, char **argv,
                           char **override_list,
                           char **params_path_p,
                           bool defer_exit)
  {
    int exit_deferred;
    if (_tdrpLoadFromArgs(argc, argv,
                          _table, &_start_,
                          override_list, params_path_p,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadApplyArgs()
  //
  // Loads up TDRP using the params path passed in, and applies
  // the command line args for printing and checking.
  //
  // Check usage() for command line actions associated with
  // this function.
  //
  //   const char *param_file_path: the parameter file to be read in
  //
  //   argc, argv: command line args
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   bool defer_exit: normally, if the command args contain a 
  //      print or check request, this function will call exit().
  //      If defer_exit is set, such an exit is deferred and the
  //      private member _exitDeferred is set.
  //      Use exidDeferred() to test this flag.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadApplyArgs(const char *params_path,
                            int argc, char **argv,
                            char **override_list,
                            bool defer_exit)
  {
    int exit_deferred;
    if (tdrpLoadApplyArgs(params_path, argc, argv,
                          _table, &_start_,
                          override_list,
                          _className,
                          defer_exit, &exit_deferred)) {
      return (-1);
    } else {
      if (exit_deferred) {
        _exitDeferred = true;
      }
      return (0);
    }
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  //

  bool Params::isArgValid(const char *arg)
  {
    return (tdrpIsArgValid(arg));
  }

  ////////////////////////////////////////////
  // isArgValid()
  // 
  // Check if a command line arg is a valid TDRP arg.
  // return number of args consumed.
  //

  int Params::isArgValidN(const char *arg)
  {
    return (tdrpIsArgValidN(arg));
  }

  ////////////////////////////////////////////
  // load()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to load
  // up more than one class for a single application. It is a
  // lower-level routine than loadFromArgs, and hence more
  // flexible, but the programmer must do more work.
  //
  //   const char *param_file_path: the parameter file to be read in.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::load(const char *param_file_path,
                   char **override_list,
                   int expand_env, int debug)
  {
    if (tdrpLoad(param_file_path,
                 _table, &_start_,
                 override_list,
                 expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadFromBuf()
  //
  // Loads up TDRP for a given class.
  //
  // This version of load gives the programmer the option to
  // load up more than one module for a single application,
  // using buffers which have been read from a specified source.
  //
  //   const char *param_source_str: a string which describes the
  //     source of the parameter information. It is used for
  //     error reporting only.
  //
  //   char **override_list: A null-terminated list of overrides
  //     to the parameter file.
  //     An override string has exactly the format of an entry
  //     in the parameter file itself.
  //
  //   const char *inbuf: the input buffer
  //
  //   int inlen: length of the input buffer
  //
  //   int start_line_num: the line number in the source which
  //     corresponds to the start of the buffer.
  //
  //   expand_env: flag to control environment variable
  //               expansion during tokenization.
  //               If TRUE, environment expansion is set on.
  //               If FALSE, environment expansion is set off.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadFromBuf(const char *param_source_str,
                          char **override_list,
                          const char *inbuf, int inlen,
                          int start_line_num,
                          int expand_env, int debug)
  {
    if (tdrpLoadFromBuf(param_source_str,
                        _table, &_start_,
                        override_list,
                        inbuf, inlen, start_line_num,
                        expand_env, debug)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // loadDefaults()
  //
  // Loads up default params for a given class.
  //
  // See load() for more detailed info.
  //
  //  Returns 0 on success, -1 on failure.
  //

  int Params::loadDefaults(int expand_env)
  {
    if (tdrpLoad(NULL,
                 _table, &_start_,
                 NULL, expand_env, FALSE)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // sync()
  //
  // Syncs the user struct data back into the parameter table,
  // in preparation for printing.
  //
  // This function alters the table in a consistent manner.
  // Therefore it can be regarded as const.
  //

  void Params::sync(void) const
  {
    tdrpUser2Table(_table, (char *) &_start_);
  }

  ////////////////////////////////////////////
  // print()
  // 
  // Print params file
  //
  // The modes supported are:
  //
  //   PRINT_SHORT:   main comments only, no help or descriptions
  //                  structs and arrays on a single line
  //   PRINT_NORM:    short + descriptions and help
  //   PRINT_LONG:    norm  + arrays and structs expanded
  //   PRINT_VERBOSE: long  + private params included
  //

  void Params::print(FILE *out, tdrp_print_mode_t mode)
  {
    tdrpPrint(out, _table, _className, mode);
  }

  ////////////////////////////////////////////
  // checkAllSet()
  //
  // Return TRUE if all set, FALSE if not.
  //
  // If out is non-NULL, prints out warning messages for those
  // parameters which are not set.
  //

  int Params::checkAllSet(FILE *out)
  {
    return (tdrpCheckAllSet(out, _table, &_start_));
  }

  //////////////////////////////////////////////////////////////
  // checkIsSet()
  //
  // Return TRUE if parameter is set, FALSE if not.
  //
  //

  int Params::checkIsSet(const char *paramName)
  {
    return (tdrpCheckIsSet(paramName, _table, &_start_));
  }

  ////////////////////////////////////////////
  // freeAll()
  //
  // Frees up all TDRP dynamic memory.
  //

  void Params::freeAll(void)
  {
    tdrpFreeAll(_table, &_start_);
  }

  ////////////////////////////////////////////
  // usage()
  //
  // Prints out usage message for TDRP args as passed
  // in to loadFromArgs().
  //

  void Params::usage(ostream &out)
  {
    out << "TDRP args: [options as below]\n"
        << "   [ -params/--params path ] specify params file path\n"
        << "   [ -check_params/--check_params] check which params are not set\n"
        << "   [ -print_params/--print_params [mode]] print parameters\n"
        << "     using following modes, default mode is 'norm'\n"
        << "       short:   main comments only, no help or descr\n"
        << "                structs and arrays on a single line\n"
        << "       norm:    short + descriptions and help\n"
        << "       long:    norm  + arrays and structs expanded\n"
        << "       verbose: long  + private params included\n"
        << "       short_expand:   short with env vars expanded\n"
        << "       norm_expand:    norm with env vars expanded\n"
        << "       long_expand:    long with env vars expanded\n"
        << "       verbose_expand: verbose with env vars expanded\n"
        << "   [ -tdrp_debug] debugging prints for tdrp\n"
        << "   [ -tdrp_usage] print this usage\n";
  }

  ////////////////////////////////////////////
  // arrayRealloc()
  //
  // Realloc 1D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::arrayRealloc(const char *param_name, int new_array_n)
  {
    if (tdrpArrayRealloc(_table, &_start_,
                         param_name, new_array_n)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // array2DRealloc()
  //
  // Realloc 2D array.
  //
  // If size is increased, the values from the last array 
  // entry is copied into the new space.
  //
  // Returns 0 on success, -1 on error.
  //

  int Params::array2DRealloc(const char *param_name,
                             int new_array_n1,
                             int new_array_n2)
  {
    if (tdrpArray2DRealloc(_table, &_start_, param_name,
                           new_array_n1, new_array_n2)) {
      return (-1);
    } else {
      return (0);
    }
  }

  ////////////////////////////////////////////
  // _init()
  //
  // Class table initialization function.
  //
  //

  void Params::_init()

  {

    TDRPtable *tt = _table;

    // Parameter 'Comment 0'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 0");
    tt->comment_hdr = tdrpStrDup("StormShapeSim simulates storm shapes and writes these to a Cartesian MDV file. It then resamples the Cartesian file using a prescribed radar scan strategy, and writes the radar-bases simulation to a CfRadial file.");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'Comment 1'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 1");
    tt->comment_hdr = tdrpStrDup("DEBUGGING");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'debug'
    // ctype is '_debug_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("debug");
    tt->descr = tdrpStrDup("Debug option");
    tt->help = tdrpStrDup("If set, debug messages will be printed appropriately");
    tt->val_offset = (char *) &debug - &_start_;
    tt->enum_def.name = tdrpStrDup("debug_t");
    tt->enum_def.nfields = 3;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("DEBUG_OFF");
      tt->enum_def.fields[0].val = DEBUG_OFF;
      tt->enum_def.fields[1].name = tdrpStrDup("DEBUG_NORM");
      tt->enum_def.fields[1].val = DEBUG_NORM;
      tt->enum_def.fields[2].name = tdrpStrDup("DEBUG_VERBOSE");
      tt->enum_def.fields[2].val = DEBUG_VERBOSE;
    tt->single_val.e = DEBUG_OFF;
    tt++;
    
    // Parameter 'Comment 2'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 2");
    tt->comment_hdr = tdrpStrDup("STORM SHAPES");
    tt->comment_text = tdrpStrDup("Set an array of storm shapes for the simulation.");
    tt++;
    
    // Parameter 'data_set_info'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("data_set_info");
    tt->descr = tdrpStrDup("Label to be used in output data, and path.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &data_set_info - &_start_;
    tt->single_val.s = tdrpStrDup("case1");
    tt++;
    
    // Parameter 'storm_shapes'
    // ctype is '_storm_shape_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("storm_shapes");
    tt->descr = tdrpStrDup("Array of storm shapes.");
    tt->help = tdrpStrDup("The shape centroid is specified. This body is an ellipse in (x,y) cordinates, with the specified z limits. Within the body dbz is constant. Beyond the body limits the dbz values decrease at the specified gradient. Below the specified minimum, the dbz values will be set to missing.");
    tt->array_offset = (char *) &_storm_shapes - &_start_;
    tt->array_n_offset = (char *) &storm_shapes_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(storm_shape_t);
    tt->array_n = 1;
    tt->struct_def.name = tdrpStrDup("storm_shape_t");
    tt->struct_def.nfields = 11;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("centroid_x_km");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_storm_shapes->centroid_x_km - (char *) _storm_shapes;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("centroid_y_km");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_storm_shapes->centroid_y_km - (char *) _storm_shapes;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("body_ellipse_radius_x_km");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &_storm_shapes->body_ellipse_radius_x_km - (char *) _storm_shapes;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("body_ellipse_radius_y_km");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &_storm_shapes->body_ellipse_radius_y_km - (char *) _storm_shapes;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("body_ellipse_rotation_deg");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &_storm_shapes->body_ellipse_rotation_deg - (char *) _storm_shapes;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("body_min_z_km");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &_storm_shapes->body_min_z_km - (char *) _storm_shapes;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("body_max_z_km");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &_storm_shapes->body_max_z_km - (char *) _storm_shapes;
      tt->struct_def.fields[7].ftype = tdrpStrDup("double");
      tt->struct_def.fields[7].fname = tdrpStrDup("body_dbz_at_base");
      tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &_storm_shapes->body_dbz_at_base - (char *) _storm_shapes;
      tt->struct_def.fields[8].ftype = tdrpStrDup("double");
      tt->struct_def.fields[8].fname = tdrpStrDup("body_dbz_at_top");
      tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &_storm_shapes->body_dbz_at_top - (char *) _storm_shapes;
      tt->struct_def.fields[9].ftype = tdrpStrDup("double");
      tt->struct_def.fields[9].fname = tdrpStrDup("dbz_gradient_horiz");
      tt->struct_def.fields[9].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[9].rel_offset = 
        (char *) &_storm_shapes->dbz_gradient_horiz - (char *) _storm_shapes;
      tt->struct_def.fields[10].ftype = tdrpStrDup("double");
      tt->struct_def.fields[10].fname = tdrpStrDup("dbz_gradient_vert");
      tt->struct_def.fields[10].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[10].rel_offset = 
        (char *) &_storm_shapes->dbz_gradient_vert - (char *) _storm_shapes;
    tt->n_struct_vals = 11;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 30;
      tt->struct_vals[1].d = 30;
      tt->struct_vals[2].d = 40;
      tt->struct_vals[3].d = 20;
      tt->struct_vals[4].d = 0;
      tt->struct_vals[5].d = 3;
      tt->struct_vals[6].d = 7;
      tt->struct_vals[7].d = 45;
      tt->struct_vals[8].d = 25;
      tt->struct_vals[9].d = 1.5;
      tt->struct_vals[10].d = 3;
    tt++;
    
    // Parameter 'min_valid_dbz'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("min_valid_dbz");
    tt->descr = tdrpStrDup("Minimum valid DBZ in Cartesian DBZ volume");
    tt->help = tdrpStrDup("Values below this will be set to missing.");
    tt->val_offset = (char *) &min_valid_dbz - &_start_;
    tt->single_val.d = -30;
    tt++;
    
    // Parameter 'Comment 3'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 3");
    tt->comment_hdr = tdrpStrDup("CARTESIAN GRID DETAILS");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'cart_grid'
    // ctype is '_cart_grid_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("cart_grid");
    tt->descr = tdrpStrDup("Cartesian grid parameters.");
    tt->help = tdrpStrDup("For the MDV output file.");
    tt->val_offset = (char *) &cart_grid - &_start_;
    tt->struct_def.name = tdrpStrDup("cart_grid_t");
    tt->struct_def.nfields = 9;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("int");
      tt->struct_def.fields[0].fname = tdrpStrDup("nx");
      tt->struct_def.fields[0].ptype = INT_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &cart_grid.nx - (char *) &cart_grid;
      tt->struct_def.fields[1].ftype = tdrpStrDup("int");
      tt->struct_def.fields[1].fname = tdrpStrDup("ny");
      tt->struct_def.fields[1].ptype = INT_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &cart_grid.ny - (char *) &cart_grid;
      tt->struct_def.fields[2].ftype = tdrpStrDup("int");
      tt->struct_def.fields[2].fname = tdrpStrDup("nz");
      tt->struct_def.fields[2].ptype = INT_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &cart_grid.nz - (char *) &cart_grid;
      tt->struct_def.fields[3].ftype = tdrpStrDup("double");
      tt->struct_def.fields[3].fname = tdrpStrDup("minx");
      tt->struct_def.fields[3].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[3].rel_offset = 
        (char *) &cart_grid.minx - (char *) &cart_grid;
      tt->struct_def.fields[4].ftype = tdrpStrDup("double");
      tt->struct_def.fields[4].fname = tdrpStrDup("miny");
      tt->struct_def.fields[4].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[4].rel_offset = 
        (char *) &cart_grid.miny - (char *) &cart_grid;
      tt->struct_def.fields[5].ftype = tdrpStrDup("double");
      tt->struct_def.fields[5].fname = tdrpStrDup("minz");
      tt->struct_def.fields[5].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[5].rel_offset = 
        (char *) &cart_grid.minz - (char *) &cart_grid;
      tt->struct_def.fields[6].ftype = tdrpStrDup("double");
      tt->struct_def.fields[6].fname = tdrpStrDup("dx");
      tt->struct_def.fields[6].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[6].rel_offset = 
        (char *) &cart_grid.dx - (char *) &cart_grid;
      tt->struct_def.fields[7].ftype = tdrpStrDup("double");
      tt->struct_def.fields[7].fname = tdrpStrDup("dy");
      tt->struct_def.fields[7].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[7].rel_offset = 
        (char *) &cart_grid.dy - (char *) &cart_grid;
      tt->struct_def.fields[8].ftype = tdrpStrDup("double");
      tt->struct_def.fields[8].fname = tdrpStrDup("dz");
      tt->struct_def.fields[8].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[8].rel_offset = 
        (char *) &cart_grid.dz - (char *) &cart_grid;
    tt->n_struct_vals = 9;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].i = 400;
      tt->struct_vals[1].i = 400;
      tt->struct_vals[2].i = 20;
      tt->struct_vals[3].d = -199.5;
      tt->struct_vals[4].d = -199.5;
      tt->struct_vals[5].d = -1;
      tt->struct_vals[6].d = 1;
      tt->struct_vals[7].d = 1;
      tt->struct_vals[8].d = 1;
    tt++;
    
    // Parameter 'Comment 4'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 4");
    tt->comment_hdr = tdrpStrDup("Mode for specifying the radar scan strategy");
    tt->comment_text = tdrpStrDup("Read in a scan file, or specify radar and scan parameters");
    tt++;
    
    // Parameter 'specify_mode'
    // ctype is '_specify_mode_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = ENUM_TYPE;
    tt->param_name = tdrpStrDup("specify_mode");
    tt->descr = tdrpStrDup("Mode for determining radar parameters");
    tt->help = tdrpStrDup("\nSPECIFY_FILE: read in a file, and use that volume for computations.\n\nSPECIFY_RADAR_PARAMS: create a volume based on specified parameters in params file.");
    tt->val_offset = (char *) &specify_mode - &_start_;
    tt->enum_def.name = tdrpStrDup("specify_mode_t");
    tt->enum_def.nfields = 2;
    tt->enum_def.fields = (enum_field_t *)
        tdrpMalloc(tt->enum_def.nfields * sizeof(enum_field_t));
      tt->enum_def.fields[0].name = tdrpStrDup("SPECIFY_FILE");
      tt->enum_def.fields[0].val = SPECIFY_FILE;
      tt->enum_def.fields[1].name = tdrpStrDup("SPECIFY_RADAR_PARAMS");
      tt->enum_def.fields[1].val = SPECIFY_RADAR_PARAMS;
    tt->single_val.e = SPECIFY_RADAR_PARAMS;
    tt++;
    
    // Parameter 'Comment 5'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 5");
    tt->comment_hdr = tdrpStrDup("SPECIFIED INPUT FILE");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'specified_file_path'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("specified_file_path");
    tt->descr = tdrpStrDup("Path for specified file.");
    tt->help = tdrpStrDup("Applies to SPECIFY_FILE mode.");
    tt->val_offset = (char *) &specified_file_path - &_start_;
    tt->single_val.s = tdrpStrDup("./template_cfradial_file.nc");
    tt++;
    
    // Parameter 'Comment 6'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 6");
    tt->comment_hdr = tdrpStrDup("SPECIFIED RADAR PARAMETERS");
    tt->comment_text = tdrpStrDup("Applies to SPECIFY_RADAR_PARAMS mode.");
    tt++;
    
    // Parameter 'radar_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("radar_name");
    tt->descr = tdrpStrDup("Name of radar");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_name - &_start_;
    tt->single_val.s = tdrpStrDup("VIRTUAL");
    tt++;
    
    // Parameter 'radar_location'
    // ctype is '_radar_location_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("radar_location");
    tt->descr = tdrpStrDup("Radar location");
    tt->help = tdrpStrDup("Note that the altitude is in meters MSL.");
    tt->val_offset = (char *) &radar_location - &_start_;
    tt->struct_def.name = tdrpStrDup("radar_location_t");
    tt->struct_def.nfields = 3;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("latitudeDeg");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &radar_location.latitudeDeg - (char *) &radar_location;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("longitudeDeg");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &radar_location.longitudeDeg - (char *) &radar_location;
      tt->struct_def.fields[2].ftype = tdrpStrDup("double");
      tt->struct_def.fields[2].fname = tdrpStrDup("altitudeKm");
      tt->struct_def.fields[2].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[2].rel_offset = 
        (char *) &radar_location.altitudeKm - (char *) &radar_location;
    tt->n_struct_vals = 3;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 40;
      tt->struct_vals[1].d = -105;
      tt->struct_vals[2].d = 0;
    tt++;
    
    // Parameter 'radar_wavelength_cm'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("radar_wavelength_cm");
    tt->descr = tdrpStrDup("Radar wavelength, cm");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &radar_wavelength_cm - &_start_;
    tt->single_val.d = 10;
    tt++;
    
    // Parameter 'beam_width_deg'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("beam_width_deg");
    tt->descr = tdrpStrDup("Radar beamwidth (deg)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &beam_width_deg - &_start_;
    tt->single_val.d = 1;
    tt++;
    
    // Parameter 'scan_name'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("scan_name");
    tt->descr = tdrpStrDup("Volume coverage pattern");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &scan_name - &_start_;
    tt->single_val.s = tdrpStrDup("Unknown");
    tt++;
    
    // Parameter 'gate_spacing_m'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("gate_spacing_m");
    tt->descr = tdrpStrDup("Gate spacing for simulation (m)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &gate_spacing_m - &_start_;
    tt->single_val.d = 250;
    tt++;
    
    // Parameter 'max_range_km'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("max_range_km");
    tt->descr = tdrpStrDup("Max range (km)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &max_range_km - &_start_;
    tt->single_val.d = 225;
    tt++;
    
    // Parameter 'elev_rate_deg_per_sec'
    // ctype is 'double'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = DOUBLE_TYPE;
    tt->param_name = tdrpStrDup("elev_rate_deg_per_sec");
    tt->descr = tdrpStrDup("Rate of rotation in elevation (deg/s)");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &elev_rate_deg_per_sec - &_start_;
    tt->single_val.d = 3;
    tt++;
    
    // Parameter 'sweeps'
    // ctype is '_sweep_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRUCT_TYPE;
    tt->param_name = tdrpStrDup("sweeps");
    tt->descr = tdrpStrDup("Definition of each sweep.");
    tt->help = tdrpStrDup("Elevation angle (deg), azimuth rate (deg/sec).");
    tt->array_offset = (char *) &_sweeps - &_start_;
    tt->array_n_offset = (char *) &sweeps_n - &_start_;
    tt->is_array = TRUE;
    tt->array_len_fixed = FALSE;
    tt->array_elem_size = sizeof(sweep_t);
    tt->array_n = 18;
    tt->struct_def.name = tdrpStrDup("sweep_t");
    tt->struct_def.nfields = 2;
    tt->struct_def.fields = (struct_field_t *)
        tdrpMalloc(tt->struct_def.nfields * sizeof(struct_field_t));
      tt->struct_def.fields[0].ftype = tdrpStrDup("double");
      tt->struct_def.fields[0].fname = tdrpStrDup("elev_deg");
      tt->struct_def.fields[0].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[0].rel_offset = 
        (char *) &_sweeps->elev_deg - (char *) _sweeps;
      tt->struct_def.fields[1].ftype = tdrpStrDup("double");
      tt->struct_def.fields[1].fname = tdrpStrDup("az_rate_deg_per_sec");
      tt->struct_def.fields[1].ptype = DOUBLE_TYPE;
      tt->struct_def.fields[1].rel_offset = 
        (char *) &_sweeps->az_rate_deg_per_sec - (char *) _sweeps;
    tt->n_struct_vals = 36;
    tt->struct_vals = (tdrpVal_t *)
        tdrpMalloc(tt->n_struct_vals * sizeof(tdrpVal_t));
      tt->struct_vals[0].d = 0.5;
      tt->struct_vals[1].d = 11.46;
      tt->struct_vals[2].d = 0.5;
      tt->struct_vals[3].d = 17.1;
      tt->struct_vals[4].d = 0.9;
      tt->struct_vals[5].d = 13.38;
      tt->struct_vals[6].d = 0.9;
      tt->struct_vals[7].d = 17.1;
      tt->struct_vals[8].d = 1.3;
      tt->struct_vals[9].d = 13.38;
      tt->struct_vals[10].d = 1.3;
      tt->struct_vals[11].d = 17.1;
      tt->struct_vals[12].d = 1.8;
      tt->struct_vals[13].d = 13.38;
      tt->struct_vals[14].d = 2.4;
      tt->struct_vals[15].d = 18.06;
      tt->struct_vals[16].d = 3.1;
      tt->struct_vals[17].d = 18.06;
      tt->struct_vals[18].d = 4;
      tt->struct_vals[19].d = 20.52;
      tt->struct_vals[20].d = 5.1;
      tt->struct_vals[21].d = 20.52;
      tt->struct_vals[22].d = 6.4;
      tt->struct_vals[23].d = 20.52;
      tt->struct_vals[24].d = 8;
      tt->struct_vals[25].d = 24.84;
      tt->struct_vals[26].d = 10;
      tt->struct_vals[27].d = 25.62;
      tt->struct_vals[28].d = 12;
      tt->struct_vals[29].d = 25.62;
      tt->struct_vals[30].d = 14;
      tt->struct_vals[31].d = 25.62;
      tt->struct_vals[32].d = 16.7;
      tt->struct_vals[33].d = 25.62;
      tt->struct_vals[34].d = 19.5;
      tt->struct_vals[35].d = 25.62;
    tt++;
    
    // Parameter 'reverse_sweep_order_in_vol'
    // ctype is 'tdrp_bool_t'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = BOOL_TYPE;
    tt->param_name = tdrpStrDup("reverse_sweep_order_in_vol");
    tt->descr = tdrpStrDup("Reverse the order of the sweeps in the volume, but preserve times.");
    tt->help = tdrpStrDup("If TRUE, reverse the order in which the sweeps are stored in the volume. But do not change the times on the rays. This is used for testing purposes and checking for bugs in the analysis.");
    tt->val_offset = (char *) &reverse_sweep_order_in_vol - &_start_;
    tt->single_val.b = pFALSE;
    tt++;
    
    // Parameter 'Comment 7'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = COMMENT_TYPE;
    tt->param_name = tdrpStrDup("Comment 7");
    tt->comment_hdr = tdrpStrDup("WRITING FILES");
    tt->comment_text = tdrpStrDup("");
    tt++;
    
    // Parameter 'cart_data_time'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("cart_data_time");
    tt->descr = tdrpStrDup("Time for Cartesian output volume.");
    tt->help = tdrpStrDup("The data will be stamped with this time.");
    tt->val_offset = (char *) &cart_data_time - &_start_;
    tt->single_val.s = tdrpStrDup("2022 01 01 00 00 00");
    tt++;
    
    // Parameter 'output_dir_mdv'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir_mdv");
    tt->descr = tdrpStrDup("Output directory path for Cartesian MDV files.");
    tt->help = tdrpStrDup("");
    tt->val_offset = (char *) &output_dir_mdv - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/StormShapeSim/mdv");
    tt++;
    
    // Parameter 'output_dir_cfradial'
    // ctype is 'char*'
    
    memset(tt, 0, sizeof(TDRPtable));
    tt->ptype = STRING_TYPE;
    tt->param_name = tdrpStrDup("output_dir_cfradial");
    tt->descr = tdrpStrDup("Output directory path for polar CfRadial files.");
    tt->help = tdrpStrDup("Files will be written to this directory.");
    tt->val_offset = (char *) &output_dir_cfradial - &_start_;
    tt->single_val.s = tdrpStrDup("/tmp/StormShapeSim/cfradial");
    tt++;
    
    // trailing entry has param_name set to NULL
    
    tt->param_name = NULL;
    
    return;
  
  }
