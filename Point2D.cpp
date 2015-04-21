#include "Point2D.h"
#include <math.h>

CPoint2D::CPoint2D()
{
}

CPoint2D::CPoint2D(float a, float b)
{
	x = a;
	y = b;
}


CPoint2D::~CPoint2D()
{
}

const CPoint2D& CPoint2D::operator=(const CPoint2D& p)
{
	x = p.x;
	y = p.y;
	return *this;
}

const CPoint2D& CPoint2D::operator+=(const CPoint2D& p)
{
	x += p.x;
	y += p.y;
	return *this;
}

const CPoint2D& CPoint2D::operator*=(const float length)
{
	x *= length;
	y *= length;
	return *this;
}

CPoint2D CPoint2D::operator+(const CPoint2D& p)
{
	CPoint2D res;
	res.x = x + p.x;
	res.y = y + p.y;
	return res;
}

CPoint2D CPoint2D::operator*(float f)
{
	CPoint2D res;
	res.x = x*f;
	res.y = y*f;
	return res;
}

float CPoint2D::Distance(const CPoint2D& p)
{
	float offset_x = x - p.x;
	float offset_y = y - p.y;

	return sqrt(offset_x*offset_x + offset_y*offset_y);
}



const CLPoint2D& CLPoint2D::operator=(const CLPoint2D& p)
{
	x = p.x;
	y = p.y;
	e = p.e;
	return *this;
}

CLPoint2D CLPoint2D::operator+(const CLPoint2D& p)
{
	CLPoint2D rp;
	rp.x = x + p.x;
	rp.y = y + p.y;
	rp.e = (e == p.e);
	return rp;
}

