#ifndef CPOINT2D_H
#define CPOINT2D_H

class CPoint2D
{
public:
	CPoint2D();
	CPoint2D(float a, float b);
	~CPoint2D();
	const CPoint2D& operator=(const CPoint2D& p);
	const CPoint2D& operator+= (const CPoint2D& p);
	const CPoint2D& operator*=(const float length);
	CPoint2D operator+(const CPoint2D& p);
	CPoint2D operator*(float f);
	union
	{
		struct 
		{
			float x;
			float y;
		};
		float m[2];
	};
	
};

class CLPoint2D
{
public:
    CLPoint2D(){x = 0; y = 0;}
	CLPoint2D(int a, int b){x = a; y = b;}
	
	int x;
	int y;
};
#endif
