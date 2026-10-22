char* countAndSay(int n)
{
    char *s = (char *)malloc(10000 * sizeof(char));
    char *temp = (char *)malloc(10000 * sizeof(char));

    strcpy(s, "1");

    for (int i = 1; i < n; i++)
      {
        int j = 0, k = 0;

        while (s[j] != '\0') {
            char digit = s[j];
            int count = 0;

            while (s[j] == digit)
              {
                count++;
                j++;
            }

            temp[k++] = count + '0';
            temp[k++] = digit;
        }

        temp[k] = '\0';
        strcpy(s, temp);
    }

    free(temp);
    return s;
}
