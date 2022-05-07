/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "server2.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: server2
* Description: constructor
********************************************************************/
server2::server2( const string &name )
: Atomic( name )
,users12(addInputPort("users12"))
,command2(addInputPort("command2"))
,users21( addOutputPort( "users21" ) )
,noclients2( addOutputPort( "noclients2" ) )
,serverstate2( addOutputPort( "serverstate2" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}



/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &server2::initFunction()
{
   num2=0;
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &server2::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()==users12)
	{
		num2=num2+msg.value();
		sendOutput( msg.time(), noclients2, num2) ;
	}
	
	if(msg.port()==command2)
	{
		if(msg.value()==21)                    //send clients to server1
		{
		sendOutput( msg.time(), users21, num2) ;
		sendOutput( msg.time(), serverstate2,0) ; //server2 is inactive
		num2=0;                                //clients on server2 becomes zero
		}
	}

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &server2::internalFunction( const InternalMessage & )
{

	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &server2::outputFunction( const InternalMessage &msg )
{
	
	return *this;

}

server2::~server2()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
