#ifndef SRTEET_VIEW_API
#define SRTEET_VIEW_API

//apt-get install libghc6-curl-dev
#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>


typedef unsigned short int imgSize;
typedef float degree;

/*
	streetViewParams - struct incapsulate Google street View api params
		latitude - широта
		longitude - довгота
		sensor - bool дані з GPS?
		heading - напрямок по компасу [0; 360]
		fov - масштабування max - 120
		pitch - погляд вверз - низ [90; -90]
*/
struct streetViewParams
{
	imgSize width;
	imgSize height;
	degree latitude; 
	degree longitude;
	short sensor;
	degree heading;
	degree fov;
	degree pitch;
};
typedef struct streetViewParams streetViewParams;

/*
	streetViewAnswer - struct
		code if not 0 - error
		image - jpg image 
*/
struct streetViewAnswer
{
	long size;
	char* image;
};
typedef struct streetViewAnswer streetViewAnswer;

/*
	get image from google street view 
*/
streetViewAnswer getStreetViewImage(const streetViewParams* const params);

#endif