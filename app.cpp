#include <iostream>
#include "appsession.h"

int main()
{

    std::cout << "Initializing GL Render application!" << std::endl;

    GLVR::Core::AppSession main_session;
    main_session.init();
    main_session.run();
    main_session.destroy();
    return 0;
}