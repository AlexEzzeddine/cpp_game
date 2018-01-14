class Character
{
	private:
		Bullets bullets[];
	public:
		Character();
		void shoot();
		void updateBulletsState();
}