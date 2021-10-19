char str[] = "Cats Like Chatching The Mouses.";
for (int i = 0; i != (int)strlen(str); ++i)
{
    if (isalpha(str[i]))
    {
        str[i] = tolower(str[i]);
    }
}
printf("%s\n", str);

/*
cats like chatching the mouses.
*/