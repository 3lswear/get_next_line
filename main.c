#include <stdio.h>

#include "get_next_line.h"

int main()
{
	char *art = "\n\
               )                      )    (                \n\
 (  (    (  ( /(            (    ) ( /(    )\\(          (   \n\
 )\\))(  ))\\ )\\())    (     ))\\( /( )\\())  ((_)\\  (     ))\\  \n\
((_))\\ /((_|_))/     )\\ ) /((_)\\()|_))/    _((_) )\\ ) /((_) \n\
 (()(_|_)) | |_     _(_/((_))((_)\\| |_    | |(_)_(_/((_))   \n\
/ _` |/ -_)|  _|   | ' \\)) -_) \\ /|  _|   | || | ' \\)) -_)  \n\
\\__, |\\___| \\__|___|_||_|\\___/_\\_\\ \\__|___|_||_|_||_|\\___|  \n\
|___/         |_____|                |_____|                \n\
";

	printf("%s", art);

	int fd;
	char buf[32];
	char **line;

	fd = open("./texts/game.txt", O_RDONLY);
	get_next_line(fd, line);

	return 0;
}
