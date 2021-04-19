#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int tmp(int a, int b) {  //������sort�ĵ������������ڸ��������ڽ�ÿһ�е�������Ӵ�С����
	return a > b;
}
class FindK {  //�����࣬��ʾÿһ�е������
public:
	FindK(){}
	FindK(int a) {  //��Ϊ����С��5���У���������Ӧ��������Ĺ��캯��
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
	void sortItself(int n) {  //����������ÿ��5�����Ӵ�С��
		sort(x, x + n, tmp);
		mid = x[n / 2];  //ѡ����λ��
	}
	int mid;             //��λ��
	int x[5];            //����ÿ�е�5����
	int size;            //���ĸ���
};
int tmpMid(FindK a, FindK b) {  //������λ����С��������
	return a.mid < b.mid;
}
class Set {  //������
public:
	Set() {
		number = 0;
	}
	Set(int n) {
		number = 0;
		size = n;
	}
	void add(int x) {  //�����������Ԫ��
		items[number++] = x;
	}
	int getN(int i) {
		return items[i];
	}
	int getNumber() {  //���ؼ�����Ԫ�ظ���
		return number;
	}
	int size;
	int number;      //��ǰ�±�͸���
	int items[100];  //���ڴ������
};
int find_k(int k, Set s, int size) {  //���ĵݹ��㷨
	FindK x[20];
	int z = floor(size / 5.0);  //�������
	int i;
	for (i = 0; i < z; i++) {  //����ÿһ��
		x[i].setX(s.items[5 * i], s.items[5 * i + 1], s.items[5 * i + 2], s.items[5 * i + 3], s.items[5 * i + 4]);
		x[i].sortItself(5);
	}
	if (size - size / 5 * 5 == 1) {  //����5�����Ĺ��췽������ͬ
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
	sort(x, x + z + 1, tmpMid);    //���᷽����λ����С��������
	int mid = x[(z + 1) / 2].mid;  //����᷽�����λ��
	Set s1, s2;                    //������������S1��S2
	for (i = 0; i < z + 1; i++) {
		if (x[i].size == 1 && i == (z + 1) / 2) {  //������5�������У�size��ʾ���еĸ���
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
		else {                      //��ÿ����5�����Ĵ���
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
	if (s1.getNumber() == k - 1) {  //��Ϊ�ҵ���С�ڡ������������������������Ҫ���εݹ鴦��
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
	cout << "����Ҫ��������ݸ�����";
	cin >> n;
	cout << "����ڼ�С������";
	cin >> k;
	cout << "������" << n << "������" << endl;
	Set set1(n);
	for (i = 0; i < n; i++) {
		cin >> x;
		set1.add(x);
	}
	cout << find_k(k, set1, n) << endl;
	return 0;
}