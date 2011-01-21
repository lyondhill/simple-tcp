#include "ClientSocket.h"
#include "SocketException.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>

using namespace std;
int main ( int argc, int argv[] )
{
  try
    {

      ClientSocket client_socket ( "localhost", 6000 );
      string reply;
      try
	{
	  client_socket << "use dummy\r\n";
	  client_socket >> reply;
	}
      catch ( SocketException& ) {}

      cout << "We received this response from the server:\n\"" << reply << "\"\n";

    }
  catch ( SocketException& e )
    {
      cout << "Exception was caught: " << e.description() << "\n";
    }

  return 0;
}
