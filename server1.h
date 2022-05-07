
/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __server1_H
#define __server1_H

/** include files **/
#include <list>
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class server1: public Atomic
{
public:
	server1( const string &name = "server1" ) ;	 // Default constructor
	//~server1();					// Destructor
	virtual string className() const;
		//{return "server1";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &clients1;
	const Port &fault;
	const Port &command1;
	const Port &users21;
	const Port &users31;
	Port &users12;
	Port &users13;
	Port &serverstate1;
	Port &noclients1;
	int num, a1,shift12,shift13,current_clients1;
	int message;
	int c;
	int s1;
	Time preparationTime;
	typedef list<Value> ElementList ;
		ElementList elements ;
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	// const Port &in;	// this is an input port named 'in'
	// Port &out ;   	// this is an output port named 'out'
	// Distribution *dist ;
	// Distribution &distribution()	{ return *dist; }
	/**************************************************************************/

	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	//Time sigma;
	
	// Time elapsed since the last state transition until now
	//Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	//Time timeLeft;
};	// class server1

inline
string server1::className() const
{
	return "server1" ;
}


#endif   //__server1_H 
