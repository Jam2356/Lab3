#include <UnitTest++/UnitTest++.h>
#include "/media/Общедоступные/Для ТИМПА 3/Task_1/modAlphaCipher.h"
#include "/media/Общедоступные/Для ТИМПА 3/Task_1/modAlphaCipher.cpp"
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("ПАВАБ", modAlphaCipher("ДЛЬ").encrypt("ААААА"));
    }
    TEST(LowCaseKey) {
        CHECK_EQUAL("ПАВАБ", modAlphaCipher("лти").encrypt("ААААА"));
    }
    TEST(WhitespaceInKey) {
        CHECK_THROW(modAlphaCipher key("Р Т"), cipher_error);
    }
    TEST(EmptyKey) {
        CHECK_THROW(modAlphaCipher key(""), cipher_error);
    }
}
struct KeyB_fixture {
    modAlphaCipher* p;
    KeyB_fixture()
    {
        p = new modAlphaCipher("Б");
    }
    ~KeyB_fixture()
    {
        delete p;
    }
};
SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("АПНБНЬМБСБНФ", p->encrypt("ПИТЕРДИНКЛЕЙДЖ"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("АПНБНЬМБСБНФ", p->encrypt("питердинклейдж"));
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("123444443"), cipher_error);
    }
}
SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_THROW(p -> decrypt("нПРОНЬМБСБНФ"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->decrypt(""), cipher_error);
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}

struct KeyAB_fixture {
    modAlphaCipher * pointer;
    KeyAB_fixture()
    {
        pointer = new modAlphaCipher(L"АВ");
    }
    ~KeyAB_fixture()
    {
        delete pointer;
    }
};
int main()
{
    return UnitTest::RunAllTests();
}
