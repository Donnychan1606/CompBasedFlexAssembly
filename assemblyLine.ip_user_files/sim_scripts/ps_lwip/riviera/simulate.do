onbreak {quit -force}
onerror {quit -force}

asim -t 1ps +access +r +m+ps_lwip -L xilinx_vip -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xil_defaultlib -L xlconcat_v2_1_1 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -O5 xil_defaultlib.ps_lwip xil_defaultlib.glbl

do {wave.do}

view wave
view structure

do {ps_lwip.udo}

run -all

endsim

quit -force
