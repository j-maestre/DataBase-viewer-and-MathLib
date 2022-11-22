#ifndef __OXML_ASSERT_H__
#define __OXML_ASSERT_H__ 1

#undef assert

#ifdef NDEBUG

#define assert(expression) ((void)0)

#else

namespace oxml {

  void _assert(
    const char *expression,
    const char *message, 
    const char *file, 
    const char *function, 
    unsigned int line
  );

  void s_assert(
    bool expression, 
    const char *message, 
    const char *file, 
    const char *function, 
    unsigned int line
  );

}

#define assert(expression, message) (void)(                                         \
				(!!(expression)) ||                                                         \
				(oxml::_assert(#expression, #message, __FILE__, __FUNCTION__, __LINE__), 0) \
)

#endif // NDEBUG

#endif