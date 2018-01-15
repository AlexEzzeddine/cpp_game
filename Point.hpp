#ifndef POINT_HPP
#define POINT_HPP

class Point
{
	private:
		int x;
		int y;
	public:
		Point();
		Point(Point const& point);
		Point(int x, int y);
		~Point();
		
		int getX() const;
		int getY() const;
		void setX(int x);
		void setY(int y);
		void setCoords(int x, int y);

		Point& operator=(Point const& point);
		bool operator==(Point const& point) const;
};

#endif