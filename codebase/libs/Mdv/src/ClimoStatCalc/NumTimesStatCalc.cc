// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
// ** Copyright UCAR (c) 1990 - 2016                                         
// ** University Corporation for Atmospheric Research (UCAR)                 
// ** National Center for Atmospheric Research (NCAR)                        
// ** Boulder, Colorado, USA                                                 
// ** BSD licence applies - redistribution and use in source and binary      
// ** forms, with or without modification, are permitted provided that       
// ** the following conditions are met:                                      
// ** 1) If the software is modified to produce derivative works,            
// ** such modified software should be clearly marked, so as not             
// ** to confuse it with the version available from UCAR.                    
// ** 2) Redistributions of source code must retain the above copyright      
// ** notice, this list of conditions and the following disclaimer.          
// ** 3) Redistributions in binary form must reproduce the above copyright   
// ** notice, this list of conditions and the following disclaimer in the    
// ** documentation and/or other materials provided with the distribution.   
// ** 4) Neither the name of UCAR nor the names of its contributors,         
// ** if any, may be used to endorse or promote products derived from        
// ** this software without specific prior written permission.               
// ** DISCLAIMER: THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS  
// ** OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED      
// ** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.    
// *=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=* 
/*********************************************************************
 * NumTimesStatCalc: Class for calculating the number of observations statistic.
 *
 * RAP, NCAR, Boulder CO
 *
 * July 2004
 *
 * Nancy Rehak
 *
 *********************************************************************/

#include <Mdv/climo/NumTimesStatCalc.hh>
#include <toolsa/str.h>

using namespace std;


/**********************************************************************
 * Constructor
 */

NumTimesStatCalc::NumTimesStatCalc(const bool debug_flag,
				   const bool check_z_levels) :
  StatCalc(debug_flag, check_z_levels)
{
}


/**********************************************************************
 * Destructor
 */

NumTimesStatCalc::~NumTimesStatCalc(void)
{
}
  

/**********************************************************************
 * calcStatistic() - Calculate the statistic field using the given
 *                   information.
 */

MdvxField *NumTimesStatCalc::calcStatistic(const DsMdvx &climo_file,
					   const MdvxField &data_field,
					   const DateTime &climo_time)
{
  // Construct the statistic field name

  string data_field_name = data_field.getFieldHeader().field_name_long;
  
  // Extract the existing num times field from the climatolog file, if
  // there  is one.  If there is an existing field, we will update
  // the running num times.  If there isn't an existing field, we will
  // create a new one.

  string climo_field_name =
    _getStatFieldName(data_field_name).substr(0, MDV_LONG_FIELD_LEN);
  
  MdvxField *curr_num_times_field =
    climo_file.getField(climo_field_name.c_str());
  MdvxField *new_num_times_field = 0;
  
  if (curr_num_times_field == 0)
  {
    if (_debug)
      cerr << "   Creating " << climo_field_name << " statistic " << endl;
    
    new_num_times_field = _createField(data_field, climo_time);
  }
  else
  {
    if (_debug)
      cerr << "   Updating " << climo_field_name << " statistic " << endl;
    
    new_num_times_field = _updateField(climo_file, data_field,
				       *curr_num_times_field);
  }
  
  return new_num_times_field;
}


/**********************************************************************
 *              Private Member Functions                              *
 **********************************************************************/

/*********************************************************************
 * _createField() - Create a new num times climatology field from the
 *                  given data field.
 *
 * Return the newly created field on success, 0 on failure.
 */

MdvxField *NumTimesStatCalc::_createField(const MdvxField &data_field,
					  const DateTime &climo_time) const
{
  static const string method_name = "NumTimesStatCalc::_createField()";

  // Create the field header

  Mdvx::field_header_t field_hdr = data_field.getFieldHeader();;
  
  field_hdr.forecast_delta = 0;
  field_hdr.forecast_time = climo_time.utime();
  
  field_hdr.encoding_type = Mdvx::ENCODING_FLOAT32;
  field_hdr.data_element_nbytes = 4;
  field_hdr.volume_size = field_hdr.nx * field_hdr.ny *
    field_hdr.nz * field_hdr.data_element_nbytes;
  field_hdr.bad_data_value = -1.0;
  field_hdr.missing_data_value = -1.0;
  field_hdr.compression_type = Mdvx::COMPRESSION_NONE;
  field_hdr.transform_type = Mdvx::DATA_TRANSFORM_NONE;
  field_hdr.scaling_type = Mdvx::SCALING_NONE;
  
  STRcopy(field_hdr.field_name_long,
	  _getStatFieldName(field_hdr.field_name_long).c_str(),
	  MDV_LONG_FIELD_LEN);
  STRcopy(field_hdr.field_name,
	  _getStatFieldName(field_hdr.field_name).c_str(),
	  MDV_SHORT_FIELD_LEN);
  STRcopy(field_hdr.units, "count", MDV_UNITS_LEN);
  
  MdvxField *num_times_field = new MdvxField(field_hdr,
					     data_field.getVlevelHeader(),
					     NULL, true);
  if (num_times_field == 0)
  {
    cerr << "ERROR: " << method_name << endl;
    cerr << "Error creating num times field" << endl;
    
    return 0;
  }
  
  // Fill in the values

  fl32 *num_times_vol = (fl32 *)num_times_field->getVol();
  
  int vol_size = field_hdr.nx * field_hdr.ny * field_hdr.nz;
  
  for (int i = 0; i < vol_size; ++i)
    num_times_vol[i] = 1;
  
  return num_times_field;
}


/*********************************************************************
 * _updateField() - Create a new num times climatology field that is an
 *                  update of the current num obs field using the given
 *                  information.
 *
 * Return the newly created field on success, 0 on failure.
 */

MdvxField *NumTimesStatCalc::_updateField(const DsMdvx &climo_file,
					  const MdvxField &data_field,
					  const MdvxField &curr_num_times_field) const
{
  static const string method_name = "NumTimesStatCalc::_updateField()";

  // Make sure the fields match so we can update the climos

  if (!_fieldsMatch(data_field, curr_num_times_field))
    return 0;
  
  // Create the new field as a copy of the original field

  MdvxField *new_num_times_field = new MdvxField(curr_num_times_field);
  
  // Loop through the new field values, incrementing the number of times.

  Mdvx::field_header_t num_times_field_hdr =
    new_num_times_field->getFieldHeader();
  
  fl32 *num_times_data = (fl32 *)new_num_times_field->getVol();
  
  int volume_size =
    num_times_field_hdr.nx * num_times_field_hdr.ny * num_times_field_hdr.nz;
  
  for (int i = 0; i < volume_size; ++i)
    ++num_times_data[i];
  
  return new_num_times_field;
}
