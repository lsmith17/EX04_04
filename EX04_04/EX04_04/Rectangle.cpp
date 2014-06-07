#include<iostream>
using namespace std;

class Rectangle2D
{
private:
	double x, y;
	double width, height;

public:
	Rectangle2D()
	{
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}

	Rectangle2D(double x, double y, double width, double height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	double getX() const
	{
		return x;
	}

	void setX(double x)
	{
		this->x = x;
	}

	double getY() const
	{
		return y;
	}

	void setY(double y)
	{
		this->y = y;
	}

	double getWidth() const
	{
		return width;
	}

	void setWidth(double width)
	{
		this->width = width;
	}

	double getHeight() const
	{
		return height;
	}

	double setHeight(double height)
	{
		this->height = height;
	}

	double getPerimeter() const
	{
		return 2 * height + 2 * width;
	}

	double getArea() const
	{
		return height * width;
	}

	bool contains(double x, double y) const
	{

		return (abs(x - this->x) <= width) && (abs(y - this->y) <= height);
	}

	bool contains(const Rectangle2D &r) const
	{
		return contains(r.x - r.width, r.y) && contains(r.x + r.width, r.y)
			&& contains(r.x, r.y - r.height) && contains(r.x, r.y + r.height);
	}

	bool overlaps(const Rectangle2D &r) const
	{
		return ((x + .5 * width > r.x + .5 * r.width)
			&& (y + .5 * height > r.y + .5 * r.height)
			|| (x + .5 * width > r.x + .5 * r.width)
			&& (y + .5 * height > r.y + .5 * r.height));


	}

};

int main(){
	Rectangle2D r1(2, 2, 5.5, 10);
	cout << "Area: " << r1.getArea() << endl;
	cout << "Perimeter: " << r1.getPerimeter() << endl;

	cout << r1.contains(3, 3) << endl;

	Rectangle2D r2(2, 2, 5, 5);
	cout << r1.contains(r2) << endl;
	cout << r1.overlaps(r2) << endl;
}