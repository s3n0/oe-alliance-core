SUMMARY = "Hardware drivers for ${MACHINE_DRIVER}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI = "http://source.mynonpublic.com/zgemma/${MACHINE_DRIVER}-drivers-${KV}-${SRCDATE}.zip"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

inherit module

FILES:${PN} += "${sysconfdir}/modprobe.d/_${MACHINEBUILD}.conf ${sysconfdir}/modules-load.d/_${MACHINEBUILD}.conf"

do_compile() {
}
do_populate_sysroot() {
}

do_install() {
	install -d ${D}/lib/modules/${KV}/extra
	install -d ${D}/${sysconfdir}/modprobe.d
	install -m 0755 ${S}/*.ko ${D}${base_libdir}/modules/${KV}/extra
	for i in ${MACHINE_DRIVER}_1 ${MACHINE_DRIVER}_2 ${MACHINE_DRIVER}_3 ${MACHINE_DRIVER}_4; do
		echo blacklist $i >> ${D}${sysconfdir}/modprobe.d/_${MACHINEBUILD}.conf
	done
}

pkg_prerm:${PN}() {
	if [ "x$D" == "x" ]; then
		if [ -f /lib/modules/${KV}/extra/hi_play.ko ] ; then
			rm -f /lib/modules/${KV}/extra/hi_play.ko;
		fi
	fi
}

RREPLACES:${PN} = "kernel-module-hi-play-4.4.35"
RCONFLICTS:${PN} = "kernel-module-hi-play-4.4.35"