

//线性表的部分实现及习题
//高概率错误1：返回值一定要！除非使用void

#include<iostream>
using namespace std;
#define InitSize 100
#define OK 0
#define ERROR 1
typedef struct student {
	int id;
} ElemType;

typedef struct {
	ElemType* data;
	int length;
} SeqList;

int InitList(SeqList& L) {
	L.data = new ElemType[InitSize];
	if (L.data == NULL) exit(ERROR);
	L.length = 0;
	return OK;
}

int Length(SeqList L) {
	return L.length;
}

int LocateElem(SeqList L, ElemType e) {
	int i;
	for (i = 0; i < L.length; i++) {
		if (L.data[i].id == e.id) return i + 1;
	}
	if (i == L.length) cout << "error!" << endl;
	return ERROR;
}

int ListInsert(SeqList& L, ElemType e, int i) {
	int n = L.length;
	for (int j = n; j >= i; j--) L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length += 1;
	return 0;
}

int ListPrint(SeqList L) {
	int n = L.length;
	for (int i = 0; i < n-1; i++)
		cout << L.data[i].id << ",";
	cout <<L.data[n-1].id<<endl;
	return 0;
}

int NO1(SeqList& L) {
	if (L.length == 0) return false;
	int b = 0;
	ElemType a = L.data[0];
	for (int i = 0; i < L.length; i++) {
		if (L.data[i].id <= a.id) {
			a = L.data[i];
			b = i;
		}
	}
	L.data[b] = L.data[L.length - 1];
	return a.id;
}

int NO2(SeqList& L) {
	ElemType e;
	int n = L.length;
	for (int i = 0; i < L.length / 2; i++) {
		e = L.data[i];
		L.data[i] = L.data[n - i - 1];
		L.data[n - i - 1] = e;
	}
	return 0;
}

int NO3(SeqList& L, ElemType x) {
	if (!L.length) exit(ERROR);
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (x.id != L.data[i].id) {
			L.data[k] = L.data[i];
			k = k + 1;
		}
	}
	L.length = k;
	return 0;
}

int NO4(SeqList& L, double s, double t) {
	if (!L.length||s>=t) exit(ERROR);
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i].id<=s || L.data[i].id>=t) {
			L.data[k] = L.data[i];
			k = k + 1;
		}
	}
	L.length = k;
	return 0;
}

int NO5(SeqList& L, double s, double t) {
	if (!L.length || s >= t) exit(ERROR);
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.data[i].id < s || L.data[i].id > t) {
			L.data[k] = L.data[i];
			k = k + 1;
		}
	}
	L.length = k;
	return 0;
}

int NO6(SeqList& SL) {
	int k = 1;
	for (int i = 1; i < SL.length; i++) {
		if (SL.data[i].id != SL.data[i - 1].id) {
			SL.data[k] = SL.data[i];
			k = k + 1;
		}
	}
	SL.length = k;
	return 0;
}

SeqList NO7(SeqList SL1, SeqList SL2) {
	SeqList SL3;
	InitList(SL3);
	int i = 0; int j = 0; int k = 0;
	while (i < SL1.length && j < SL2.length) {
		if (SL1.data[i].id > SL2.data[j].id)
			SL3.data[k++] = SL1.data[i++];
		else
			SL3.data[k++] = SL2.data[i++];
	}
	while (i < SL1.length)
		SL3.data[k++] = SL1.data[i++];
	while (j < SL2.length)
		SL3.data[k++] = SL2.data[j++];
	return SL3;
}

int NO8(SeqList& L, int m, int n) {
	int l = L.length;
	ElemType e;
	for (int i = 0; i < L.length / 2; i++) {
		e = L.data[i];
		L.data[i] = L.data[l - i - 1];
		L.data[l - i - 1] = e;
	}
	for (int i = 0; i < n / 2; i++) {
		e = L.data[i];
		L.data[i] = L.data[n - i - 1];
		L.data[n - i - 1] = e;
	}
	for (int i = n; i < n + m / 2; i++) {
		e = L.data[i];
		L.data[i] = L.data[l - (i - n) - 1];
		L.data[l - (i - n) - 1] = e;
	}
	return 0;
}

int NO9(SeqList& L, ElemType x) {
	int i = 0; int flag = 0;
	ElemType e;
	while (i < L.length && flag == 0) {
		if (L.data[i++].id >= x.id) {		//错误1：在运行玩这一句后，无论if成不成立，i都会增加1，因此在后面要将i减一以确定i值正确
			i = i - 1;
			if (L.data[i].id == x.id) {
				e = L.data[i];
				L.data[i] = L.data[i + 1];
				L.data[i + 1] = e;
				flag = 1;
			}
			else {
				for (int j = L.length - 1; j >= i; j--) {	//错误2：时刻注意for循环结束的时刻点！
					L.data[j + 1] = L.data[j];
				}
				L.data[i] = x;
				L.length += 1;
				flag = 1;
			}
		}
	}
	return 0;
}

int NO11(SeqList A, SeqList B) {		//错误：判定i+j刚好抵达中位点时，预判下一步的i与j的值！
	if (A.length == 0 && B.length == 0) exit(ERROR);
	int i = 0; int j = 0; int k; int l;
	l = A.length + B.length;
	while ( (i + j) < l / 2.0 && i < A.length && j < B.length) {
		if (A.data[i].id < B.data[j].id) k = A.data[i++].id;
		else k = B.data[j++].id;
	}
	if (i == A.length) {
		while (i + j < l/2.0) k = B.data[j++].id;
	}
	else {
		while (i + j < l/2.0) k = A.data[i++].id;
	}
	return k;
}

int main() {
	student a;
	ElemType b, c, d, e,f;
	a.id = 1;
	b.id = 2;
	c.id = 3;
	d.id = 4;
	e.id = 5;
	f.id = 10;
	SeqList L,SL,B;
	InitList(L);
	InitList(SL);
	InitList(B);
	ListInsert(L, a, 1);ListInsert(L, b, 2);ListInsert(L, c, 2);ListInsert(L, d, 2);ListInsert(L, d, 1); ListInsert(L, c, 1);
	ListInsert(SL, a, 1); ListInsert(SL, a, 2); ListInsert(SL, b, 3); ListInsert(SL, b, 4); ListInsert(SL, c, 5); ListInsert(SL, e, 6);
	ListInsert(B, a, 1); ListInsert(B, f, 2); ListInsert(B, f, 2); ListInsert(B, f, 2); ListInsert(B, f, 2);
	SeqList Q = L;
	ListPrint(L);
	ListPrint(SL);

	//NO1(L);
	//ListPrint(L);

	//NO2(L);
	//ListPrint(L);

	//NO3(L, b);
	//ListPrint(L);

	//L = Q;
	//ListInsert(L, a, 1);
	//ListPrint(L);

	//NO4(L, 2, 3);
	//ListPrint(L);
	//ListPrint(SL);

	//NO6(SL);
	//ListPrint(SL);

	//L = Q;
	//NO8(L, 2, 4);
	//ListPrint(L);

	//NO9(SL, d);
	//ListPrint(SL);
	//return 0;

	int k = NO11(SL, B);
	cout << k << endl;
}
