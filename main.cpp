#include <string>
#include "include/trashguy.h"
int main() {
    std::string s = std::string("---------------------+");
    TrashGuy t(s);
    FILE * f = fopen("file.txt", "w");
    for(std::string &ch: t.generate(f)){
        fprintf(f, "%s\n", ch.c_str());
    }
    return 0;
}
