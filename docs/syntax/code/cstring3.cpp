char str1[] = "This is an apple.";
char str2[] = "That is a banana.";
int res = memcmp(str1, str2, sizeof(str1));
if (res > 0)
{
    printf("'%s' is greater than '%s'.\n", str1, str2);
}
else if (res < 0)
{
    printf("'%s' is less than '%s'.\n", str1, str2);
}
else
{
    printf("'%s' is the same as '%s'.\n", str1, str2);
}

/*
'This is an apple.' is greater than 'That is a banana.'.

*/