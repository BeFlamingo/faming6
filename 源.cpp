#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int tmp(int a, int b) {  //排序函数sort的第三个参数，在该题中用于将每一列的五个数从大到小排序
	return a > b;
}
class FindK {  //定义类，表示每一列的五个数
public:
	FindK(){}
	FindK(int a) {  //因为存在小于5的列，所以有适应各种情况的构造函数
		x[0] = a;
	}
	FindK(int a, int b) {
		x[0] = a;
		x[1] = b;
	}
	FindK(int a, int b, int c) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
	}
	FindK(int a, int b, int c, int d) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		x[3] = d;
	}
	FindK(int a, int b, int c, int d, int e) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		x[3] = d;
		x[4] = e;
	}
	void setX(int a) {
		x[0] = a;
		size = 1;
	}
	void setX(int a, int b) {
		x[0] = a;
		x[1] = b;
		size = 2;
	}
	void setX(int a, int b, int c) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		size = 3;
	}
	void setX(int a, int b, int c, int d) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		x[3] = d;
		size = 4;
	}
	void setX(int a, int b, int c, int d, int e) {
		x[0] = a;
		x[1] = b;
		x[2] = c;
		x[3] = d;
		x[4] = e;
		size = 5;
	}
	void sortItself(int n) {  //排序函数，将每列5个数从大到小排
		sort(x, x + n, tmp);
		mid = x[n / 2];  //选出中位数
	}
	int mid;             //中位数
	int x[5];            //代表每列的5个数
	int size;            //数的个数
};
int tmpMid(FindK a, FindK b) {  //根据中位数从小到大排序
	return a.mid < b.mid;
}
class Set {  //集合类
public:
	Set() {
		number = 0;
	}
	Set(int n) {
		number = 0;
		size = n;
	}
	void add(int x) {  //往集合中添加元素
		items[number++] = x;
	}
	int getN(int i) {
		return items[i];
	}
	int getNumber() {  //返回集合中元素个数
		return number;
	}
	int size;
	int number;      //当前下标和个数
	int items[100];  //用于存放数据
};
int find_k(int k, Set s, int size) {  //核心递归算法
	FindK x[20];
	int z = floor(size / 5.0);  //算出组数
	int i;
	for (i = 0; i < z; i++) {  //构造每一组
		x[i].setX(s.items[5 * i], s.items[5 * i + 1], s.items[5 * i + 2], s.items[5 * i + 3], s.items[5 * i + 4]);
		x[i].sortItself(5);
	}
	if (size - size / 5 * 5 == 1) {  //不足5个数的构造方法，下同
		x[i].setX(s.items[5 * i]);
		x[i].sortItself(1);
	}
	else if (size - size / 5 * 5 == 2) {
		x[i].setX(s.items[5 * i], s.items[5 * i + 1]);
		x[i].sortItself(2);
	}
	else if (size - size / 5 * 5 == 3) {
		x[i].setX(s.items[5 * i], s.items[5 * i + 1], s.items[5 * i + 2]);
		x[i].sortItself(3);
	}
	else if (size - size / 5 * 5 == 4) {
		x[i].setX(s.items[5 * i], s.items[5 * i + 1], s.items[5 * i + 2], s.items[5 * i + 3]);
		x[i].sortItself(4);
	}
	sort(x, x + z + 1, tmpMid);    //按横方向中位数从小到大排序
	int mid = x[(z + 1) / 2].mid;  //算出横方向的中位数
	Set s1, s2;                    //构造两个集合S1，S2
	for (i = 0; i < z + 1; i++) {
		if (x[i].size == 1 && i == (z + 1) / 2) {  //处理不足5个数的列，size表示该列的个数
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
		}
		else if (x[i].size == 2 && i != (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
			if (x[i].x[1] < mid)
				s1.add(x[i].x[1]);
			else
				s2.add(x[i].x[1]);
		}
		else if (x[i].size == 2 && i == (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
		}
		else if (x[i].size == 3 && i != (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
			if (x[i].x[1] < mid)
				s1.add(x[i].x[1]);
			else
				s2.add(x[i].x[1]);
			if (x[i].x[2] < mid)
				s1.add(x[i].x[2]);
			else
				s2.add(x[i].x[2]);
		}
		else if (x[i].size == 3 && i == (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
			if (x[i].x[2] < mid)
				s1.add(x[i].x[2]);
			else
				s2.add(x[i].x[2]);
		}
		else if (x[i].size == 4 && i != (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
			if (x[i].x[1] < mid)
				s1.add(x[i].x[1]);
			else
				s2.add(x[i].x[1]);
			if (x[i].x[2] < mid)
				s1.add(x[i].x[2]);
			else
				s2.add(x[i].x[2]);
			if (x[i].x[3] < mid)
				s1.add(x[i].x[3]);
			else
				s2.add(x[i].x[3]);
		}
		else if (x[i].size == 4 && i == (z + 1) / 2) {
			if (x[i].x[0] < mid)
				s1.add(x[i].x[0]);
			else
				s2.add(x[i].x[0]);
			if (x[i].x[1] < mid)
				s1.add(x[i].x[1]);
			else
				s2.add(x[i].x[1]);
			if (x[i].x[3] < mid)
				s1.add(x[i].x[3]);
			else
				s2.add(x[i].x[3]);
		}
		else {                      //对每列有5个数的处理
			if (i <= (z + 1) / 2) {
				if (i == (z + 1) / 2) {
					s1.add(x[i].x[3]);
					s1.add(x[i].x[4]);
				}
				else {
					s1.add(x[i].x[2]);
					s1.add(x[i].x[3]);
					s1.add(x[i].x[4]);
					if (x[i].x[0] < mid)
						s1.add(x[i].x[0]);
					else
						s2.add(x[i].x[0]);
					if (x[i].x[1] < mid)
						s1.add(x[i].x[1]);
					else
						s2.add(x[i].x[1]);
				}
			}
			if (i >= (z + 1) / 2) {
				if (i == (z + 1) / 2) {
					s2.add(x[i].x[0]);
					s2.add(x[i].x[1]);
				}
				else {
					s2.add(x[i].x[0]);
					s2.add(x[i].x[1]);
					s2.add(x[i].x[2]);
					if (x[i].x[3] < mid)
						s1.add(x[i].x[3]);
					else
						s2.add(x[i].x[3]);
					if (x[i].x[4] < mid)
						s1.add(x[i].x[4]);
					else
						s2.add(x[i].x[4]);
				}
			}
		}
	}
	if (s1.getNumber() == k - 1) {  //分为找到、小于、大于三种情况来处理，后两种要分治递归处理
		return mid;
	}
	else if (s1.getNumber() > k - 1) {
		return find_k(k, s1, s1.getNumber());
	}
	else {
		return find_k(k - 1 - s1.getNumber(), s2, s2.getNumber());
	}
}
int main() {
	int n;
	int i;
	int a, b, c, d, e;
	int x;
	int k;
	cout << "输入要输入的数据个数：";
	cin >> n;
	cout << "输入第几小的数：";
	cin >> k;
	cout << "输入这" << n << "个数：" << endl;
	Set set1(n);
	for (i = 0; i < n; i++) {
		cin >> x;
		set1.add(x);
	}
	cout << find_k(k, set1, n) << endl;
	return 0;
}