connect -url tcp:127.0.0.1:3121
source E:/study/fpga/zynq_study/hello_world/hello_world.sdk/cpu_wrapper_hw_platform_0/ps7_init.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent JTAG-HS1 210512180081"} -index 0
loadhw -hw E:/study/fpga/zynq_study/hello_world/hello_world.sdk/cpu_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x40000000 0xbfffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent JTAG-HS1 210512180081"} -index 0
stop
ps7_init
ps7_post_config
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent JTAG-HS1 210512180081"} -index 0
rst -processor
targets -set -nocase -filter {name =~ "ARM*#0" && jtag_cable_name =~ "Digilent JTAG-HS1 210512180081"} -index 0
dow E:/study/fpga/zynq_study/hello_world/hello_world.sdk/hello_world/Debug/hello_world.elf
configparams force-mem-access 0
bpadd -addr &main
