scanf("%[abc]s", s);
printf("%s\n", s);

/*
輸入：abcdef
輸出：abc
*/

scanf("%[^abc]s", s);
printf("%s\n", s);

/*
輸入：fedcba
輸出：cba
*/
