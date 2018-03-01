#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

string level[12] = {"A+","A=","A-","B+","B=","B-",
					"C+","C=","C-","D+","D=","F"};
float GP[12] = {4.0, 4.0, 3.7, 3.3, 3.0, 2.7,
				2.3, 2.0, 1.7, 1.3, 1.0, 0.0};

class GPAmanager
{
public:
	GPAmanager(int n, int m);
	void Operation();
	~GPAmanager();

private:
	int *point;
	float *gpa;
	int op_num;
	int stu_num;

	void addCourse();
	void getGPA();
	void getNum();
};

GPAmanager::GPAmanager(int n, int m)
{
	//≥ı ºªØ
	point = new int[n]();
	gpa = new float[n]();
	stu_num = n;
	op_num = m;
}

void GPAmanager::Operation()
{
	int op_kind = 0;
	for (int i = 0; i < op_num; i++)
	{
		cin >> op_kind;
		switch (op_kind)
		{
		case 1:
			addCourse();
			break;
		case 2:
			getGPA();
			break;
		case 3:
			getNum();
			break;
		default:
			break;
		}
	}
}

GPAmanager::~GPAmanager()
{
	delete []point;
	delete []gpa;
}

void GPAmanager::addCourse()
{
	int stu_id = 0;
	int stu_point = 0;
	int stu_po = 0;
	string stu_level;

	cin >> stu_id >> stu_point >> stu_level;
	stu_po = stu_id - 1;
	float stu_GP = 0;
	for (int i = 0; i < 12; i++)
	{
		if (stu_level == level[i])
		{
			stu_GP = GP[i];
			break;
		}
	}
	//gpa[stu_po] = ceil(10 * (gpa[stu_po] * point[stu_po] + stu_GP * stu_point)
	//						/ (point[stu_po] + stu_point)) / 10;
	gpa[stu_po] = (gpa[stu_po] * point[stu_po] + stu_GP * stu_point)
							/ (point[stu_po] + stu_point);
	point[stu_po] += stu_point;
}

void GPAmanager::getGPA()
{
	int stu_id = 0;
	cin >> stu_id;
	cout << setiosflags(ios::fixed) << setprecision(1) 
		 << ceil(10 * gpa[stu_id-1]) / 10 << endl;
}

void GPAmanager::getNum()
{
	int number = 0;
	float aim_GPA = 0;
	cin >> aim_GPA;
	for (int i = 0; i < stu_num; i++)
	{
		float temp_GPA = ceil(10 * gpa[i]) / 10;
		if (abs(temp_GPA - aim_GPA) < 0.1)
		{
			number++;
		}
	}
	cout << number << endl;
}

int main()
{
	int m = 0, n = 0;
	cin >> n >> m;
	GPAmanager m_GPA(n, m);
	m_GPA.Operation();
	return 0;
}
