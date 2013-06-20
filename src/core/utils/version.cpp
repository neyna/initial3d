#include "../initial3d.hpp"

using boost::format;
using namespace std;

const char* VERION_TEXT = "%d.%d";

void print_version() {
  cout << "Software version : " << (format(VERION_TEXT) % INITIAL3D_VERSION_MAJOR % INITIAL3D_VERSION_MINOR).str().c_str() << endl;
}

void getVersion(shared_ptr<string> &computedVersion) {
	string version = (format(VERION_TEXT) % INITIAL3D_VERSION_MAJOR % INITIAL3D_VERSION_MINOR).str();
	computedVersion.reset(new string(version));
}
