/*
author          Oliver Blaser
date            07.03.2023
copyright       GNU LGPL-2.1 - Copyright (c) 2023 Oliver Blaser
*/

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>

#include <iconv/iconv.h>

#include <Windows.h>

using std::cout;
using std::endl;

namespace
{
    void clear_buffer(char* buffer, size_t count)
    {
        for (size_t i = 0; i < count; ++i) buffer[i] = 0;
    }
}



int main(int argc, char** argv)
{
    iconv_t cd; // conversion descriptor (handle in windows terminology)
    const char* inbuf;
    char* outbuf;
    size_t inbytesleft, outbytesleft;
    size_t r;

    const char in[] = "string with <auml ouml uuml micro> - <\xC3\xA4 \xC3\xB6 \xC3\xBC \xC2\xB5>"; // input string utf-8 encoded

    constexpr size_t bufferSize = sizeof(in);
    char buffer[bufferSize];

    //SetConsoleOutputCP(CP_UTF8);
    cout << "console output code page: " << GetConsoleOutputCP() << endl << endl;

    cout << "input: " << in << endl;

    cout << "\nto ASCII" << endl;
    {
        clear_buffer(buffer, bufferSize);
        inbuf = in;
        outbuf = buffer;
        inbytesleft = sizeof(in);
        outbytesleft = bufferSize;

        cd = iconv_open("ascii", "utf-8");
        r = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

        cout << "cd: " << (size_t)cd << ", result: " << (int)r << ", inbytesleft: " << inbytesleft << ", outbytesleft: " << outbytesleft << endl;
        cout << buffer << endl;

        iconv_close(cd);
    }

    cout << "\nto ASCII 2" << endl;
    {
        const char in2[] = "0123456789abcdef <#@!?>";
        static_assert(sizeof(in2) <= sizeof(in), "in2 string is too long");

        clear_buffer(buffer, bufferSize);
        inbuf = in2;
        outbuf = buffer;
        inbytesleft = sizeof(in);
        outbytesleft = bufferSize;

        cd = iconv_open("ascii", "utf-8");
        r = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

        cout << "cd: " << (size_t)cd << ", result: " << (int)r << ", inbytesleft: " << inbytesleft << ", outbytesleft: " << outbytesleft << endl;
        cout << buffer << endl;

        iconv_close(cd);
    }

    cout << "\nto CP1252" << endl;
    {
        clear_buffer(buffer, bufferSize);
        inbuf = in;
        outbuf = buffer;
        inbytesleft = sizeof(in);
        outbytesleft = bufferSize;

        cd = iconv_open("CP1252", "utf-8");
        r = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

        cout << "cd: " << (size_t)cd << ", result: " << (int)r << ", inbytesleft: " << inbytesleft << ", outbytesleft: " << outbytesleft << endl;
        cout << buffer << endl;

        iconv_close(cd);
    }

    cout << "\nto CP850" << endl;
    {
        clear_buffer(buffer, bufferSize);
        inbuf = in;
        outbuf = buffer;
        inbytesleft = sizeof(in);
        outbytesleft = bufferSize;

        cd = iconv_open("CP850", "utf-8");
        r = iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);

        cout << "cd: " << (size_t)cd << ", result: " << (int)r << ", inbytesleft: " << inbytesleft << ", outbytesleft: " << outbytesleft << endl;
        cout << buffer << endl;

        iconv_close(cd);
    }

    return 0;
}
