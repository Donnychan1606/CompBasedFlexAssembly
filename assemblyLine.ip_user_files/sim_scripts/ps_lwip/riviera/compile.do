vlib work
vlib riviera

vlib riviera/xilinx_vip
vlib riviera/axi_infrastructure_v1_1_0
vlib riviera/axi_vip_v1_1_4
vlib riviera/processing_system7_vip_v1_0_6
vlib riviera/xil_defaultlib
vlib riviera/xlconcat_v2_1_1

vmap xilinx_vip riviera/xilinx_vip
vmap axi_infrastructure_v1_1_0 riviera/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_4 riviera/axi_vip_v1_1_4
vmap processing_system7_vip_v1_0_6 riviera/processing_system7_vip_v1_0_6
vmap xil_defaultlib riviera/xil_defaultlib
vmap xlconcat_v2_1_1 riviera/xlconcat_v2_1_1

vlog -work xilinx_vip  -sv2k12 "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work axi_infrastructure_v1_1_0  -v2k5 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_4  -sv2k12 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_6  -sv2k12 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/ps_lwip/ip/ps_lwip_processing_system7_0_0/sim/ps_lwip_processing_system7_0_0.v" \

vlog -work xlconcat_v2_1_1  -v2k5 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/2f66/hdl/xlconcat_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib  -v2k5 "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/ps_lwip/ip/ps_lwip_xlconcat_0_0/sim/ps_lwip_xlconcat_0_0.v" \
"../../../bd/ps_lwip/ip/ps_lwip_xlconcat_0_1/sim/ps_lwip_xlconcat_0_1.v" \
"../../../bd/ps_lwip/sim/ps_lwip.v" \

vlog -work xil_defaultlib \
"glbl.v"

