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
	printf("BUFFER_SIZE =>\t[%u]\n", BUFFER_SIZE);

	int fd;
	char *line;
	/* line = (char *)ft_calloc(sizeof(char), 1); */

	fd = open("./texts/game.txt", O_RDONLY);
	/* fd = open("./texts/among.txt", O_RDONLY); */
	/* fd = 1; */
	while (get_next_line(fd, &line))
	{
		printf("the line is =>[%s]\n", line);
		/* printf("%s\n", line); */
		free(line);
	}
	free(line);

	close(fd);

	return 0;
}
