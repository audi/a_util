#ifndef RESULT_TESTER_LIB_HEADER_INCLUDED
#define RESULT_TESTER_LIB_HEADER_INCLUDED

#include "a_util/result/result_type.h"

_MAKE_RESULT(-1000, ERR_OUT_OF_MEMORY);

#if defined(_WIN32)
#define RESULT_TEST_DDL_EXPORT __declspec(dllexport)
#else
#define RESULT_TEST_DDL_EXPORT
#endif

namespace test
{

RESULT_TEST_DDL_EXPORT a_util::result::Result GetResult();
RESULT_TEST_DDL_EXPORT a_util::result::Result GetResultOutOfMemory();
RESULT_TEST_DDL_EXPORT a_util::result::Result GetDetailedResultOutOfMemory();
RESULT_TEST_DDL_EXPORT a_util::result::Result GetResultOutOfInternalMemory();
RESULT_TEST_DDL_EXPORT a_util::result::Result GetDetailedResultOutOfInternalMemory();

} // namespace test

#undef RESULT_TEST_DDL_EXPORT

#endif // RESULT_TESTER_LIB_HEADER_INCLUDED