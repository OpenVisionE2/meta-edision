DESCRIPTION = "GLES/EGL files for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

PR = "${SRCDATE}"

PROVIDES = "virtual/libgles2 virtual/egl"

SRC_URI = "http://source.mynonpublic.com/xcore/xcore-libgles-xc7346-${SRCDATE}.tar.gz"

S = "${WORKDIR}/libgles-xc7346"

do_configure() {
}

do_compile() {
}

do_install_append() {
	install -d ${D}${libdir}
	install -m 0755 ${S}/lib/libv3dplatform.so ${D}${libdir}/
	install -m 0755 ${S}/lib/libv3ddriver.so ${D}${libdir}/
	ln -s libv3ddriver.so ${D}${libdir}/libEGL.so
	ln -s libv3ddriver.so ${D}${libdir}/libGLESv2.so
	install -d ${D}/${includedir}
	install -m 0644 ${S}/include/v3dplatform.h ${D}${includedir}/
	for d in EGL GLES GLES2 KHR; do
		install -d ${D}${includedir}/$d
		for f in ${S}/include/$d/*.h; do
			install -m 0644 $f ${D}${includedir}/$d/
		done
	done
}

FILES_${PN} = "${libdir}/*"
FILES_${PN}-dev = "${incdir}/*"

RPROVIDES_${PN} = "virtual/libgles2 virtual/egl libv3dplatform.so libv3ddriver.so libGLESv2.so libEGL.so"
