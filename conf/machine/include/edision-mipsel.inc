TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

require conf/machine/include/tune-mips32.inc

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "edision"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	edision-splash \
	firmware-dvb-demod-si2168-a20 \
	firmware-dvb-demod-si2168-a30 \
	firmware-dvb-demod-si2168-b40 \
	firmware-dvb-tuner-si2158-a20 \
	kernel-module-dvb-usb-dvbsky \
	kernel-module-dvb-usb-v2 \
	kernel-module-extrawlan-rt8723bs \
	kernel-module-hci-uart \
	kernel-module-m88ds3103 \
	kernel-module-si2157 \
	kernel-module-si2168 \
	os-dvb-modules-${MACHINE} \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

PREFERRED_PROVIDER_virtual/kernel = "linux-os"

KERNEL_IMAGETYPE = "vmlinux.gz"
KERNEL_CONSOLE = "ttyS0,115200n8"

KERNEL_MODULE_AUTOLOAD += "\
	r8723bs \
	hci_uart \
	"

MACHINE_FEATURES += "alsa switchoff osdposition hdmicec dvb-c videoenhancement HDMI linuxwifi"

require conf/machine/include/rootfs-ubi.inc

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

STB_PLATFORM = "edisionmips"
