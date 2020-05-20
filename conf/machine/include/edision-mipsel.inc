TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

require conf/machine/include/tune-mips32.inc

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

BOX_BRAND = "edision"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "os-dvb-modules-${MACHINE}"
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "rt8723bs"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-hci-uart"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-rt2800usb"

MACHINE_EXTRA_RRECOMMENDS += "enigma2-plugin-drivers-dvb-usb-opticombo"
MACHINE_EXTRA_RRECOMMENDS += "gstreamer1.0-plugin-dvbmediasink"
MACHINE_EXTRA_RRECOMMENDS += "edision-splash"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

PREFERRED_PROVIDER_virtual/kernel = "linux-os"

KERNEL_IMAGETYPE = "vmlinux.gz"
KERNEL_CONSOLE = "ttyS0,115200n8"

KERNEL_MODULE_AUTOLOAD += "r8723bs"
KERNEL_MODULE_AUTOLOAD += "hci_uart"

MACHINE_FEATURES += "alsa wlan 3dtv switchoff osdposition hdmicec textlcd dvb-c videoenhancement"

KERNEL_MODULE_AUTOLOAD += "xfs"

require conf/machine/include/rootfs-ubi.inc

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"
