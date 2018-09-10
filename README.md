# zynq_study
主要学习使用PS和PL的交互方式，对于每一种交互方式，都会提供一个单独的例子.

# 软硬件环境
* ALINX7020开发板
* vivado2017.4



# 例子
- [x] [hello_world](https://github.com/kdurant/zynq_study/tree/master/hello_world)

- [x] [PS控制 MIO](https://github.com/kdurant/zynq_study/tree/master/mio)
- [x] [PS控制PL侧EMIO](https://github.com/kdurant/zynq_study/tree/master/ps_emio)
- [ ] [PS控制PL侧GPIO]()

> 注意EMIO和GPIO的区别：
>
>
>

- [x] [PS读取PL中断](https://github.com/kdurant/zynq_study/tree/master/pl_int)
- [ ] [PS和PL通过FIFO交互]()
- [ ] [PS和PL通过BRAM交互]()
- [ ] [PL读写PS侧DDR]()

- [ ] [自定义AXI4-Lite接口IP](https://github.com/kdurant/zynq_study/tree/master/user_define_ip)

# FAQ
1. 如何使用SDK 中的 Console 窗口显示串口发送的信息?
`STDIO Connection`中选择**PS配置串口**连接到的`PC串口`。
> 串口必须连上，只是不需要另外开一个串口调试助手

1. "Error while running ps7_init method"


2. AXI interface port /AXI_RD is not associated to any clock port. It may not work correctly. Please update ASSOCIATED_BUSIF parameter of a clock port to include this interface port
