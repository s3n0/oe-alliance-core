SUMMARY = "Platform Util drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"
PACKAGE_ARCH := "${MACHINE_ARCH}"
require conf/license/license-close.inc

PR="${SRCDATE}.${SRCDATE_PR}"

SRC_URI = " \
    http://source.mynonpublic.com/xtrend/platform-util-${MACHINE}-${PV}-${PR}.tar.gz \
    file://${INITSCRIPT_NAME}.sysvinit \
"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${WORKDIR}/nxserver ${D}${bindir}
    install -d ${D}/etc/init.d
    install -m 0755 ${WORKDIR}/${INITSCRIPT_NAME}.sysvinit ${D}/etc/init.d/${INITSCRIPT_NAME}
}

do_package_qa() {
}

FILES:${PN}="/"

inherit update-rc.d

INITSCRIPT_PARAMS = "start 65 S . stop 90 0 ."
INITSCRIPT_NAME = "platform-util"
