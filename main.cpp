#include <stdint.h>
#include <stdio.h>
#include <string>

static int getLongestSso()
{
    int ret = 0;
    const int max = 2 * (int)sizeof(std::string);
    for(int i = 0; i < max; ++i)
    {
        const std::string str(i, '@');
        const uintptr_t b = (uintptr_t)&str;
        const uintptr_t e = b + sizeof(std::string);
        const uintptr_t c = (uintptr_t)str.c_str();
        if(b <= c && c < e)
            ret = i;
    }

    return ret;
}

int main()
{
#define SIZE(x) printf("sizeof(%s) = %d\n", #x, (int)sizeof(x));
    SIZE(std::string);
    SIZE(void*);
    printf("max SSO = %d\n", getLongestSso());
}
