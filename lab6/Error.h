//Класс исключений с необходимым текстом
class Error
{
	const char* info;
public:
	Error(const char* info) : info(info) {}
	const char* getInfo() { return info; }	
};


