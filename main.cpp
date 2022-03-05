#include "DynamicTable.h"

int main() {

    srand(time(nullptr));

    auto table = new DT::DynamicTable(5);

    DT::DynamicTable dynamicTable;

    table -> menu();

    delete table;

    return 0;
}

