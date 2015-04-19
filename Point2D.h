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
    CLPoint2D(){x = 0; y = 0; o = true;}
	CLPoint2D(int a, int b, bool odd){x = a; y = b;o = odd;}
	const CLPoint2D& operate=(const CLPoint2D& p);
	CLPoint2D operate+(const CLPoint2D& p);
	int x;
	int y;
	bool o;
};
#endif
