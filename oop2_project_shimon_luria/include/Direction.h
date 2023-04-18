struct Direction {
	Direction() = default;
	Direction(bool u ,bool d,bool r,bool l)
	:UP(u),DOWN(d),RIGHT(r),LEFT(l)
	{}
	Direction& operator=(const Direction&) = default;
	bool UP = false;
	bool DOWN = false;
	bool RIGHT = false;
	bool LEFT = false;
};
inline bool operator==(const Direction& a, const Direction& b)
{
	return a.DOWN == b.DOWN && a.UP == b.UP && a.RIGHT == b.RIGHT && a.LEFT == b.LEFT;
}
inline bool operator!=(const Direction& a, const Direction& b)
{
	return !(a == b);
}
inline Direction operator-(Direction& other)
{
	if (other.DOWN)
		return Direction(1, 0, 0, 0);
	else if (other.UP)
		return Direction(0, 1, 0, 0);
	else if (other.RIGHT)
		return Direction(0, 0, 0, 1);
	else if (other.LEFT)
		return Direction(0, 0, 1, 0);

}