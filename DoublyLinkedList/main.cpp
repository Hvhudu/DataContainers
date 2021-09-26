#include<iostream>
using namespace std;

class List {

	class Element
	{
		int Data;//Значение элемента
		Element* pNext;//Адрес следующео элемента
		Element* pPrev;

	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor\t" << this << endl;
		}
		friend class List;
	}*Head, * Tail;
	rsize_t size;
public:
	size_t get_size()
	{
		return this->size;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor\t" << this << endl;
	}

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}else
		{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		}
		size++;
	}
};

