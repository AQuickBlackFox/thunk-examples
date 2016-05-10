#include<stdio.h>
#include<hsakmt.h>
#include<assert.h>
#include"thunk_util.h"

int main(){
    HSAKMT_STATUS status = hsaKmtOpenKFD();
	thunkCheck(status, Opening Kfd);
    status = hsaKmtCloseKFD();
    thunkCheck(status, Closing Kfd);
    return 0;
}
