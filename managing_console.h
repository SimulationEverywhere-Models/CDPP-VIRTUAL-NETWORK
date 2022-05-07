/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __managing_console_H
#define __managing_console_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class managing_console: public Atomic
{
public:
	managing_console( const string &name = "managing_console" ) ;	 // Default constructor
	~managing_console();					// Destructor
	virtual string className() const
		{return "managing_console";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &serverstate1;
	const Port &serverstate2;
	const Port &serverstate3;
	const Port &noclients1;
	const Port &noclients2;
	const Port &noclients3;
	Port &command1;
	Port &command2;
	Port &command3;
	Port &serverstates;
	Port &noclients;
	int s;
	int s3;
	int s2;
	Time preparationTime;
};	// class managing_console


#endif   //__managing_console_H 
