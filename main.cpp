#include "DynamicTable.h"

int main() {

    srand(time(nullptr));

    auto* table = new DT::DynamicTable(6);

    table -> menu();

    delete table;

    return 0;
}

