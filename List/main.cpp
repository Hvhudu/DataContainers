#include<iostream>
using namespace std;
//#define ITERATORS_CHECK

class List {

	class Element
	{
		int Data;//Значение элемента
		Element* pNext;//Адрес следующео элемента
		Element* pPrev;

	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
#ifdef DEBUG
cout << "EConstructor\t" << this << endl;
#endif // DEBUG

			
		}
		~Element()
		{
#ifdef DEBUG
cout << "EDestructor\t" << this << endl;
#endif // DEBUG
			
		}
		friend class List;
	}*Head, * Tail;
	rsize_t size;
public:
	class Reverse_Iterator
	{
		Element* Retemp;
		Reverse_Iterator(Element* Retemp = nullptr) : Retemp(Retemp)
		{
			cout << "ReItConstructor;\t" << this << endl;
		}
		~Reverse_Iterator()
		{
			cout << "ReItDestructor:\t" << this << endl;
		}
		Reverse_Iterator& operator++()
		{
			Retemp = Retemp->pPrev;
			return *this;
		}
		Reverse_Iterator& operator++(int)
		{
			Reverse_Iterator old = *this;
			Retemp = Retemp->pPrev;
			return old;
		}
		bool operator==(const Reverse_Iterator& other)const
		{
			return this->Retemp == other.Retemp;
		}
		bool operator!=(const Reverse_Iterator& other)const
		{
			return this->Retemp != other.Retemp;
		}
		const int& operator*()const
		{
			return this->Retemp->Data;
		}
		int& operator*()
		{
			return this->Retemp->Data;
		}
	};
	Reverse_Iterator rbegin()
		{
			this->Tail;
		}
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
cout << "ItConstructor;\t" << this << endl;
#endif // DEBUG
			
		}
		~Iterator()
		{
#ifdef DEBUG
cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG
			
		}

		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const int& operator*()const
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
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
#ifdef DEBUG
cout << "LConstructor\t" << this << endl;
#endif // DEBUG

		
	}
	List(const initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	List(const List& other) :List()
	{
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
	}
	List& operator=(const List& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
#ifdef DEBUG
cout << "LCopyAssignment: " << this << endl;
#endif // DEBUG

		
		return *this;
	}
	~List()
	{
		while (Tail)pop_back();
		//while (Head)pop_front();
#ifdef DEBUG
cout << "LDestructor\t" << this << endl;
#endif // DEBUG

		
	}

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		else
		{
			/*Element* New = new Element(Data);
			New->pNext = Head;
			Head->pPrev = New;
			Head = New;*/
			Head = Head->pPrev = new Element(Data, Head);
		}
		size++;
	}
	void push_back(int Data)
	{
		if (!Head && !Tail)return push_front(Data);
		/*Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;*/
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}
	void pop_front()
	{
		if (Head = Tail)
		{
			delete Head;
			Head = Tail = nullptr;
			return;
		}
		Head = Head->pNext;
		delete Head->pPrev;
		Head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		if (Tail == Head)return pop_front();
		Tail = Tail->pPrev;
		delete Tail->pNext;
		Tail->pNext = nullptr;
		size--;
	}


	void print()const
	{
		cout << "Адресс списка: " << Head << endl;
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->size << endl;
	}
	void reverse_print()const
	{
		cout << "Адресс конца списка: " << Tail << endl;
		for (Element* Temp = Tail;Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
		cout << "Количество элементов списка: " << this->size << endl;
	}
};


void main()
{
	setlocale(LC_ALL, "ru");
#ifdef BASE CHECK
int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();
#endif // BASE CHECK
#ifdef ITERATORS_CHECK
	List list = { 3,5,8,13,21 };
	list.print();
	List list2;
	list2 = list;
	for (List::Iterator it = list2.begin(); it != list2.end(); ++it)
	{
		cout << *it << "\t";
	}
	list2.reverse_print();
#endif // ITERATORS_CHECK

	double arr[] = { 3.5,5.5,8.6,13.7,21.1 };
	cout << sizeof(arr) << endl << endl;
	for (int i = 0; i < sizeof(arr) /sizeof(*arr); i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
	cout << endl;
	for (double i : arr)	// Range-based for intended to work only conteiners.
	{
		cout << i << "\t";
	}
	cout << endl;
	cout << endl;
	
	/*
	-----------------------------------------
	for(type i : conteiner)
	{
		cout<<i<<"\t";
	}
	-----------------------------------------
	*/

	List list = { 0,1,1,2,3,5,8,13,21 };
	for (int i : list)
	{
		cout << i << "\t";
	}
	cout << endl;
}
