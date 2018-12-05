#pragma once
class Storage
{
public:
	enum TypeOfStorage
	{
		HDD = 0,
		SSD = 1,
	};

	TypeOfStorage type;
	static const int size = 100;
	static const int amount = 100;
	int generalSize;

public:
	Storage();
	Storage(TypeOfStorage type);
	~Storage();
};

