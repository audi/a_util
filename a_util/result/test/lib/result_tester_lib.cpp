#include "lib/result_tester_lib.h"
#include "a_util/result/error_def.h"

_MAKE_RESULT(-1001, ERR_OUT_OF_INTERNAL_MEMORY);

namespace test
{

a_util::result::Result GetResult()
{
    return a_util::result::Result();
}

a_util::result::Result GetResultOutOfMemory()
{
    return ERR_OUT_OF_MEMORY;
}

a_util::result::Result GetDetailedResultOutOfMemory()
{
    return a_util::result::Result(
        ERR_OUT_OF_MEMORY, "Out of memory", __LINE__, __FILE__, A_UTIL_CURRENT_FUNCTION);
}

a_util::result::Result GetResultOutOfInternalMemory()
{
    return ERR_OUT_OF_INTERNAL_MEMORY;
}

a_util::result::Result GetDetailedResultOutOfInternalMemory()
{
    return a_util::result::Result(ERR_OUT_OF_INTERNAL_MEMORY,
                                  "Out of internal memory",
                                  __LINE__,
                                  __FILE__,
                                  A_UTIL_CURRENT_FUNCTION);
}

} // namespace test
