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
    assert(isdigit('A') == false);
    assert(isdigit('Z') == false);
    assert(isdigit('a') == false);
    assert(isdigit('z') == false);
    assert(isdigit('0') == true);
    assert(isdigit('9') == true);
    assert(isdigit('+') == false);
    assert(isdigit('/') == false);
}

void test_isalnum(void)
{
    assert(isalnum('A') == false);
    assert(isalnum('Z') == false);
    assert(isalnum('a') == false);
    assert(isalnum('z') == false);
    assert(isalnum('0') == true);
    assert(isalnum('9') == true);
    assert(isalnum('+') == false);
    assert(isalnum('/') == false);}

void test_areupper(void)
{
    // TODO
}
