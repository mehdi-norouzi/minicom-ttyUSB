#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("%s\r\n", "Enter the file name ...");
		return 0;
	}

	FILE *fp;
	fp = fopen(argv[1], "r");
	uint8_t command[255];
	uint8_t value;
	int usbdev;

system("sudo stty -F /dev/ttyUSB0 115200 cs8 -cstopb -parity -icanon min 1 time 1"); //8N1
	usbdev = open("/dev/ttyUSB0", O_RDWR);

	while (fscanf(fp, "%s", command) == 1) {
		printf("%s", command);
		value = atoi(command);
		write(usbdev, &value, 1);
	}

	printf("sent file: %s\r\n", argv[1]);


	fclose(fp);

	close(usbdev);

	return 0;
}

