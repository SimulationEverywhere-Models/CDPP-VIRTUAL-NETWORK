/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "server1.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: server1
* Description: constructor
********************************************************************/
server1::server1( const string &name )
: Atomic( name )
,clients1( addInputPort( "clients1" ) )
,fault(addInputPort("fault"))
,command1(addInputPort("command1"))
,users21(addInputPort("users21"))
,users31(addInputPort("users31"))
, serverstate1( addOutputPort( "serverstate1" ) )
, noclients1( addOutputPort( "noclients1" ) )
, users12( addOutputPort( "users12" ) )
,users13( addOutputPort( "users13" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}


/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &server1::initFunction()
{
	MainSimulator::Instance().outputStream() << "int" << "\n";
s1=1;
	num=0;

	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &server1::externalFunction( const ExternalMessage &msg )
{
	if(msg.port()== clients1 )
	  {
		MainSimulator::Instance().outputStream() << "EXT" << "\n";
		message=static_cast < int > (msg.value());
		a1=(msg.value())/10;
		if((message%10)==0)           //clients IN
		 {num= num+a1;}
		if((message%10)==1)            //clients OUT
			{num= num-a1;}

		current_clients1=num;
		if(s1==1)
		{
		sendOutput( msg.time(), noclients1, num) ;
        sendOutput( msg.time(), serverstate1, 1) ;

		}
		if(s1==0)
		{
			sendOutput( msg.time(), users13, num) ;
		}

	  }
	if(msg.port()== command1)
	{

         if(msg.value() == 12)        // send clients to server2
         {
        	 shift12=num-100;
        	 num=100;
        	 current_clients1=num;           //update number of clients
        	 sendOutput( msg.time(), users12, shift12) ;
     		sendOutput( msg.time(), noclients1, num) ;
         }
         if(msg.value() == 13)            //send clients to server3
         {
        	 current_clients1=0;
        	 sendOutput(msg.time(),users13,num);
        	 num=0;
        	 MainSimulator::Instance().outputStream() << "current_clients1="<<current_clients1 << "\n";
         }

	}

	if (msg.port()== fault)
	{
		MainSimulator::Instance().outputStream() << "fault" << "\n";
		c=static_cast < int > (msg.value());
        if(msg.value()==1)
        {
		sendOutput( msg.time(),serverstate1,0) ;            //server is inactive
		MainSimulator::Instance().outputStream() << "Server1:inactive" << "\n";
        s1=0;
        }
        if(msg.value()==0)
        {sendOutput(msg.time(),serverstate1,1);             //server1 is active
        MainSimulator::Instance().outputStream() << "Server1: active" << "\n";
        s1=1;

        }
	}
   if(msg.port()==users21)
   {
	   num=num+msg.value();
	   current_clients1=num;
	   sendOutput( msg.time(), noclients1, num) ;
	   sendOutput( msg.time(), serverstate1, 1) ;
   }

   if(msg.port()==users31)
   {
        num=msg.value();
	   sendOutput( msg.time(), noclients1, num) ;

   }
	
	
	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &server1::internalFunction( const InternalMessage &)
{
	//TODO: implement the internal function here

	MainSimulator::Instance().outputStream() << "internal fn" << "\n";

	passivate();
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &server1::outputFunction( const InternalMessage &msg )
{

}

//server1::~server1()
//{
	//TODO: add destruction code here. Free distribution memory, etc. 
//}

