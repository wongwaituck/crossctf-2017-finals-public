#include <unistd.h>
#include <errno.h>

main( int argc, char ** argv, char ** envp )
{
      if( setgid(getegid()) ) perror( "setgid" );
      if( setuid(geteuid()) ) perror( "setuid" );
      envp = 0; /* blocks IFS attack on non-bash shells */
      system("/bin/cat /home/tastyriffs/flag");
      perror( argv[0] );
      return errno;
}
