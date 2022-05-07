/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "managing_console.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: managing_console
* Description: constructor
********************************************************************/
managing_console::managing_console( const string &name )
: Atomic( name )
,serverstate1(addInputPort("serverstate1"))
,serverstate2(addInputPort("serverstate2"))
,serverstate3(addInputPort("serverstate3"))
,noclients1(addInputPort("noclients1"))
,noclients2(addInputPort("noclients2"))
,noclients3(addInputPort("noclients3"))
,command1( addOutputPort( "command1" ) )
,command2( addOutputPort( "command2" ) )
,command3( addOutputPort( "command3" ) )
,serverstates( addOutputPort( "serverstates" ) )
,noclients( addOutputPort( "noclients" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}



/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &managing_console::initFunction()
{ s=1;
  s3=0;
  s2=0;
   passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &managing_console::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()==noclients1 && s==1)         //if s=1 then server-1 is active and then mananging console will check number of clients
	{
      MainSimulator::Instance().outputStream() << "clients on server1: " <<msg.value()<< "\n";
		if(msg.value()>=101)
		{
			sendOutput( msg.time(), command1, 12) ;   //command to shift clients to server2
			s2=1;
		}
		if(msg.value()<=30)
		{
			if(s2==1)
			{
			sendOutput( msg.time(), command2, 21) ;  //command to shift clients to server1
			}
		}

	}
	if(msg.port()==noclients1 && s3==1)
	{
		sendOutput( msg.time(), command1, 13) ;
		sendOutput(msg.time(),serverstates,31);
		s3=1;
	}

	if(msg.port()==serverstate1)
	{
		if(msg.value()==1)
		{
			s=1;
			MainSimulator::Instance().outputStream() << "Server1: active" << "\n";
			sendOutput(msg.time(),serverstates,11);
			if(s3==1)
			{
			sendOutput( msg.time(), command3, 31) ;
			sendOutput(msg.time(),serverstates,30);
			s3=0;
			}
		}
		if(msg.value()==0)
		{
			s=0;
			MainSimulator::Instance().outputStream() << "Server1: inactive" << "\n";
			sendOutput(msg.time(),serverstates,10);
			sendOutput( msg.time(), command1, 13) ;
			sendOutput(msg.time(),serverstates,31);
			s3=1;
		}
	}
	if(msg.port()==noclients2)
	{
		MainSimulator::Instance().outputStream() << "Server2: active" << "\n";
		sendOutput(msg.time(),serverstates,21);            //server-2 is active
		MainSimulator::Instance().outputStream() << "clients on server2: " <<msg.value()<< "\n";
		sendOutput( msg.time(), noclients,msg.value()) ;
    }
	if(msg.port()==noclients3)
	{
		MainSimulator::Instance().outputStream() << "Server3: active" << "\n";
		sendOutput(msg.time(),serverstates,31);            //server-3 is active
		MainSimulator::Instance().outputStream() << "clients on server3: " <<msg.value()<< "\n";
		sendOutput( msg.time(), noclients,msg.value()) ;
	}
	if(msg.port()==serverstate2)
	{
		if(msg.value()==1)
		{
			MainSimulator::Instance().outputStream() << "Server2: active" << "\n";
			sendOutput(msg.time(),serverstates,21);            //server-2 is active
		}
		if(msg.value()==0)
		{
			MainSimulator::Instance().outputStream() << "Server2: inactive" << "\n";
			sendOutput(msg.time(),serverstates,20);            //server-2 is inactive
			s2=0;
		}
	}
	if(msg.port()==serverstate3)
		{
			if(msg.value()==1)
			{
				MainSimulator::Instance().outputStream() << "Server3: active" << "\n";
				sendOutput(msg.time(),serverstates,31);            //server-3 is active
			}
			if(msg.value()==0)
			{
				MainSimulator::Instance().outputStream() << "Server3: inactive" << "\n";
				sendOutput(msg.time(),serverstates,30);            //server-3 is inactive
			}
		}

		return *this ;
 }


/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &managing_console::internalFunction( const InternalMessage & )
{
	//TODO: implement the internal function here


	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &managing_console::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	
	return *this;

}

managing_console::~managing_console()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
