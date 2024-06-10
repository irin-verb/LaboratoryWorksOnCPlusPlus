#pragma once //включать заголовочный файл только один раз

//поэтому можно в С++ не писать:
//#ifndef module_h
//#define module_h
//...
//#endif


enum AnimalSize { UNKNOWN, SMALL, MEDIUM, BIG };

class Animal
{
private:
	
	char name[256];
	float maxSpeed;
	float curSpeed;
	AnimalSize size;
	bool isPredator;
	bool isHungry;
	
	void calcSize(float w, float h, float l);
		
public:

	Animal(const char* name, float maxSpeed, float w, float h, float l, 
	       bool isPredator = true); 

	void setHungry(bool isHungry)
	{
		curSpeed = isHungry? maxSpeed * 0.7f : maxSpeed;
		this->isHungry = isHungry; 
	}
	
	bool getHungry() { return isHungry; }
	
	float getCurSpeed() { return curSpeed; }
	
	Animal* roar();
	
	Animal* howl();
	
	Animal* printAbout();	
};


