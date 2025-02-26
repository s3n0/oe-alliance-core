DESCRIPTION = "Webkit browser for HbbTV"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
require conf/license/license-close.inc

PV = "1.0"
PR = "${SRCDATE}"
SRC_URI = "http://code.vuplus.com/download/release/support/webkit-hbbtv-browser_${MACHINE}_${SRCDATE}.tar.gz"

RDEPENDS:${PN} = "webkit-gtk"

do_install:append() {
	install -d ${D}/usr/bin
	install -d ${D}/usr/lib/mozilla/plugins
	install -d ${D}/home/root

	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/none.html ${D}/home/root
	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/browser ${D}/usr/bin
	install -m 0755 ${WORKDIR}/webkit-hbbtv-browser/libhbbtvplugin.so ${D}/usr/lib/mozilla/plugins/
}

do_package_qa() {
}

PROVIDES += "webkit-hbbtv-browser"
RPROVIDES:${PN} += "webkit-hbbtv-browser"

PACKAGE_ARCH := "${MACHINE_ARCH}"

FILES:${PN} = "/"

INSANE_SKIP:${PN} = "already-stripped"
