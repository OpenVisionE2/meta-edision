SUMMARY = "Linux kernel for ${MACHINE}"
SECTION = "kernel"
LICENSE = "GPLv2"
PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "osmio4k|osmio4kplus"

KERNEL_RELEASE = "5.1"

inherit kernel machine_kernel_pr

SRC_URI[md5sum] = "18ee55bc50d3c96c3d70ef40902b62b2"
SRC_URI[sha256sum] = "8ffc08a31f260ecc1a637bafbe5cdb67e3d6a62554af056a7f00ff7fdbe99883"

LIC_FILES_CHKSUM = "file://${WORKDIR}/linux-brcmstb-${PV}/COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "flex-native bison-native openssl-native"

# By default, kernel.bbclass modifies package names to allow multiple kernels
# to be installed in parallel. We revert this change and rprovide the versioned
# package names instead, to allow only one kernel to be installed.
PKG_kernel-base = "kernel-base"
PKG_kernel-image = "kernel-image"
RPROVIDES_kernel-base = "kernel-${KERNEL_VERSION}"
RPROVIDES_kernel-image = "kernel-image-${KERNEL_VERSION}"

SRC_URI += "http://source.mynonpublic.com/edision/linux-edision-${PV}.tar.gz \
    file://defconfig \
    file://findkerneldevice.py \
    file://0001-Add-support-for-TBS5980-and-TBS5925.patch \
    "

S = "${WORKDIR}/linux-brcmstb-${PV}"
B = "${WORKDIR}/build"

export OS = "Linux"
KERNEL_OBJECT_SUFFIX = "ko"
KERNEL_IMAGEDEST = "tmp"

FILES_kernel-image = "${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}* ${KERNEL_IMAGEDEST}/findkerneldevice.py"

do_shared_workdir_append() {
       unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
       make CC="${KERNEL_CC}" LD="${KERNEL_LD}" AR="${KERNEL_AR}" \
                  -C ${STAGING_KERNEL_DIR} O=${STAGING_KERNEL_BUILDDIR} scripts prepare
}

kernel_do_install_append () {
    install -d ${D}/${KERNEL_IMAGEDEST}
    install -m 0644 ${KERNEL_OUTPUT_DIR}/${KERNEL_IMAGETYPE} ${D}/${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION}
    install -m 0644 ${WORKDIR}/findkerneldevice.py ${D}/${KERNEL_IMAGEDEST}
}

pkg_postinst_kernel-image () {
    if [ "x$D" == "x" ]; then
        if [ -f /${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION} ] ; then
            if grep -q 'root=/dev/mmcblk' /proc/cmdline ; then
                python /${KERNEL_IMAGEDEST}/findkerneldevice.py
                dd if=/${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE} of=/dev/kernel
            else
                flash_erase /dev/${MTD_KERNEL} 0 0
                nandwrite -p /dev/${MTD_KERNEL} /${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION}
                rm -f /${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION}
            fi
        fi
    fi
    true
}

pkg_postrm_kernel-image () {
}

do_rm_work() {
}

# extra tasks
addtask kernel_link_images after do_compile before do_install
