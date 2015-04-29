/*!
\file Sortir.cpp
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/
#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <time.h>

using namespace std;

struct list
{
	int value;
	list* next;

};

/**
	Функция добавления элемента в начало списка
	*/
void InsertHead (int a, list *&pF) //добавление элемента в начало списка
	{
		list *p = new list; //создаем новый элемент
		p->value = a; //заполняем его.
		p->next=pF; //Заполняем его 
		pF=p;

	}
/**
	Функция получения элемента из списка по его номеру
	*/
void GetValue (int n,  list *pF) //получение элемента из списка по его номеру
	{
		list*p= pF;
		for (int i = 1; i < n; i++)
		{
			p = p->next;
		}
		cout <<p->value <<endl; //"Значение: "
	}

/**
	Функция удаления элемента из списка по номеру
	*/
void remove (int n,  list *&pF) //удаление элемента из списка по номеру
	{
		list *p = pF;
		int i;
		if(n>1){
			for (i = 1; i < (n-1); i++)
			{
				p = p->next;
			}
			p->next = p->next->next;
		}else{
			pF=pF->next;
		}
	}

/**
	Функция вывода списка
	*/
void printList(list *pF) //"Список: ";
{
	list *p=pF;
	while (p)
	{
		cout << p->value << endl;
		p = p->next;
	}
	cout<<"\n";
}
//!Главная функция
int main()
{
	setlocale(LC_ALL, "rus");

	list *pFirst = NULL; //указатель на начало списка
	list *p; //указатель на список
	int n = 5; //кол-во элементов в списке
	int data;
	for (int i = 0; i < n; i++) //изначально, заполним список
	{
		cin >> data;
		InsertHead(data,  pFirst);
	}

	//Выводим список
	printList(pFirst);
	//Выводим значение элемента из списка
	int m;
//	cout <<"Введите номер элемента в списке:";
	cin >> m;
	GetValue(m, pFirst);

	//Удаляем значение из списка
	int k;
//	cout <<"Введите номер элемента, который вы хотите удалить: ";
	cin >> k;
	remove(k, pFirst);  
	printList(pFirst);
	getchar();
	getchar();
	return 0;
}
