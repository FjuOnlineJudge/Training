char str[] = "Ha!";
printf("Before strcpy:\n");
printf("%s\n", str);
strcat(str, " Hello!");
printf("\nAfter strcpy:\n");
printf("%s\n", str);

/*
Before strcpy:
Ha!

After strcpy:
Ha! Hello!

*/