// TODO: try to not include by relative path (-I directory)

// TODO: it's usually done this way:
//
// executable(test_abc)
// include(test_abc $TESTED_LIBRARY) // ~ -I include
// include(test_abc $TEST_LIBRARY)   // ~ -I vendor/test/include
// link(test_abc TESTED_LIBRARY)     // ~ -ltested
// link(test_abc TEST_LIBRARARY)     // ~ -ltestlib

#include "../user_interface.h"
// работа с аргументами переменной длины (когда их количество меняется)
#include <stdarg.h>
// for working with NULL Objects
#include <stddef.h>
// exception handling
#include <setjmp.h>


#include <cmocka.h>
