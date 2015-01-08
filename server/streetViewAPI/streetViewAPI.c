#include "streetViewAPI.h"

char * const getGoogleURLByParams(const streetViewParams* const params) 
{
	return "http://maps.googleapis.com/maps/api/streetview?size=600x300&location=Chagrin%20Falls,%20OH&heading=0&pitch=10&sensor=false=120";
}

streetViewAnswer getStreetViewImage(const streetViewParams* const params) 
{
	long lSize;
	CURLcode ret; 
	FILE* dataFile = tmpfile();
	CURL *hnd = curl_easy_init();
	curl_easy_setopt(hnd, CURLOPT_URL, getGoogleURLByParams(params));
	curl_easy_setopt(hnd, CURLOPT_WRITEDATA, dataFile);
	ret = curl_easy_perform(hnd);
	curl_easy_cleanup(hnd);
	
	if (ret)
	{
		fputs("getStreetViewImage. GET request error.\n",stderr);
		exit(1);
	}

	if (!dataFile)
	{
		fputs("getStreetViewImage. Cannot create tmp file.\n",stderr);
		exit(1);
	}

	//get file length
	fseek( dataFile , 0L , SEEK_END);
	lSize = ftell( dataFile );
	rewind( dataFile );

	//allocate memory for entire content
	char *buffer = calloc( 1, lSize+1 );

	if( !buffer ) 
	{
		fputs("getStreetViewImage. Memory alloc fails",stderr);
		exit(1);
	}

	/* copy the file into the buffer */
	if( 1!=fread( buffer , lSize, 1 , dataFile) ) 
	{
		free(buffer);
		fputs("entire read \n",stderr);
		exit(1);
	}

	fclose(dataFile);

	streetViewAnswer res = {
		.size = lSize,
		.image = buffer
	};

	return res;
}