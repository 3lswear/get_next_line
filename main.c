#include <stdio.h>

#include "get_next_line.h"
void read1(int fd)
{
	int ret;
	char buf[33];
	buf[32] = 0;
	while ((ret = read(fd, buf, 32)))
	{
		printf("%s", buf);
		break;
	}
	printf("\n");
}

void read2(int fd)
{
	int ret;
	char buf[33];
	buf[32] = 0;
	while ((ret = read(fd, buf, 32)))
	{
		printf("%s", buf);
		break;
	}
	printf("\n");
}

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
	char *line;
	line = (char *)ft_calloc(sizeof(char), 1);

	fd = open("./texts/game.txt", O_RDONLY);
	get_next_line(fd, &line);
	printf("the line is =>[%s]\n", line);
	get_next_line(fd, &line);
	printf("the line is =>[%s]\n", line);
	close(fd);

	return 0;
}
