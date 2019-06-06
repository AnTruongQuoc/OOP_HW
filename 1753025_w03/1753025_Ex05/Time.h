class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	Time(const Time& src);
	void input();
	void output();
	Time future();
};