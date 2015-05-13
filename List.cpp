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
int remove (int n,  list *&pF) //удаление элемента из списка по номеру
	{
		list *p = pF;
		int i;
		if(n>1){
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				p->next = p->next->next;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (pF!=0)
			{
				pF=pF->next;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}

/**
	Функция добавление элемента в список по номеру
	*/
int add (int n, int x,  list *&pF) //удаление элемента из списка по номеру
	{
		list *p = pF;
		int i;
		if(n>1)
		{
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				list *newP = new list; //создаем новый элемент
				newP->value = x; //заполняем его.
				newP->next=p->next; //Заполняем его 
				p->next = newP;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			InsertHead(x, pF);
			return 0;
			
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
		cout << p->value<< " ";
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
	int n = 0; //кол-во операций
	cin >> n;

	int data;
	int num;
	char op;
	for (int i = 0; i < n; i++) //изначально, заполним список
	{	
		cin >> op;
		if(op=='a')
		{
			cin >> num;
			cin >> data;
			if(	add(num, data, pFirst)<0)
			{
				cout << "Oshibka dobavlenia! Neverniy nomer!";
			}
		}
		else
		if(op=='d')
		{
			cin >> num;
			if(	remove(num,  pFirst)<0)
			{
				cout << "Neverniy nomer!";
			}
		}
		
		
	}

	printList(pFirst);
	getchar();
	getchar();
	return 0;
}
