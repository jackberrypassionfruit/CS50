#include <assert.h>
#include <stdbool.h>
#include <string.h>

#include "ctype.h"
#include "tests.h"

void test_isalpha(void)
{
    assert(isalpha('A') == true);
    assert(isalpha('Z') == true);
    assert(isalpha('a') == true);
    assert(isalpha('z') == true);
    assert(isalpha('0') == false);
    assert(isalpha('9') == false);
    assert(isalpha('+') == false);
    assert(isalpha('/') == false);
}

void test_isdigit(void)
{
    // TODO
}

void test_isalnum(void)
{
    // TODO
}

void test_areupper(void)
{
    // TODO
}
