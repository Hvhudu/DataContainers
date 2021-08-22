#include<iostream>
using namespace std;

class Element
{
	int Data;//Значение элемента
	Element* pNext;//Адрес следующео элемента
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

class ForwardList
{
	Element* Head;  //Голова списка - указывает на нулевой элемент списка
public:
	ForwardList()
	{
		//Конструктор по умолчанию, создаёт пустой список
		Head = nullptr;
		//Если Голова указывает на ноль, то список пуст, т.е, не содержит элементов,
		//И Голове больше на на что указывать.
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}
	//					Addin element:
	void push_front(int Data)
	{
		//1) Создаём новый элемент:
		Element* New = new Element(Data);
		//2)Прикрепляем элемент к списку:
		New->pNext = Head;
		//3) Говорим, что новый элемент - начальный элемент списка
		Head = New;
	}

	//					Methods:
	void print()const
	{
		Element* Temp = Head;//Temp - итератор
		// Итератор - это казатель при помощи которого можно получить 
		//доступ к элементам структуры данных
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "ru");
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
}