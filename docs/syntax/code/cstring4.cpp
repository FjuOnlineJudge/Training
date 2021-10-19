char str[5];
printf("Before memeset:\n");
for (int i = 0; i < (int)strlen(str); ++i)
{
    printf("%c", str[i]);
}
memset(str, '+', sizeof(str));
printf("\nAfter memeset:\n");
for (int i = 0; i < (int)strlen(str); ++i)
{
    printf("%c", str[i]);
}

/*
Before memeset:

After memeset:
+++++
*/