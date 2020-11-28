#include "stringfn.h"
#include "test.h"


void test_impl()
{
  stringfn_mut_to_lowercase(NULL);
}


int main()
{
  test_run(test_impl);
}

