#ifndef CPU_H
#define CPU_H
/**
*  Keep the cpu busy for doing nothing (no-op)
*  so that io port will not be processed by cpu
*  here timer can also be used, but lets do this in looping counter
* @param int sleep time
*/
void sleep(u32 timer_count) {
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
  }
}
#endif