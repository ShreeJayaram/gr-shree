/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "mango_impl.h"

namespace gr {
  namespace moduleOOK {

    mango::sptr
    mango::make(float interpolator, int amplitude, int offset )
    {
      return gnuradio::get_initial_sptr
        (new mango_impl(interpolator, amplitude, offset));
    }

    /*
     * The private constructor
     */
    mango_impl::mango_impl(float interpolator, int amplitude, int offset )
      : gr::sync_interpolator("mango",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)), interpolator)
    {
 	d_interpolator(interpolator);
	d_offset(offset);
	d_amplitude(amplitude);
     }
	


    /*
     * Our virtual destructor.
     */
    mango_impl::~mango_impl()
    {
    }

    int
    mango_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

	int i;
	int j = 0;
	int ctr = 0;

	while(i < noutput_items) { 
	
		if (in[j] == 0)
			{ 
				out[i++] = offset() - (amplitude()/2);
			}
		if (in[j] == 1)
			{
				out[i++] = offset() + (amplitude()/2);
			}
		ctr++;
		if (ctr >= interpolation()){ 
			ctr = 0;
			j++;
		}
			} 
	
      // Do <+signal processing+>

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace almostfinal */
} /* namespace gr */


	



      
