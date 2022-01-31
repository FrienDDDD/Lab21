#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){

	double Area;
	double cornerR1[4][2] = {{R1->x,R1->y},{R1->x+R1->w,R1->y},{R1->x,R1->y-R1->h},{R1->x+R1->w,R1->y-R1->h}} ;
	double cornerR2[4][2]  = {{R2->x,R2->y},{R2->x+R2->w,R2->y},{R2->x,R2->y-R2->h},{R2->x+R2->w,R2->y-R2->h}};
	
	
	if(cornerR1[0][1] <= cornerR2[0][1] && cornerR1[1][1] <= cornerR2[1][1] && cornerR1[2][1] >= cornerR2[2][1] && cornerR1[3][1] >= cornerR2[3][1] && cornerR1[0][0] >= cornerR2[0][0]  && cornerR1[1][0] <= cornerR2[1][0] && cornerR1[2][0] >= cornerR2[2][0] && cornerR1[3][0] <= cornerR2[3][0]){
		Area = R1->w*R1->h ;
	}if(cornerR2[0][1] <= cornerR1[0][1] && cornerR2[1][1] <= cornerR1[1][1] && cornerR2[2][1] >= cornerR1[2][1] && cornerR2[3][1] >= cornerR1[3][1] && cornerR2[0][0] >= cornerR1[0][0]  && cornerR2[1][0] <= cornerR1[1][0] && cornerR2[2][0] >= cornerR1[2][0] && cornerR2[3][0] <= cornerR1[3][0]){
		Area = R2->w*R2->h ;
	}
	
	
	if(cornerR1[0][1] <= cornerR2[0][1] && cornerR1[1][1] <= cornerR2[1][1] && cornerR1[2][1] <= cornerR2[2][1] && cornerR1[3][1] <= cornerR2[3][1] && cornerR1[0][0] <= cornerR2[0][0]  && cornerR1[1][0] <= cornerR2[1][0] && cornerR1[2][0] <= cornerR2[2][0] && cornerR1[3][0] <= cornerR2[3][0]){
		Area = (R1->w-(R2->x-R1->x))*(R2->h-(R2->y-R1->y));
	}if(cornerR2[0][1] <= cornerR1[0][1] && cornerR2[1][1] <= cornerR1[1][1] && cornerR2[2][1] <= cornerR1[2][1] && cornerR2[3][1] <= cornerR1[3][1] && cornerR2[0][0] <= cornerR1[0][0]  && cornerR2[1][0] <= cornerR1[1][0] && cornerR2[2][0] <= cornerR1[2][0] && cornerR2[3][0] <= cornerR1[3][0]){
		Area = (R2->w-(R1->x-R2->x))*(R1->h-(R1->y-R2->y));
	}
	
	
	if(cornerR1[0][1] >= cornerR2[0][1] && cornerR1[1][1] >= cornerR2[1][1] && cornerR1[2][1] >= cornerR2[2][1] && cornerR1[3][1] >= cornerR2[3][1] && cornerR1[0][0] <= cornerR2[0][0]  && cornerR1[1][0] <= cornerR2[1][0] && cornerR1[2][0] <= cornerR2[2][0] && cornerR1[3][0] <= cornerR2[3][0]){
		Area = (R1->w-(R2->x-R1->x))*(R2->h-(R1->y-R2->y));
	}if(cornerR2[0][1] >= cornerR1[0][1] && cornerR2[1][1] >= cornerR1[1][1] && cornerR2[2][1] >= cornerR1[2][1] && cornerR2[3][1] >= cornerR1[3][1] && cornerR2[0][0] <= cornerR1[0][0]  && cornerR2[1][0] <= cornerR1[1][0] && cornerR2[2][0] <= cornerR1[2][0] && cornerR2[3][0] <= cornerR1[3][0]){
		Area = (R2->w-(R1->x-R2->x))*(R1->h-(R2->y-R1->y));
	}
	
	
	if(cornerR1[0][1] >= cornerR2[0][1] && cornerR1[1][1] >= cornerR2[1][1] && cornerR1[2][1] >= cornerR2[2][1] && cornerR1[3][1] >= cornerR2[3][1] && cornerR1[0][0] >= cornerR2[0][0]  && cornerR1[1][0] <= cornerR2[1][0] && cornerR1[2][0] >= cornerR2[2][0] && cornerR1[3][0] <= cornerR2[3][0]){
		Area = R1->w*(R1->h-(R1->y-R2->y));
	}if(cornerR2[0][1] >= cornerR1[0][1] && cornerR2[1][1] >= cornerR1[1][1] && cornerR2[2][1] >= cornerR1[2][1] && cornerR2[3][1] >= cornerR1[3][1] && cornerR2[0][0] >= cornerR1[0][0]  && cornerR2[1][0] <= cornerR1[1][0] && cornerR2[2][0] >= cornerR1[2][0] && cornerR2[3][0] <= cornerR1[3][0]){
		Area = R2->w*(R2->h-(R2->y-R1->y));
	}
	
	
	if(cornerR1[0][1] >= cornerR2[0][1] && cornerR1[1][1] >= cornerR2[1][1] && cornerR1[2][1] <= cornerR2[2][1] && cornerR1[3][1] <= cornerR2[3][1] && cornerR1[0][0] <= cornerR2[0][0]  && cornerR1[1][0] <= cornerR2[1][0] && cornerR1[2][0] <= cornerR2[2][0] && cornerR1[3][0] <= cornerR2[3][0]){
		Area = R2->h*(R1->x+R1->w-R2->x);
	}if(cornerR2[0][1] >= cornerR1[0][1] && cornerR2[1][1] >= cornerR1[1][1] && cornerR2[2][1] <= cornerR1[2][1] && cornerR2[3][1] <= cornerR1[3][1] && cornerR2[0][0] <= cornerR1[0][0]  && cornerR2[1][0] <= cornerR1[1][0] && cornerR2[2][0] <= cornerR1[2][0] && cornerR2[3][0] <= cornerR1[3][0]){
		Area = R1->h*(R2->x+R2->w-R1->x);
	}
	
	
	if(cornerR1[0][0] >= cornerR2[1][0]  && cornerR1[1][0] >= cornerR2[1][0] && cornerR1[2][0] >= cornerR2[1][0] && cornerR1[3][0] >= cornerR2[1][0]){
		Area = 0;
	}if(cornerR2[0][0] >= cornerR1[1][0]  && cornerR2[1][0] >= cornerR1[1][0] && cornerR2[2][0] >= cornerR1[1][0] && cornerR2[3][0] >= cornerR1[1][0]){
		Area = 0;
	}
	
	
	return Area ;

}


