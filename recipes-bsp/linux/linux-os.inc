DESCRIPTION = "Linux kernel for ${MACHINE}"
SECTION = "kernel"
LICENSE = "GPLv2"

PACKAGE_ARCH = "${MACHINE_ARCH}"

DEPENDS += "xz-native bc-native"
DEPENDS_append_aarch64 = " libgcc"
KERNEL_CC_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"
KERNEL_LD_append_aarch64 = " ${TOOLCHAIN_OPTIONS}"

KERNEL_EXTRA_ARGS = "EXTRA_CFLAGS=-Wno-attribute-alias"

# Pick up shared functions
inherit kernel

export OS = "Linux"

S = "${WORKDIR}/linux-${PV}"
B = "${WORKDIR}/build"

KERNEL_IMAGEDEST = "tmp"

pkg_postrm_kernel-image () {
}

do_rm_work() {
}
