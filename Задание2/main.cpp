#include <UnitTest++/UnitTest++.h>
#include "/home/stud/C++Projects/C++Project/C++Project_1/Encryptor.h"
#include "/home/stud/C++Projects/C++Project/C++Project_1/Encryptor.cpp"
SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("LLEHO",Encryptor().encrypt("HELLO",4));
    }
    TEST(PunctuationInKey) {
        CHECK_THROW(Encryptor().encrypt("HELLO", 0),cipher_error);
    }
}

struct KeyB_fixture {
    Encryptor * p;
    KeyB_fixture()
    {
        p = new Encryptor();
    }
    ~KeyB_fixture()
    {
        delete p;
    }
};

SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("LRLOEWDHOL",
                    p->encrypt("HELLOWORLD",4));
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encrypt("",4),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encrypt("1234+8765=9999",4),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("DLROWOLLEH",
                    Encryptor().encrypt("HELLOWORLD",10));
    }
}
int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}