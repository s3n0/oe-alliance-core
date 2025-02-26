SUMMARY = "Enigma2 Skin OctagonEightSD"
MAINTAINER = "Openeight"
SECTION = "base"
PRIORITY = "required"
LICENSE = "proprietary"
inherit allarch

require conf/license/license-gplv2.inc

inherit gitpkgv
SRCREV = "${AUTOREV}"
PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"
VER ="1.0"
PR = "r2"

SRC_URI="git://github.com/Openeight/OctagonEightSD.git;protocol=https"

S = "${WORKDIR}/git"

FILES:${PN} = "/usr"

do_package_qa[noexec] = "1"

do_install() {
    cp -rp ${S}/usr ${D}/
}
