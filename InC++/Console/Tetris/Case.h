#ifndef CASE_H
#define CASE_H

class Square
{
protected:
	int m_axisX, m_axisY;//Les mettres en constantes !
	char m_value;

public:
	Square(void);
	Square(int x, int y, char value);
	~Square(void);

	Square& operator=(Square const& caseToCopy);
	int getAxisX(void);
	int getAxisY(void);
	void setCoordinates(int x, int y);
	void setValue(char value);
	char getValue(void);
	bool isEqual(Square const& case2) const;
};

bool operator==(Square const& case1, Square const& case2);

#endif;
