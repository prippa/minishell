#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define UP (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
#define DOWN (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
#define RIGHT (buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
#define LEFT (buf[0] == 27 && buf[1] == 91 && buf[2] == 68)

#define WTF_UP (buf[0] == 27 && buf[1] == 91 && buf[2] == 72)
#define WTF_DOWN (buf[0] == 27 && buf[1] == 91 && buf[2] == 70)

#define TAB (buf[0] == 9)
#define BACK_SPACE (buf[0] == 127)
#define CTRL_D (buf[0] == 4)

int main(void)
{
    char buf[8];
    static struct termios oldtio, newtio;
    tcgetattr(0, &oldtio);
    newtio = oldtio;
    newtio.c_lflag &= ~ICANON;
    newtio.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &newtio);
    while (1)
    {
    	bzero(buf, sizeof(buf));
    	read(0, buf, 8);

        if UP write(1, "UP", strlen("UP"));
        if DOWN write(1, "DOWN", strlen("DOWN"));
        if RIGHT write(1, "RIGHT", strlen("RIGHT"));
        if LEFT write(1, "LEFT", strlen("LEFT"));
		if TAB write(1, "TAB", strlen("TAB"));
		if CTRL_D write(1, "CTRL_D", strlen("CTRL_D"));
		if BACK_SPACE
		{
			write(1, "\b", 1);
			write(1, " ", 1);
			write(1, "\b", 1);
		}
		if (UP || DOWN || RIGHT || LEFT || TAB || BACK_SPACE || CTRL_D || WTF_UP || WTF_DOWN)
			continue ;
        if (buf[0] == 'q') {
            break;
        }
		write(1, buf, 8);
    }
    write(1, "\n", 1);
    tcsetattr(0, TCSANOW, &oldtio);
    return 0;
}