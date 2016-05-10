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

	HsaNodeProperties nodeProps;
	HsaMemoryProperties *memProps;
	HSAuint32 nodeId;

	for(nodeId=0;nodeId<systemProps.NumNodes;nodeId++){
		status = hsaKmtGetNodeProperties(nodeId, &nodeProps);
		thunkCheck(status, Getting Node Properties);
		printf("\nNode:               %u\n", nodeId);
		printf("Number of CPUCores: %u\n", nodeProps.NumCPUCores);
		printf("Number of GPUCores: %u\n", nodeProps.NumFComputeCores);
		printf("Max CPU Freq:       %u MHz\n", nodeProps.MaxEngineClockMhzCCompute);
		printf("Max GPU Freq:       %u MHz\n", nodeProps.MaxEngineClockMhzFCompute);
		printf("Number of MemBanks: %u\n", nodeProps.NumMemoryBanks);
		printf("Number of Caches:   %u\n", nodeProps.NumCaches);
		printf("Number of IOLinks:  %u\n", nodeProps.NumIOLinks);
		printf("Max Waves per SIMD: %u\n", nodeProps.MaxWavesPerSIMD);
		printf("WaveFront Size:     %u\n", nodeProps.WaveFrontSize);
		uint32_t memBank, bank;
		memBank = nodeProps.NumMemoryBanks;
		memProps = (HsaMemoryProperties*)malloc(memBank*sizeof(HsaMemoryProperties));
		status = hsaKmtGetNodeMemoryProperties(nodeId, memBank, memProps);
		thunkCheck(status, Getting Memory Properties);
		for(bank = 0; bank < memBank; bank++){
			printf("Heap Type:          %s\n", heapType[memProps[bank].HeapType]);
			printf("Memory Clock:       %u MHz\n", memProps[bank].MemoryClockMax);
		}
	}

	status = hsaKmtReleaseSystemProperties();
	thunkCheck(status, Releasing System Properties);

    status = hsaKmtCloseKFD();
    thunkCheck(status, Closing Kfd);
    return 0;
}
