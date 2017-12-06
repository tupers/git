
#include <iostream>
#include <vector>

#include <coreFramework.h>

int main()
{
	coreFramework* app = new coreFramework;
	
	try {
		app->init();
		//app.exec();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	delete app;

    return 0;
}
