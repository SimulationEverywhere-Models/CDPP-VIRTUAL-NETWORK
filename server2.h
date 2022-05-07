/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __server2_H
#define __server2_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class server2: public Atomic
{
public:
	server2( const string &name = "server2" ) ;	 // Default constructor
	~server2();					// Destructor
	virtual string className() const
		{return "server2";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &users12;
	const Port &command2;
	Port &users21;
	Port &serverstate2;
	Port &noclients2;
	int num2;
	Time preparationTime;
};	// class server2


#endif   //__server2_H 
