#include "tst.h"

char *_getenv(const char *name)
{
    int i = 0, j = 0;
    char *str;
    if (!name)
        return (NULL);
    while (environ[i])
    {
        if (name[j] == environ[i][j])
        {
            while (name[j])
            {
                if (name[j] != environ[i][j])
                    break;
                j++;
            }
            if (name[j] == '\0')
            {
                str = (environ[i] + j + 1);
                return (str);
            }
        }
        i++;
    }
    return (NULL);
}
