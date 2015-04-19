#include "Point2D.h"


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

const CLPoint2D& CLPoint2D::operator=(const CLPoint2D& p)
{
	x = p.x;
	y = p.y;
	o = p.o;
	return *this;
}

CLPoint2D CLPoint2D::operator+(const CLPoint2D& p)
{
	CLPoint2D rp;
	rp.x = x + p.x;
	rp.y = y + p.y;
	rp.o = (o == p.o);
	return rp;
}

