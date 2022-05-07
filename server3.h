/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __server3_H
#define __server3_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class server3: public Atomic
{
public:
	server3( const string &name = "server3" ) ;	 // Default constructor
	~server3();					// Destructor
	virtual string className() const
		{return "server3";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &users13;
	const Port &command3;
	Port &users31;
	Port &serverstate3;
	Port &noclients3;
	int num3;
	Time preparationTime;
	
	};	// class server3


#endif   //__server3_H 
