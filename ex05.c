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

	HsaSystemProperties systemProps;
	status = hsaKmtAcquireSystemProperties(&systemProps);
	thunkCheck(status, Acquiring System Properties);

	printf("Number of Nodes: %u\n", systemProps.NumNodes);
	printf("Platform OEM:    %u\n", systemProps.PlatformOem);
	printf("Platform Id:     %u\n", systemProps.PlatformId);
	printf("Platform Rev:    %u\n", systemProps.PlatformRev);

	status = hsaKmtReleaseSystemProperties();
	thunkCheck(status, Releasing System Properties);

    status = hsaKmtCloseKFD();
    thunkCheck(status, Closing Kfd);
    return 0;
}
