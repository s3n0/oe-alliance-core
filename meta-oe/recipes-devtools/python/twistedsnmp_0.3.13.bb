SUMMARY = "twisted SNMP framework"
SECTION = "devel/python"
PRIORITY = "optional"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://license.txt;md5=c6f330cac7a286df5a2a7617fdda815f"

FILESEXTRAPATHS:prepend := "${THISDIR}/twistedsnmp:"

RDEPENDS:${PN} = "${PYTHON_PN}-pysnmp-se"

SRCNAME = "TwistedSNMP"
SRC_URI = "${SOURCEFORGE_MIRROR}/${BPN}/${SRCNAME}-${PV}.tar.gz \
            file://py3.patch"

S = "${WORKDIR}/${SRCNAME}-${PV}"

inherit distutils3

SRC_URI[md5sum] = "70716c4314f6c03a3da0cf57cabba03c"
SRC_URI[sha256sum] = "4e3d20110a3083bf4c602b57c5bcf447182bb0effcb8b0603f5da0314a804cce"

include ${PYTHON_PN}-package-split.inc
