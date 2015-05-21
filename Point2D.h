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
	float Distance(const CPoint2D& p);
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
    CLPoint2D(){x = 0; y = 0; e = true;}
	CLPoint2D(int a, int b, bool even){ x = a; y = b; e = even; }
	const CLPoint2D& operator=(const CLPoint2D& p);
	CLPoint2D operator+(const CLPoint2D& p);
	bool operator==(const CLPoint2D& p);
	int x;
	int y;
	bool e;
};
#endif
