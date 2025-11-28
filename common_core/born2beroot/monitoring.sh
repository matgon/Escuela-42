#!/bin/bash

arch_cmd=$(uname -a)
echo "#Architecture: $arch_cmd"
cpu_cmd=$(lscpu | grep "Socket(s):" | awk '{print $2}')
echo "#CPU physical : $cpu_cmd"
vcpu_cmd=$(nproc)
echo "#vCPU : $vcpu_cmd"
mem_total=$(free -m | awk '/Mem:/ {print $2}')
mem_used=$(free -m | awk '/Mem:/ {print $3}')
mem_percent=$(awk "BEGIN {printf \"%.2f\", $mem_used/$mem_total*100}")
echo "#Memory Usage: ${mem_used}/${mem_total}MB (${mem_percent} %)"
disk_used=$(df -BM / | awk 'NR==2 {gsub("M","",$3); print $3}')
disk_total=$(df -BM / | awk 'NR==2 {gsub("M","",$2); print $2}')
disk_percent=$(df -h / | awk 'NR==2 {print $5}')
echo "#Disk Usage: ${disk_used}M/${disk_total}M ($disk_percent)"
cpu_load_cmd=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')
echo "#CPU load: $cpu_load_cmd%"
last_boot_cmd=$(who -b | awk '{print $3 " " $4}')
echo "#Last boot: $last_boot_cmd"
lvm_cmd=$(lsblk | grep "lvm" >/dev/null && echo "yes" || echo "no")
echo "#LVM use: $lvm_cmd"
tcp_cmd=$(ss -t state established | tail -n +2 | wc -l)
echo "#TCP Connections : $tcp_cmd ESTABLISHED"
user_log_cmd=$(who | wc -l)
echo "#User log: $user_log_cmd"
ip_cmd=$(hostname -I | awk '{print $1}')
mac_cmd=$(ip link show | awk '/ether/ {print $2}')
echo "#Network: IP $ip_cmd ($mac_cmd)"
sudo_count_cmd=$(journalctl _COMM=sudo | grep COMMAND | wc -l 2>/dev/null)
echo "#Sudo : $sudo_count_cmd"