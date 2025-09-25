// define:bkcheck(HighRiskyFuncWarning)

void bad() {
     char path[] = "/usr/local/bin/gcc";
     // bad: high risk func
     char *name = basename(path);

     char *datestr = "2023-01-01 12:00:00";
     // bad: high risk func
     struct tm *tm = getdate(datestr);
	 
		char path[] = "/usr/local/bin/gcc";
     // bad: high risk func
     char *name = basename(path);

     char *datestr = "2023-01-01 12:00:00";
     // bad: high risk func
     struct tm *tm = getdate(datestr);
}