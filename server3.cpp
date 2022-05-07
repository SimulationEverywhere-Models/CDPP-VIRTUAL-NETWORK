/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "server3.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: server3
* Description: constructor
********************************************************************/
server3::server3( const string &name )
: Atomic( name )
,users13(addInputPort("users13"))
,command3(addInputPort("command3"))
,users31( addOutputPort( "users31" ) )
,noclients3( addOutputPort( "noclients3" ) )
,serverstate3( addOutputPort( "serverstate3" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &server3::initFunction()
{
  num3=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &server3::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()==users13)
	{
		num3=num3+msg.value();
		sendOutput( msg.time(), noclients3, num3) ;
	}

	if(msg.port()==command3)
	{
		if(msg.value()==31)                    //send clients to server1
		{
		sendOutput( msg.time(), users31, num3) ;
		sendOutput( msg.time(), serverstate3,0) ; //server2 is inactive
		num3=0;                                //clients on server2 becomes zero
		sendOutput( msg.time(), noclients3, num3) ;

		}
	}

	
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &server3::internalFunction( const InternalMessage & )
{

	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &server3::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	
	return *this;

}

server3::~server3()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
