#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(WIN32)
#define DLLEXP __declspec(dllexport) 
#else
#define DLLEXP
#endif

#ifdef STANDARD
#include <string.h>
#include <stdlib.h>
#include <time.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#endif
#include <mysql.h>
#include <m_ctype.h>
#include <m_string.h>
#include <stdlib.h>

#include <ctype.h>

#ifdef HAVE_DLOPEN
#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __WIN__
#define SETENV(name,value)		SetEnvironmentVariable(name,value);
#else
#define SETENV(name,value)		setenv(name,value,1);		
#endif

DLLEXP 
my_bool touch_file_init(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *message
);

DLLEXP 
void touch_file_deinit(
	UDF_INIT *initid
);

DLLEXP 
my_ulonglong touch_file(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *is_null
,	char *error
);

#ifdef	__cplusplus
}
#endif

void touch_file_deinit(
	UDF_INIT *initid
){
}

my_bool touch_file_init(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *message
){
	if(args->arg_count==1
	&&	args->arg_type[0]==STRING_RESULT){
		initid->maybe_null = 1;
		return 0;
	} else {
		strcpy(
			message
		,	"Expected exactly one string type parameter"
		);		
		return 1;
	}
}
my_ulonglong touch_file(
	UDF_INIT *initid
,	UDF_ARGS *args
,	char *is_null
,	char *error
){
  FILE *fp = fopen(args->args[0], "w");

  if (fp == NULL) {
    return 1;
  }

//  if (fputs("hi", fp) < 0) {
//    return 1;
//  }

  if (fclose(fp) != 0) {
    return 1;
  }

  return 0;
}

#endif /* HAVE_DLOPEN */
