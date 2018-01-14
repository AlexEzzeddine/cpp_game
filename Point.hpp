class Point
{
	private:
		int x;
		int y;
	public:
		Point();
		Point(Point &point);
		Point(int x, int y);
		int getX();
		int getY();
		void setX(int x);
		void setY(int y);

		bool operator==(Point const& point) const;
}