#include <stdlib.h>

typedef struct{
	int x;
	int y;
} P;

class avion
{
	private:
		P *points;
	public:
		avion(int x,int y);
		~avion();
	P* getPoints();
	bool rotateLeft(int height,int width);

	bool goLeft();
	bool goUp();
	bool goRight(int width);
	bool goDown(int height);
	
};

avion::~avion()
{
	free(points);
}

bool avion::goDown(int height)
{
	if(points[0].x<height && points[1].x<height && points[5].x<height && points[3].x<height)
	  {
	  	for(int i=0;i<8;i++)
	  	   points[i].x++;
	  	   return true;
	  }
	  return false;
}

bool avion::goRight(int width)
{
	if(points[0].y<width && points[1].y<width && points[5].y<width && points[3].y<width)
	  {
	  	for(int i=0;i<8;i++)
	  	   points[i].y++;
	  	   return true;
	  }
	  return false;
}

bool avion::goUp()
{
	if(points[0].x>0 && points[1].x>0 && points[5].x>0 && points[3].x>0)
	  {
	  	for(int i=0;i<8;i++)
	  	   points[i].x--;	  
		  return true;
	  }
	  return false;
}

bool avion::goLeft()
{
	if(points[0].y>0 && points[1].y>0 && points[5].y>0 && points[3].y>0)
	  {
	  	for(int i=0;i<8;i++)
	  	   points[i].y--;
	  	   return true;
	  }
	  return false;
}

P* avion::getPoints()
{
	return this->points;
}

avion::avion(int x,int y)
{
	this->points = (P*)malloc(8*sizeof(P));
	this->points[0].x=x;
	this->points[0].y=y;
	this->points[1].x=x+1;
	this->points[1].y=y+1;
	this->points[2].x=x;
	this->points[2].y=y+1;
	this->points[3].x=x-1;
	this->points[3].y=y+1;
	this->points[4].x=x;
	this->points[4].y=y+2;
	this->points[5].x=x;
	this->points[5].y=y+3;
	this->points[6].x=x-1;
	this->points[6].y=y+3;
	this->points[7].x=x+1;
	this->points[7].y=y+3;
} 

bool avion::rotateLeft(int height,int width)
{
	if(this->points[0].y==this->points[5].y) //vertical
	{
		if(this->points[0].x < this->points[5].x) //cu capul sus
		{
			if(points[0].y>1)  //verific daca pot face rotirea
			{
				points[0].x=points[0].x+2;
	            points[0].y=points[0].y-2;
	            points[1].x=points[1].x+2;
            	points[1].y=points[1].y;
            	points[2].x=points[2].x+1;
            	points[2].y=points[2].y-1;
             	points[3].x=points[3].x;
            	points[3].y=points[3].y-2;
              	points[5].x=points[5].x-1;
 	            points[5].y=points[5].y+1;
               	points[6].x=points[6].x-2;
               	points[6].y=points[6].y;
              	points[7].x=points[7].x;
              	points[7].y=points[7].y+2;
              	return true;
			}
			    
		}
		else if(this->points[0].x > this->points[5].x) //cu capul jos
		{
			if(points[0].y<width-2)  //verific daca pot face rotirea
			{
				points[0].x=points[0].x-2;
	            points[0].y=points[0].y+2;
	            points[1].x=points[1].x-2;
            	points[1].y=points[1].y;
            	points[2].x=points[2].x-1;
            	points[2].y=points[2].y+1;
             	points[3].x=points[3].x;
            	points[3].y=points[3].y+2;
              	points[5].x=points[5].x+1;
 	            points[5].y=points[5].y-1;
               	points[6].x=points[6].x+2;
               	points[6].y=points[6].y;
              	points[7].x=points[7].x;
              	points[7].y=points[7].y-2;
              	return true;
			}
			    
		}
	}
    else if(this->points[0].x==this->points[5].x) //orizontal
	{
		if(this->points[0].y < this->points[5].y) //cu capul la stanga
		{
			if(points[0].x<height-2)  //verific daca pot face rotirea
			{
				points[0].x=points[0].x+2;
	            points[0].y=points[0].y+2;
	            points[1].x=points[1].x;
            	points[1].y=points[1].y+2;
            	points[2].x=points[2].x+1;
            	points[2].y=points[2].y+1;
             	points[3].x=points[3].x+2;
            	points[3].y=points[3].y;
              	points[5].x=points[5].x-1;
 	            points[5].y=points[5].y-1;
               	points[6].x=points[6].x;
               	points[6].y=points[6].y-2;
              	points[7].x=points[7].x-2;
              	points[7].y=points[7].y;
              	return true;
			}
			    
		}
		else if(this->points[0].y > this->points[5].y) //cu capul la dreapta
		{
			if(points[0].x>1)  //verific daca pot face rotirea
			{
				points[0].x=points[0].x-2;
	            points[0].y=points[0].y-2;
	            points[1].x=points[1].x;
            	points[1].y=points[1].y-2;
            	points[2].x=points[2].x-1;
            	points[2].y=points[2].y-1;
             	points[3].x=points[3].x-2;
            	points[3].y=points[3].y;
              	points[5].x=points[5].x+1;
 	            points[5].y=points[5].y+1;
               	points[6].x=points[6].x;
               	points[6].y=points[6].y+2;
              	points[7].x=points[7].x+2;
              	points[7].y=points[7].y;
              	return true;
			}
			    
		}
	}
	return false;
	
}


