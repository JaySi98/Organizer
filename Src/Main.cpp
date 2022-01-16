#include <iostream>
#include <Include/Config.h>

#ifdef ADD_NCURSES
   #include <ncurses.h>
#endif

#ifdef ADD_BOOST
    #include <boost/regex.hpp>
#endif

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " Version: " 
              << Organizer_VERSION_MAJOR << "."
              << Organizer_VERSION_MINOR << std::endl;

   return EXIT_SUCCESS;
}