//最小覆蓋圓增量算法：O(n)
//https://blog.csdn.net/ACdreamers/article/details/9406735
//https://blog.csdn.net/commonc/article/details/52291822
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	double x, y;
};

//according to 兩中垂線(1與2點、1與3點) A12x+B12y=C12 、A13x+B13y=C13
struct Point solve (double A12, double B12, double C12, double A13, double B13, double C13, struct Point p1, struct Point p2, struct Point p3)
{
	struct Point Intersection;
	double det = A12*B13-A13*B12;
	if (det != 0) {
		//克拉瑪
		Intersection.x = (B13*C12-B12*C13)/det;
		Intersection.y = (A12*C13-A13*C12)/det;
	} else {
		if ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) > (p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y)) {
			if ((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) > (p2.x-p3.x)*(p2.x-p3.x)+(p2.y-p3.y)*(p2.y-p3.y)) {
				Intersection.x = (p1.x + p2.x)/2;
				Intersection.y = (p1.y + p2.y)/2;
			} else {
				Intersection.x = (p2.x + p3.x)/2;
				Intersection.y = (p2.y + p3.y)/2;
			}
		} else {
			if ((p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y) > (p2.x-p3.x)*(p2.x-p3.x)+(p2.y-p3.y)*(p2.y-p3.y)) {
				Intersection.x = (p1.x + p3.x)/2;
				Intersection.y = (p1.y + p3.y)/2;
			} else {
				Intersection.x = (p2.x + p3.x)/2;
				Intersection.y = (p2.y + p3.y)/2;
			}
		}
	}
	return Intersection;
}

int main(int argc, char const *argv[])
{
	int N;
	while ( cin >> N && N ) {

		struct Point *p = new struct Point[N];
		for (int i = 0; i < N; ++i)
			cin >> p[i].x >> p[i].y;

		double R; cin >> R;

		struct Point O;	O = p[0];
		double cur_R_sqr = 0; // cur_R^2
		bool able = true;
		for (int i = 1; i < N && able; ++i)
		{
			if ( (p[i].x-O.x)*(p[i].x-O.x)+(p[i].y-O.y)*(p[i].y-O.y) > cur_R_sqr ) //!incircle
			{
				O = p[i];	cur_R_sqr = 0;
				for (int j = 0; j < i && able; ++j)
				{
					if ( (p[j].x-O.x)*(p[j].x-O.x)+(p[j].y-O.y)*(p[j].y-O.y) > cur_R_sqr )
					{
						O.x = (p[i].x + p[j].x)/2; O.y = (p[i].y + p[j].y)/2;
						cur_R_sqr =  (p[i].x - O.x)*(p[i].x - O.x) + (p[i].y - O.y)*(p[i].y - O.y);
						if ( cur_R_sqr > R*R ) able = false;
						for (int k = 0; k < j && able; ++k)
						{
						 	if ( (p[k].x-O.x)*(p[k].x-O.x)+(p[k].y-O.y)*(p[k].y-O.y) > cur_R_sqr )
						 	{
						 		O = solve (p[j].x-p[i].x, p[j].y-p[i].y, (p[j].x*p[j].x+p[j].y*p[j].y-p[i].x*p[i].x-p[i].y*p[i].y)/2
						 					,p[k].x-p[i].x, p[k].y-p[k].y, (p[k].x*p[k].x+p[k].y*p[k].y-p[i].x*p[i].x-p[i].y*p[i].y)/2
						 					, p[i], p[j], p[k]);
						 		cur_R_sqr = (p[i].x - O.x)*(p[i].x - O.x) + (p[i].y - O.y)*(p[i].y - O.y);
						 	}
						} 
					}
				}
			}
		}
		if (cur_R_sqr > R*R) able = false;
		if (able) cout << "The polygon can be packed in the circle." << endl;
		else cout << "There is no way of packing that polygon."  << endl;
	}
	return 0;
}
