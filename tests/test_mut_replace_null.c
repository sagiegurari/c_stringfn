#include "stringfn.h"
#include "test.h"


void test_impl()
{
  stringfn_mut_replace(NULL, 's', 't');
}


int main()
{
  test_run(test_impl);
}

