onbreak {quit -f}
onerror {quit -f}

vsim -voptargs="+acc" -t 1ps -L xilinx_vip -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_4 -L processing_system7_vip_v1_0_6 -L xil_defaultlib -L xlconcat_v2_1_1 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -lib xil_defaultlib xil_defaultlib.ps_lwip xil_defaultlib.glbl

do {wave.do}

view wave
view structure
view signals

do {ps_lwip.udo}

run -all

quit -force
