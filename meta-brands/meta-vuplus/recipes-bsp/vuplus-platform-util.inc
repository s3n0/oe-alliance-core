SUMMARY = "Platform Util drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH := "${MACHINE_ARCH}"
require conf/license/license-close.inc

RDEPENDS:${PN} += "gptfdisk"

PR="${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://code.vuplus.com/download/release/platform-util/platform-util-${MACHINE}-${PV}-${SRCDATE}.${SRCDATE_PR}.tar.gz \
    file://${INITSCRIPT_NAME}.sysvinit \
"

S="${WORKDIR}/platform-util-${MACHINE}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/* ${D}${bindir}
    install -d ${D}/etc/init.d
    install -m 0755 ${WORKDIR}/${INITSCRIPT_NAME}.sysvinit ${D}/etc/init.d/${INITSCRIPT_NAME}
}

do_package_qa() {
}

FILES:${PN}="/"

inherit update-rc.d

INITSCRIPT_PARAMS = "start 65 S . stop 90 0 ."
INITSCRIPT_NAME = "vuplus-platform-util"

INSANE_SKIP:${PN} += "already-stripped"
