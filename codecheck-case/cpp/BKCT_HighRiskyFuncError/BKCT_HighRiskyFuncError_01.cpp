// define:bkcheck(HighRiskyFuncError)

void bad() {
     char str[100];
     // bad: high risk func
     gets(str);

     char src[] = "Hello, world!";
     char dest[10];
     // bad: high risk func
     strcpy(dest, src);
	 
	 char str[100];
     // bad: high risk func
     gets(str);

     char src[] = "Hello, world!";
     char dest[10];
     // bad: high risk func
     strcpy(dest, src);
}

void good() {
    char str[100];
    // good
    fgets(str);
}