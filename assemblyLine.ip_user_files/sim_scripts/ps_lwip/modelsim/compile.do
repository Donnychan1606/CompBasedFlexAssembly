vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_4
vlib modelsim_lib/msim/processing_system7_vip_v1_0_6
vlib modelsim_lib/msim/xil_defaultlib
vlib modelsim_lib/msim/xlconcat_v2_1_1

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_4 modelsim_lib/msim/axi_vip_v1_1_4
vmap processing_system7_vip_v1_0_6 modelsim_lib/msim/processing_system7_vip_v1_0_6
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib
vmap xlconcat_v2_1_1 modelsim_lib/msim/xlconcat_v2_1_1

vlog -work xilinx_vip -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/axi_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/clk_vip_if.sv" \
"D:/Xilinx/Vivado/2018.3/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work axi_infrastructure_v1_1_0 -64 -incr "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_4 -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/98af/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work processing_system7_vip_v1_0_6 -64 -incr -sv -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xilinx_vip "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/ps_lwip/ip/ps_lwip_processing_system7_0_0/sim/ps_lwip_processing_system7_0_0.v" \

vlog -work xlconcat_v2_1_1 -64 -incr "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/2f66/hdl/xlconcat_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/ec67/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ipshared/70cf/hdl" "+incdir+../../../../assemblyLine.srcs/sources_1/bd/ps_lwip/ip/ps_lwip_processing_system7_0_0" "+incdir+D:/Xilinx/Vivado/2018.3/data/xilinx_vip/include" \
"../../../bd/ps_lwip/ip/ps_lwip_xlconcat_0_0/sim/ps_lwip_xlconcat_0_0.v" \
"../../../bd/ps_lwip/ip/ps_lwip_xlconcat_0_1/sim/ps_lwip_xlconcat_0_1.v" \
"../../../bd/ps_lwip/sim/ps_lwip.v" \

vlog -work xil_defaultlib \
"glbl.v"

