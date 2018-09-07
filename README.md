# zynq_study
主要学习使用PS和PL的交互方式，对于每一种交互方式，都会提供一个单独的例子

# IO方式
* MIO
    - 只对PS部分可见，PL不可用
    - 分布在Bank0, Bank1
    - 引脚固定
    - 直接由PS操作
* EMIO
    - PS可用，但需要分配引脚。PL可用
    - 分布在Bank2，Bank3
    - 引脚由PL扩展，可直接由PS操作
* AXI_GPIO
    - PS通过M_AXI_GPIO接口控制PL非EMIO，使用时消耗管脚资源和逻辑资源

1. [PS控制 MIO]()
2. [PS控制PL侧EMIO]()
3. [PS控制PL侧GPIO]()

# AXI_GP接口
2个32位主设备接口和2个32位从设备接口

## PS通过AXI_GP_MASTER写FIFO， PL读
AXI-Stream FIFO

## PL通过AXI_GP_MASTER写FIFO， PS读

# AXI_HP接口
用于PL访问PS上的存储器（DDR，on-chip RAM）

## PL读写DDR

## PL读写on-chip RAM


# 中断方式

# DMA方式
