#ifndef THUNK_UTIL_H
#define THUNK_UTIL_H

#include<hsakmt.h>
#include<stdlib.h>

void thunk_check(HSAKMT_STATUS status, 
                 char* msg,
                 const char* file,
                 const char* func,
                 int line)
{
    if(status == HSAKMT_STATUS_SUCCESS){
		printf("%s Success\n",msg);
	}
	else{
		printf("%s Failed with %d status in file: %s in func: %s at line: %d\n", msg, status, file, func, line);
		exit(1);
	}
}

#define thunkCheck(status, msg) thunk_check(status, #msg,\
        __FILE__, __func__, __LINE__);

const char* heapType[] =
{
	"HSA_HEAPTYPE_SYSTEM",
	"HSA_HEAPTYPE_FRAME_BUFFER_PUBLIC",
	"HSA_HEAPTYPE_FRAME_BUFFER_PRIVATE",
	"HSA_HEAPTYPE_GPU_GDS",
	"HSA_HEAPTYPE_GPU_LDS",
	"HSA_HEAPTYPE_GPU_SCRATCH",
	"HSA_HEAPTYPE_DEVICE_SVM",
};

#endif
