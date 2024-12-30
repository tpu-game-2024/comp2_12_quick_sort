#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item* a, item* b)
{
    item temp = *a;
    *a = *b;
    *b = temp;
}

// 中央のピボットを使用したパーティション関数
item* partition(item* low, item* high)
{
    item* pivot = low + (high - low) / 2;
    swap(pivot, high);
    pivot = high;
    item* i = low - 1;

    for (item* j = low; j <= high - 1; j++)
	{
        if (j->key <= pivot->key)
		{
            i++;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return (i + 1);
}

// クイックソートを実装するメイン関数
void quickSort(item* low, item* high)
{
    if (low < high)
	{
        item* pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}


// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
       if (begin == nullptr || end == nullptr || begin >= end)
	   {
         return false;
       }

    quickSort(begin, const_cast<item*>(end - 1));
    return true;
}
