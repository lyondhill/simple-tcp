#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

using namespace std;
int main ( int argc, int argv[] )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 6000 );

      while ( true )
	{

	  ServerSocket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock >> data;
		  std::cout << data << endl;
		  new_sock << "HAY YOU";
		}
	    }
	  catch ( SocketException& ) {}

	}
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  return 0;
}
