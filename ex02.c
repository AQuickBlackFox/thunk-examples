#include<stdio.h>
#include<hsakmt.h>
#include<assert.h>
#include"thunk_util.h"

int main(){
    HSAKMT_STATUS status = hsaKmtOpenKFD();
	thunkCheck(status, Opening Kfd);

	HsaVersionInfo versionInfo;
	status = hsaKmtGetVersion(&versionInfo);
	thunkCheck(status, Getting HsaKfd version);

	printf("KernelInterface Version: %u.%u\n", versionInfo.KernelInterfaceMajorVersion,
                                               versionInfo.KernelInterfaceMinorVersion); 

    status = hsaKmtCloseKFD();
    thunkCheck(status, Closing Kfd);
    return 0;
}
