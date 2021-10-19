char str1[] = "This is an apple.";
char str2[] = "That is a banana.";
printf("Before strcpy:\n");
printf("%s\n", str2);
strcpy(str2, str1);
printf("\nAfter strcpy:\n");
printf("%s\n", str2);

/*
Before strcpy:
That is a banana.

After strcpy:
This is an apple.

*/