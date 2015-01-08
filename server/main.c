#include "streetViewAPI/streetViewAPI.h"

int main(int argc, char const *argv[])
{
	streetViewAnswer img = getStreetViewImage(NULL);
	printf("imgSize: %li %s\n", img.size, img.image);

	FILE *fp;

	if((fp=fopen("test.jpg", "wb"))==NULL) {
		printf("Не удается открыть файл.\n");
		exit(1);
	}

	fwrite(img.image, img.size, 1, fp);

	fclose( fp );
	free( img.image );
	return 0;
}