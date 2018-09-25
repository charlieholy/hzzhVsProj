/*
 * cpu_num.c
 *
 *  Created on: 2018年9月23日
 *      Author: chenpeiwen
 */
#include <uv.h>
int main(){
	uv_cpu_info_t *info;
	int cpu_count;
	uv_cpu_info(&info,&cpu_count);
	printf("cpu count %d\n",cpu_count);
	return 0;
}
