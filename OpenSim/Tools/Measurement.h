#ifndef __Measurement_h__
#define __Measurement_h__

// Measurement.h
// Author: Peter Loan
/*
 * Copyright (c) 2006, Stanford University. All rights reserved. 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included 
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


// INCLUDE
#include <iostream>
#include <string>
#include <math.h>
#include "osimToolsDLL.h"
#include <OpenSim/Common/PropertyObj.h>
#include <OpenSim/Common/PropertyBool.h>
#include <OpenSim/Common/Storage.h>
#include <OpenSim/Common/Scale.h>
#include <OpenSim/Common/ScaleSet.h>
#include "MarkerPairSet.h"
#include <OpenSim/Simulation/Model/BodyScaleSet.h>

#ifdef SWIG
	#ifdef OSIMTOOLS_API
		#undef OSIMTOOLS_API
		#define OSIMTOOLS_API
	#endif
#endif

namespace OpenSim {

//=============================================================================
//=============================================================================
/**
 * A class implementing a measurement (the distance between one or more pairs
 * of markers, used to scale a model).
 *
 * @author Peter Loan
 * @version 1.0
 */
class OSIMTOOLS_API Measurement : public Object  
{
	OPENSIM_DECLARE_DERIVED(Measurement,Object);

//=============================================================================
// DATA
//=============================================================================
protected:
	PropertyObj _markerPairSetProp;
	MarkerPairSet &_markerPairSet;

	PropertyObj _bodyScaleSetProp;
	BodyScaleSet &_bodyScaleSet;

	PropertyBool _applyProp;
	bool &_apply;

//=============================================================================
// METHODS
//=============================================================================
	//--------------------------------------------------------------------------
	// CONSTRUCTION
	//--------------------------------------------------------------------------
public:
	Measurement();
	Measurement(const Measurement &aMeasurement);
	virtual ~Measurement();
	virtual Object* copy() const;

#ifndef SWIG
	Measurement& operator=(const Measurement &aMeasurement);
#endif
   void copyData(const Measurement &aMeasurement);

	BodyScaleSet &getBodyScaleSet() { return _bodyScaleSet; }

	MarkerPairSet& getMarkerPairSet() { return _markerPairSet; }
	int getNumMarkerPairs() const { return _markerPairSet.getSize(); }
	const MarkerPair& getMarkerPair(int aIndex) const { return *_markerPairSet[aIndex]; }

	bool getApply() const { return _apply; }
	void setApply(bool aApply) { 
		_apply = aApply;
		_applyProp.setUseDefault(false);
	}

	void applyScaleFactor(double aFactor, ScaleSet& aScaleSet);

	/* Register types to be used when reading a Measurement object from xml file. */
	static void registerTypes();

private:
	void setNull();
	void setupProperties();
//=============================================================================
};	// END of class Measurement
//=============================================================================
//=============================================================================

} // end of namespace OpenSim

#endif // __Measurement_h__


