#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

#define ARRAY_HEAD 0

//data1とdata2を交換する関数。
static void swap(item* data1, item* data2) 
{
	item temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

static int partition(item* data1,int L,int R) 
{

	int pivot = L;
	int m = L;
	int n = R + 1;

	do {
		do {
			m++;
		} while (data1[m].key < data1[pivot].key);
		do {
			n--;
		} while (data1[pivot].key < data1[n].key);
		if (m < n) {
			swap(&data1[m], &data1[n]);
		}
	} while (m < n);

	swap(&data1[pivot], &data1[n]);

	return n;
}

void My_quick_sort(item* begin, int L, int R) 
{
	int pivot;

	if (L < R) {
		pivot = partition(begin, L, R);
		My_quick_sort(begin, L, pivot - 1);
		My_quick_sort(begin, pivot + 1, R);
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	int L, R;

	L = ARRAY_HEAD;//配列の先頭
	R = (int)(end - begin) - 1;//配列の要素数

	if (begin == NULL || end == NULL)return false;
	if (begin > end)return false;

	My_quick_sort(begin, L, R);

	return true;
}
