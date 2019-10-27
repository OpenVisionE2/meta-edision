CHIPSET = "bcm72604"

require conf/machine/include/brahma-b53.inc
require conf/machine/include/build-extras.inc

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    edision-dvb-modules-${MACHINE} \
    edision-resizerootfs \
    wlan-qcacld-20 \
    firmware-qca6174 \
    wireless-regdb-static \
"

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-cdfs"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-hci-uart"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-btqca"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "kernel-module-rt2800usb"

MACHINE_EXTRA_RRECOMMENDS += "enigma2-plugin-drivers-dvb-usb-opticombo"
MACHINE_EXTRA_RRECOMMENDS += "gst-plugin-dvbmediasink"
MACHINE_EXTRA_RRECOMMENDS += "edision-splash"

DVBMEDIASINK_CONFIG = "--with-wma --with-pcm --with-dtsdownmix --with-eac3 --with-h265 --with-vb9"

PREFERRED_VERSION_wireless-regdb = "2018.10.24"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "edision-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "edision-blindscan-utils-${MACHINE}"

PREFERRED_PROVIDER_virtual/kernel = "linux-edision"
PREFERRED_VERSION_linux-edision = "5.3"

PREFERRED_PROVIDER_virtual/egl = "libv3d-${MACHINE}"
PREFERRED_PROVIDER_virtual/libgles2 = "libv3d-${MACHINE}"

MTD_BOOTFS = "mmcblk1p1"
MTD_BLACK  = "mmcblk1"
MTD_KERNEL = "mmcblk1p2"
MTD_ROOTFS = "mmcblk1p3"
KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.tar.bz2"

KERNEL_IMAGETYPE = "Image.gz"
KERNEL_CONSOLE = "ttyS0,115200n8"

KERNEL_MODULE_AUTOLOAD += "wlan"
KERNEL_MODULE_AUTOLOAD += "hci_uart"

MACHINE_FEATURES += "dvb-c blindscan-tbs blindscan-dvbs blindscan-dvbc satip mountboot videoenhancement"

require conf/machine/include/autoload-filesystems.inc
require conf/machine/include/rootfs-emmc.inc
