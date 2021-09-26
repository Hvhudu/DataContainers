#include<iostream>
using namespace std;

class Element
{
	static int count;
	int Data;//Значение элемента
	Element* pNext;//Адрес следующео элемента

public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;  //Голова списка - указывает на нулевой элемент списка
	size_t size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
		}
		~Iterator()
		{
		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		Iterator& operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		int& operator*()
		{
			return this->Temp->Data;
		}
	};
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	size_t get_size()const
	{
		return this->size;
	};
	ForwardList()
	{
		//Конструктор по умолчанию, создаёт пустой список
		Head = nullptr;
		size = 0;
		//Если Голова указывает на ноль, то список пуст, т.е, не содержит элементов,
		//И Голове больше на на что указывать.
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const initializer_list<int>& il):ForwardList()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin();it != il.end(); it++)
		{
			this->push_back(*it);
		}

	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		//Конструктор копирования выполняет DeepCopy
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}
	//					Operators
	ForwardList& operator=(const ForwardList& other)
	{
		//1)Удаляем старое значение объекта
		while (Head)pop_front();
		//Конструктор копирования выполняет DeepCopy
		//2)Выполняет побитовое копирование
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		return *this;
	}
	//					Adding element:
	void push_front(int Data)
	{
		//1) Создаём новый элемент:
		Element* New = new Element(Data);
		//2)Прикрепляем элемент к списку:
		New->pNext = Head;
		//3) Говорим, что новый элемент - начальный элемент списка
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)Temp = Temp->pNext;
		//Element* New = new Element(Data);
		//Temp->pNext = New;
		Temp->pNext = new Element(Data);
		size++;

	}
	void Insetr(int Index, int Data)
	{
		if (Index >= size)return push_back(Data);
		if (Index == 0)return push_front(Data);
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)Temp = Temp->pNext;
		Element* New = new Element(Data);
		New ->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}
	//					Removing elements:
	void pop_front()
	{
		//1) Запоминаем адрес удаляемого элемента:
		Element* ereased = Head;
		//2) Исключаем элемент из списка:
		Head = Head->pNext;
		//3) Удаляем элемент из памяти:
		delete ereased;
		
	}
	void pop_back()
	{
		//1) Доходим до конца списка:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		//2) Удаляем элемент из памяти:
		delete Temp->pNext;
		//3)"Забываем" Об удалённом элементе:
		Temp->pNext = nullptr;
		
	}
	//					Methods:
	void print()const
	{
		Element* Temp = Head;//Temp - итератор
		// Итератор - это указатель при помощи которого можно получить 
		//доступ к элементам структуры данных
		/*while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
			
		}*/
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Общее кол-во элементов " << size << endl;
	}
};

//#define BASE_CHECK
#define delimiter "\n--------------------------------------------------\n"
void main()
{
	setlocale(LC_ALL, "ru");
#ifdef BASE_CHECK

	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	int index, value;
	/*cout << "Введите индекс добавляемого эл-та "; cin >> index;
	cout << "Введите значение добавляемого эл-та "; cin >> value;
	list.Insetr(index,value);
	list.print();*/

#endif // BASE_CHECK
	
	ForwardList list = { 3,5,8,13,21 };
	//list.print();
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << delimiter << endl;
	/*for (ForwardList::Iterator it = list.begin(); it != list.end(); it++)
	{
		cout << *it << endl;
	}*/
	cout << delimiter << endl;
	/*ForwardList list2;
	list2 = list;
	list2.print();*/
}