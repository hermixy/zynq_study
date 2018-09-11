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
- [x] [PS和PL通过FIFO交互](https://github.com/kdurant/zynq_study/tree/master/ps_fifo_pl)
主要是考虑小批量数据通信使用此种交互方式
![pic](https://github.com/kdurant/zynq_study/blob/master/image/axi_stream_fifo.png)
* FCLK_CLK0使用100MHz时，有警告。50MHz，125MHz没有发现警告

- [ ] [PS和PL通过BRAM交互]()
- [ ] [PL读写PS侧DDR]()

> AXI-DMA：实现从PS内存到PL高速传输高速通道AXI-HP<---->AXI-Stream的转换
> AXI-FIFO-MM2S：实现从PS内存到PL通用传输通道AXI-GP<----->AXI-Stream的转换
> AXI-Datamover：实现从PS内存到PL高速传输高速通道AXI-HP<---->AXI-Stream的转换，只不过这次是完全由PL控制的，PS是完全被动的。
> AXI-VDMA：实现从PS内存到PL高速传输高速通道AXI-HP<---->AXI-Stream的转换，只不过是专门针对视频、图像等二维数据的。
> AXI-CDMA IP: 这个是由PL完成的将数据从内存的一个位置搬移到另一个位置，无需CPU来插手。这个和我们这里用的Stream没有关系

- [ ] [自定义AXI4-Lite接口IP](https://github.com/kdurant/zynq_study/tree/master/user_define_ip)

# FAQ
1. 如何使用SDK 中的 Console 窗口显示串口发送的信息?         
`STDIO Connection`中选择**PS配置串口**连接到的`PC串口`。
> 串口必须连上，只是不需要另外开一个串口调试助手

2. "Error while running ps7_init method"      
A: sdk调试


3. `AXI interface port /AXI_RD is not associated to any clock port. It may not work correctly. Please update ASSOCIATED_BUSIF parameter of a clock port to include this interface port`     
A: 修改`FCLK_CLK0`为其他时钟，目前100MHz时出现过这个警告


4. `apply_bd_automation -rule xilinx.com:bd_rule:processing_system7 -config {make_external "FIXED_IO, DDR" apply_board_preset "1" Master "Disable" Slave "Disable" }  [get_bd_cells processing_system7_0]`